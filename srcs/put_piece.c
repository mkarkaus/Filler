/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:37:33 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/24 17:04:44 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**remove_excess_downright(t_input *in)
{

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
	printf("%s\n%s\n", new[0], new[1]);
	in->pcol -= in->lft_trim;
	in->prow -= in->top_trim;
	// printf("SAUNASORSA\n");
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
	return (remove_excess(in));
}

void	put_piece(t_input *in)
{
	in->pc = trim_token(in);
}
