/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:17:43 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 11:28:10 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int grid[9][9], int size)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < size - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
