/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:29:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/27 16:51:30 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_input in;
	int		lower_pl_checked;

	get_player_number(&in);
	lower_pl_checked = 0;
	while (1)
	{
		get_data(&in);
		if (lower_pl_checked == 0)
		{
			opponent_islower(&in);
			lower_pl_checked = 1;
		}
		create_heatmap(&in);
		if (put_piece(&in) == 0 && write(2, "No valid moves left.\n", 21))
			break ;
		free_arrays((void **)in.heat, in.mrow);
		free_arrays((void **)in.map, in.mrow);
		free_arrays((void **)in.pc, in.prow);
		ft_putnbr(in.y_ans);
		write(1, " ", 1);
		ft_putnbr(in.x_ans);
		write(1, "\n", 1);
	}
	return (0);
}
