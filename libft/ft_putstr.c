/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:39:02 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/07 13:22:42 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	return (i);
}