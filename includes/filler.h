/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:42:58 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/20 18:57:33 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_input {
	char			**map;
	char			**pc;
	unsigned char	pl_c;
	int				mrow;
	int				mcol;
	int				prow;
	int				pcol;
}			t_input;

void	get_data(t_input *in);
int		get_player_number(t_input *in);

#endif