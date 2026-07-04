/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 09:54:47 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/04 11:05:57 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(void);
int		parse_input(char *str, int views[16]);

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	views[16];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], views))
	{
		print_error();
		return (1);
	}
	return (0);
}
