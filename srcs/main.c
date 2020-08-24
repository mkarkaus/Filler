/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:29:36 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/24 16:38:07 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main()
{
	t_input in;

	get_player_number(&in);
	// while (1)
	// {
		get_data(&in);
		in.heat = create_heatmap(&in);
		put_piece(&in);
		// ft_print_intarr(in.heat, in.mrow, in.mcol);
	// }
	return (0);
}
