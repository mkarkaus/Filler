/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:31:18 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/25 12:32:17 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	remove_excess_downright(t_input *in, char **new)
{
	int		y;
	int		k;
	int		r_trim;

	k = 0;
	while (k < in->prow && ft_strchr(new[k], '*'))
		k++;
	y = k - 1;
	while (++y < in->prow)
		free(new[y]);
	in->prow -= y - k;
	y = -1;
	r_trim = in->pcol;
	while (++y < in->prow)
	{
		k = in->pcol - 1;
		while (new[y][k] != '*')
			k--;
		if (r_trim > in->pcol - (k + 1))
			r_trim = in->pcol - (k + 1);
	}
	in->pcol -= r_trim;
	y = -1;
	while (++y < in->prow)
		new[y] = ft_strcut(new[y], r_trim, 1, 1);
}

char	**remove_excess_upleft(t_input *in)
{
	char	**new;
	int		k;

	k = -1;
	new = (char **)malloc((in->prow + 1) * sizeof(char *));
	while (++k < in->prow - in->top_trim)
		new[k] = ft_strsub(in->pc[in->top_trim + k], in->lft_trim, \
			in->pcol - in->lft_trim);
	in->pcol -= in->lft_trim;
	in->prow -= in->top_trim;
	remove_excess_downright(in, new);
	return (new);
}

char	**trim_token(t_input *in)
{
	int		y;
	int		x;
	int		top_trim_end;

	in->lft_trim = ft_strlen(in->pc[0]);
	top_trim_end = 0;
	y = -1;
	while (++y < in->prow)
	{
		x = 0;
		while (x < in->pcol && in->pc[y][x] == '.')
			x++;
		if (in->pc[y][x] == '*' && x < in->lft_trim)
		{
			in->lft_trim = x;
			top_trim_end = 1;
		}
		else if (x == in->pcol && !top_trim_end)
			in->top_trim++;
	}
	return (remove_excess_upleft(in));
}