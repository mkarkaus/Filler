/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:29:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/26 16:47:11 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>//REMOVE

int		main()
{
	t_input in;
	int		lower_pl_checked;
	// int		fd;
	// char	*temp;

	// fd = open("foo.txt", O_RDWR | O_APPEND);
	get_player_number(&in);
	lower_pl_checked = 0;
	while (1)
	{
		// printf("8 2\n");
		get_data(&in);
		// write(fd, "SOTASORSA\n", 10);
		// write(fd, "\n", 1);
		if (lower_pl_checked == 0)
		{
			opponent_islower(&in);
			lower_pl_checked = 1;
		}
		// printf("<> %d <>\n", in.op_lower);
		in.heat = create_heatmap(&in);
		// ft_print_intarr(in.heat, 24, 40);
		put_piece(&in);
		// free_arrays((void **)in.heat, in.mrow);
		// free_arrays((void **)in.map, in.mrow);
		// free_arrays((void **)in.pc, in.prow);

		ft_putnbr(in.y_ans);
		write(1, " ", 1);
		ft_putnbr(in.x_ans);
		write(1, "\n", 1);
	}
	return (0);
}
