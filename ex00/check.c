/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:49:32 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 15:22:38 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int line[4])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_row(int grid[4][4], int row, int left, int right)
{
	return (1);
}

int	check_col(int grid[4][4], int col, int top, int bottom)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line) != top)
		return (0);
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line) != bottom)
		return (0);
	return (1);
}

int	check_all_views(int grid[4][4], int views[16])
{
	return (1);
}