/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:47:44 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:04:44 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s[i] != c && s[i])
		words++;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			words++;
		i++;
	}
	return (words);
}

static int	ft_count_symbols(char const *s, char c)
{
	int		counter;

	counter = 0;
	while (*s != c && *s)
	{
		counter++;
		s++;
	}
	return (counter);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*str;
	int		i;
	int		words_count;

	if (!s)
		return (NULL);
	i = 0;
	words_count = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (i < words_count && *s)
	{
		if (*s != c)
		{
			str = ft_strsub(s, 0, ft_count_symbols(s, c));
			res[i] = str;
			s = s + ft_count_symbols(s, c);
			i++;
		}
		s++;
	}
	res[i] = NULL;
	return (res);
}
