/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:45:08 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/09/08 12:16:00 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_surr(t_input *in, int y, int x, int num)
{
	return ((y > 0 && x > 0 && in->heat[y - 1][x - 1] == num - 1) \
	|| (y > 0 && in->heat[y - 1][x] == num - 1) \
	|| (y > 0 && x < in->mcol - 1 && in->heat[y - 1][x + 1] == num - 1) \
	|| (x < in->mcol - 1 && in->heat[y][x + 1] == num - 1) \
	|| (y < in->mrow - 1 && x < in->mcol - 1 && \
		in->heat[y + 1][x + 1] == num - 1) \
	|| (y < in->mrow - 1 && in->heat[y + 1][x] == num - 1) \
	|| (y < in->mrow - 1 && x > 0 && in->heat[y + 1][x - 1] == num - 1) \
	|| (x > 0 && in->heat[y][x - 1] == num - 1));
}

int		empty_spots_left(int **i_arr, int row_max, int col_max)
{
	int x;
	int	y;

	y = -1;
	while (++y < row_max)
	{
		x = -1;
		while (++x < col_max)
		{
			if (i_arr[y][x] == -1)
				return (1);
		}
	}
	return (0);
}

void	fill_heatmap(t_input *in, int num)
{
	int		x;
	int		y;

	y = -1;
	while (++y < in->mrow)
	{
		x = -1;
		while (++x < in->mcol)
		{
			if (in->heat[y][x] == -1 && check_surr(in, y, x, num))
				in->heat[y][x] = num;
		}
	}
}

void	start_heatmap(t_input *in)
{
	int		x;
	int		y;

	y = -1;
	while (++y < in->mrow)
	{
		x = -1;
		while (++x < in->mcol)
		{
			if (in->map[y][x] == in->op_c || in->map[y][x] == in->op_c + 32)
				in->heat[y][x] = 0;
			else
				in->heat[y][x] = -1;
		}
	}
}

void	create_heatmap(t_input *in)
{
	int		num;
	int		i;

	num = 1;
	i = -1;
	in->heat = (int **)malloc((in->mrow + 1) * sizeof(int *));
	while (++i < in->mrow)
		in->heat[i] = (int *)malloc((in->mcol + 1) * sizeof(int));
	start_heatmap(in);
	while (empty_spots_left(in->heat, in->mrow, in->mcol))
	{
		fill_heatmap(in, num);
		num++;
	}
}
