/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:14:56 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/20 19:18:51 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_player_number(t_input *in)
{
	char	*temp;
	char	*ptr;
	int		pl_num;

	get_next_line(0, &temp);
	ptr = ft_strchr(temp, 'p');
	pl_num = ft_atoi(ptr + 1);
	free(temp);
	if (pl_num != 1 && pl_num != 2)
	{
		printf("Invalid player number.\n");
		return (-1);
	}
	else
	{
		if (pl_num == 1)
			in->pl_c = 'O';
		else
			in->pl_c = 'X';
	}
	return (0);
}

void	init_struct(t_input *in)
{
	in->mrow = 0;
	in->mcol = 0;
	in->prow = 0;
	in->pcol = 0;
}

void	get_dimensions(t_input *in, char c)
{
	char	*temp;
	char	*ptr;

	get_next_line(0, &temp);
	ptr = ft_strchr(temp, ' ');
	if (c == 'm')
		in->mrow = ft_atoi(ptr + 1);
	else
		in->prow = ft_atoi(ptr + 1);
	ptr++;
	while (ft_isdigit(*ptr))
		ptr++;
	if (c == 'm')
	{
		in->mcol = ft_atoi(ptr + 1);
		free(temp);
		get_next_line(0, &temp);
	}
	else
		in->pcol = ft_atoi(ptr + 1);
	free(temp);
}

char	**get_arrays(int row)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc((row + 1) * sizeof(char *));
	while (i < row)
	{
		get_next_line(0, &arr[i]);
		i++;
	}
	return (arr);
}

void	get_data(t_input *in)
{
	int		i;

	i = 0;
	init_struct(in);
	get_dimensions(in, 'm');
	in->map = get_arrays(in->mrow);
	while (i < in->mrow)
	{
		in->map[i] = ft_strcut(in->map[i], 4, 0, 1);
		i++;
	}
	get_dimensions(in, 'p');
	in->pc = get_arrays(in->prow);
	// for (int k = 0; in->map[k]; k++)
	// 	printf("%s\n", in->map[k]);
	// for (int k = 0; in->pc[k]; k++)
	// 	printf("%s\n", in->pc[k]);
	
	// printf("¤¤ map dimensions: %d %d ¤¤\n", in->mrow, in->mcol);
	// printf("¤¤ piece dimensions: %d %d ¤¤\n", in->prow, in->pcol);
}
