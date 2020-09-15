/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:29:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/09/14 15:04:17 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_input in;
	int		lower_pl_checked;
	int		ret;

	get_player_number(&in);
	lower_pl_checked = 0;
	while (1)
	{
		ret = get_data(&in);
		if (ret == -1 && write(2, "Invalid map.\n", 13))
			break;
		else if (ret == -2 && write(2, "Invalid piece.\n", 15))
			break;
		if (lower_pl_checked == 0 && !opponent_islower(&in))
			lower_pl_checked = 1;
		create_heatmap(&in);
		if (put_piece(&in) == 0 && write(2, "No valid moves left.\n", 21))
			break ;
		ft_free_arrays((void **)in.heat, in.mrow);
		ft_free_arrays((void **)in.map, in.mrow);
		ft_free_arrays((void **)in.pc, in.prow);
		ft_putnbr(in.y_ans);
		write(1, " ", 1);
		ft_putnbr(in.x_ans);
		write(1, "\n", 1);
	}
	return (0);
}
