/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:19:09 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 18:47:32 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *temp;

	temp = (char *)malloc(size);
	if (temp == NULL || size == 0)
		return (NULL);
	ft_bzero(temp, size);
	return ((void *)temp);
}
