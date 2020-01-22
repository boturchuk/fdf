/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:55:04 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 18:58:54 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = str1;
	while (*str1 != '\0' && *str1 != '\n')
		str1++;
	i = 0;
	while (i < n && str2[i])
	{
		*str1 = str2[i];
		str1++;
		i++;
	}
	*str1 = '\0';
	return (tmp);
}
