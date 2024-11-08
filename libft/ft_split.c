/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:48:45 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 15:48:48 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_word(const char **s, char c)
{
	const char	*start;
	size_t		len;

	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	return (strndup(start, len));
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		i;
	int		num_words;

	i = 0;
	num_words = count_words(s, c);
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!s || !words)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words[i] = get_word(&s, c);
			if (!words[i++])
				return (NULL);
		}
	}
	words[i] = NULL;
	return (words);
}
