/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:00:09 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/20 13:12:37 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int msg)
{
	char	**txt;

	txt = (char**)malloc(sizeof(char*) * 5);
	txt[0] = "Oops.. Here Is An Error";
	ft_putstr(txt[msg]);
	ft_putchar('\n');
	exit(0);
}
