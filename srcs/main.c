/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:29:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/25 17:18:28 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main()
{
	t_input in;

	get_player_number(&in);
	while (1)
	{
		get_data(&in);
		in.heat = create_heatmap(&in);
		put_piece(&in);
		free_arrays((void **)in.heat, in.mrow);
		free_arrays((void **)in.map, in.mrow);
		free_arrays((void **)in.pc, in.prow);
		printf("%d %d\n", in.y_ans, in.x_ans);
	}
	return (0);
}
