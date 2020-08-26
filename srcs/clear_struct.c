/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:02:01 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/26 12:02:12 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_struct(t_input *in)
{
	in->lft_trim = 0;
	in->top_trim = 0;
	in->y_ans = 0;
	in->x_ans = 0;
	in->mrow = 0;
	in->mcol = 0;
	in->prow = 0;
	in->pcol = 0;
}

void	free_arrays(void **ptr, int rows)
{
	int		i;

	i = -1;
	while (++i < rows)
		free(ptr[i]);
	free(ptr);
}
