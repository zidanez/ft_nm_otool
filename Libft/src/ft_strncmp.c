/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:36:46 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:02:39 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (int)n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
