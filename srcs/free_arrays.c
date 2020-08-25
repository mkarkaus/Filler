/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:00:53 by mkarkaus          #+#    #+#             */
/*   Updated: 2020/08/25 17:15:00 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_arrays(void **ptr, int rows)
{
	int		i;

	i = -1;
	while (++i < rows)
		free(ptr[i]);
	free(ptr);
}