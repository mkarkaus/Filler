/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:42:58 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/26 17:21:37 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_input {
	int				**heat;
	char			**map;
	char			**pc;
	unsigned char	pl_c;
	unsigned char	op_c;
	int				op_lower;
	int				lft_trim;
	int				top_trim;
	int				mrow;
	int				mcol;
	int				prow;
	int				pcol;
	int				y_ans;
	int				x_ans;
}			t_input;

int		opponent_islower(t_input *in);
void	init_struct(t_input *in);
void    ft_print_intarr(int **arr, int maxr, int maxc, FILE *fd);//REMOVE
void	free_arrays(void **ptr, int rows);
char	**trim_token(t_input *in);
void	put_piece(t_input *in);
void	get_data(t_input *in);
int		get_player_number(t_input *in);
int		**create_heatmap(t_input *in);

#endif