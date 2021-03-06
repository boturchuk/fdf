/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:49:45 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 18:45:07 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') ||
			(i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}
