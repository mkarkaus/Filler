/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:37:33 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/25 17:04:43 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_my_char(char c, char my_pl)
{
	return (c == my_pl || c == my_pl + 32);
}

int		is_valid(t_input *in, int y, int x)
{
	int		ret;
	int		plc_found;
	int		py;
	int		px;

	ret = 0;
	py = -1;
	plc_found = 0;
	while (++py < in->prow)
	{
		px = -1;
		while (++px < in->pcol)
		{
			if (in->pc[py][px] == '*' && (in->heat[y + py][x + px] == '0' || \
			(plc_found == 1 && is_my_char(in->map[y + py][x + px], in->pl_c))))
				return (0);
			else if (in->pc[py][px] == '*')
			{
				if (is_my_char(in->map[y + py][x + px], in->pl_c))
					plc_found = 1;
				else
					ret += in->heat[y + py][x + px];
			}
		}
	}
	if (plc_found == 0)
		return (0);
	return (ret);
}

void	find_optimal_move(t_input *in)
{
	int		y;
	int		x;
	int		temp;
	int		ans_sum;

	ans_sum = 2147483646;
	y = -1;
	temp = 0;
	while (++y < in->mrow - in->prow + 1)
	{
		x = -1;
		while (++x < in->mcol - in->pcol + 1)
		{
			temp = is_valid(in, y, x);
			if (temp != 0 && temp < ans_sum)
			{
				ans_sum = temp;
				in->y_ans = y;
				in->x_ans = x;
			}
		}
	}
	in->y_ans -= in->top_trim;
	in->x_ans -= in->lft_trim;
}

void	put_piece(t_input *in)
{
	in->pc = trim_token(in);
	find_optimal_move(in);
}
