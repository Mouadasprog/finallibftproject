/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:54 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 15:51:57 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0 && base == 10)
		count++;
	while (n != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ft_itoa(int n, int base)
{
	char			*res;
	const char		*digits = "0123456789ABCDEF";
	int				len;
	unsigned int	num;

	if (base < 2 || base > 16)
		return (NULL);
	len = get_digit_count(n, base);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n < 0 && base == 10)
		num = -n;
	else
		num = n;
	while (len >= 0)
	{
		res[len] = digits[num % base];
		num /= base;
		len--;
	}
	if (n < 0 && base == 10)
		res[0] = '-';
	return (res);
}
