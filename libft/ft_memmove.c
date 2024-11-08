/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:44:56 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 15:44:59 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	if (!src || !dest)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 < src1)
		while (n--)
			*dest1++ = *src1++;
	else
	{
		dest1 += n;
		src1 += n;
		while (n--)
			*--dest1 = *--src1;
	}
	return (dest);
}
