/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:13:59 by tyou              #+#    #+#             */
/*   Updated: 2021/04/24 16:04:12 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flip(char *s)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = 0;
	if (s == NULL)
		return (0);
	while (s[size])
		size++;
	size--;
	while (i < size / 2)
	{
		tmp = s[i];
		s[i] = s[size - i];
		s[size - i] = tmp;
		i++;
	}
	return (s);
}
