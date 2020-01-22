/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:47:01 by mboturch          #+#    #+#             */
/*   Updated: 2019/11/05 18:42:51 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	int sign;
	int res;
	int i;

	res = 0;
	i = 0;
	while ((s[i] > 8 && s[i] < 20) || s[i] == ' ')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
		res = res * 10 + (s[i++] - '0');
	return (res * sign);
}