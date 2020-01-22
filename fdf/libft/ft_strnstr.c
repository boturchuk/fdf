/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:17:48 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 18:59:59 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		n = i;
		while (haystack[n] == needle[j] && n < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}
