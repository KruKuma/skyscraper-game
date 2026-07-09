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
			if (solve(grid, views, pos + 1, size))
				return (1);
			grid[row][col] = 0;
		}
		nb++;
	}
	return (0);
}
