/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:52:14 by fnancy            #+#    #+#             */
/*   Updated: 2021/04/24 14:41:24 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	ft_error(char *filename, char *msg, int errnum)
{
	write(2, "./ft_nm: ", 9);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (errnum);
}

t_symbol	*sort_symbols(t_symbol *symbols, uint32_t size)
{
	int			ret;
	uint32_t	i;
	uint32_t	j;
	t_symbol	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			ret = ft_strcmp(symbols[i].name, symbols[j].name);
			if (ret > 0 || (ret == 0 && symbols[i].value > symbols[j].value))
			{
				tmp = symbols[i];
				symbols[i] = symbols[j];
				symbols[j] = tmp;
			}
			++j;
		}
		++i;
	}
	return (symbols);
}

uint32_t	swap_uint32(uint32_t n)
{
	n = ((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF);
	return ((n << 16) | (n >> 16));
}

uint64_t	swap_uint64(uint64_t n)
{
	n = ((n << 8) & 0xFF00FF00FF00FF00ULL) \
		| ((n >> 8) & 0x00FF00FF00FF00FFULL);
	n = ((n << 16) & 0xFFFF0000FFFF0000ULL) \
		| ((n >> 16) & 0x0000FFFF0000FFFFULL);
	return ((n << 32) | (n >> 32));
}
