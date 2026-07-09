/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:51:05 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 15:39:41 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_all_views(int grid[9][9], int views[36], int size);
int	check_row(int grid[9][9], int row, int left, int right, int size);
int	check_col(int grid[9][9], int col, int top, int bottom, int size);

int	is_row_complete(int grid[9][9], int size, int row)
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (grid[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	is_col_complete(int grid[9][9], int size, int col)
{
	int	row;

	row = 0;
	while (row < size)
	{
		if (grid[row][col] == 0)
			return (0);
		row++;
	}
	return (1);
}

int	is_still_valid(int grid[9][9], int views[36], int size, int row, int col)
{
	if (is_row_complete(grid, size, row))
	{
		if (!check_row(grid, row, views[row + size * 2],
				views[row + size * 3], size))
			return (0);
	}
	if (is_col_complete(grid, size, col))
	{
		if (!check_col(grid, col, views[col], views[col + size], size))
			return (0);
	}
	return (1);
}

int	is_valid_number(int grid[9][9], int size, int row, int col, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[row][i] == nb)
			return (0);
		if (grid[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[9][9], int views[36], int pos, int size)
{
	int	row;
	int	col;
	int	nb;

	if (pos == size * size)
		return (check_all_views(grid, views, size));
	row = pos / size;
	col = pos % size;
	nb = 1;
	while (nb <= size)
	{
		if (is_valid_number(grid, size, row, col, nb))
		{
			grid[row][col] = nb;
			if (is_still_valid(grid, views, size, row, col))
			{
				if (solve(grid, views, pos + 1, size))
					return (1);
			}
			grid[row][col] = 0;
		}
		nb++;
	}
	return (0);
}
