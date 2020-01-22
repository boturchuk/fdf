/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:04:49 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 19:01:04 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(char const *s)
{
	char const *p;

	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	p = s;
	while (*s != '\0')
		s++;
	if (p != s)
		s--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	return ((s - p) + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	str = ft_strsub(s, 0, length(s));
	return (str);
}
