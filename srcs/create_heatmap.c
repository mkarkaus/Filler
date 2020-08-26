/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:45:08 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/26 17:24:03 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void    ft_print_intarr(int **arr, int maxr, int maxc, FILE *fd)
{
    int i;
    int    j;

    i = -1;
    while(++i < maxr)
    {
        j = 0;
        while(j < maxc)
        {
            fprintf(fd, "%3i", arr[i][j]);
            j++;
        }
        fprintf(fd, "\n");
    }
}

int		check_surr(t_input *in, int **i_arr, int y, int x)
{
	int		nbr;
	int		temp;

	nbr = -1;
	temp = -1;
	(y > 0 && x > 0 && (temp = i_arr[y - 1][x - 1]) != -1 && \
			(nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(y > 0 && (temp = i_arr[y - 1][x]) != -1 && (nbr == -1 || temp < nbr)) ?\
		nbr = temp: 0;
	(y > 0 && x < in->mcol - 1 && (temp = i_arr[y - 1][x + 1]) != -1 && \
			(nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(x < in->mcol - 1 && (temp = i_arr[y][x + 1]) != -1 && \
			(nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(y < in->mrow - 1 && x < in->mcol - 1 && (temp = i_arr[y + 1][x + 1]) \
			!= -1 && (nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(y < in->mrow - 1 && (temp = i_arr[y + 1][x]) != -1 && \
			(nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(y < in->mrow - 1 && x > 0 && (temp = i_arr[y + 1][x - 1]) != -1 && \
			(nbr == -1 || temp < nbr)) ? nbr = temp: 0;
	(x > 0 && (temp = i_arr[y][x - 1]) != -1 && (nbr == -1 || temp < nbr)) ? \
		nbr = temp: 0;
	return (nbr);
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

void	fill_heatmap(t_input *in, int **i_arr, int row_max, int col_max)
{
	int		x;
	int		y;
	int		nbr;

	y = -1;
	nbr = -1;
	while (++y < row_max)
	{
		x = -1;
		while (++x < col_max)
		{
			if (i_arr[y][x] == -1 && (nbr = check_surr(in, i_arr, y, x)) != -1)
				i_arr[y][x] = nbr + 1;
		}
	}
}

void	start_heatmap(t_input *in, int **i_arr)
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
				i_arr[y][x] = 0;
			else
				i_arr[y][x] = -1;
		}
	}
}

int		**create_heatmap(t_input *in)
{
	int		**i_arr;
	int		i;
	FILE	*fd;//REMOVE

	fd = fopen("foo.txt", "w+");//REMOVE
	// write(fd, "\n", 1);
	i = -1;
	i_arr = (int **)malloc((in->mrow + 1) * sizeof(int *));
	while (++i < in->mrow)
		i_arr[i] = (int *)malloc((in->mcol + 1) * sizeof(int));
	start_heatmap(in, i_arr);
	while (empty_spots_left(i_arr, in->mrow, in->mcol))
		fill_heatmap(in, i_arr, in->mrow, in->mcol);
	ft_print_intarr(i_arr, in->mrow, in->mcol, fd);//REMOVE
	fclose(fd);
	return (i_arr);
}
