/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:41:26 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 15:54:10 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	results;
	int					sign;

	i = 0;
	results = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		results = results * 10 + (str[i] - '0');
		i++;
	}
	return (results * sign);
}
