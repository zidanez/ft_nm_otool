/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:34:41 by fnancy            #+#    #+#             */
/*   Updated: 2021/04/24 14:47:40 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	print_sections_symbols(t_symbol symbol, size_t len)
{
	if (symbol.type == N_ABS || symbol.type == N_SECT || symbol.type == N_INDR)
		print_unsigned(symbol.value, 16, len);
	if (symbol.type == N_ABS)
		write(1, symbol.ext ? " A " : " a ", 3);
	else if (symbol.type == N_INDR)
		write(1, symbol.ext ? " I " : " i ", 3);
	else if (symbol.type == N_SECT)
	{
		if (symbol.sect == sections()->bss)
			write(1, symbol.ext ? " B " : " b ", 3);
		else if (symbol.sect == sections()->data)
			write(1, symbol.ext ? " D " : " d ", 3);
		else if (symbol.sect == sections()->text)
			write(1, symbol.ext ? " T " : " t ", 3);
		else
			write(1, symbol.ext ? " S " : " s ", 3);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	print_symbols(t_symbol symbol, size_t len)
{
	if (!ft_strcmp(symbol.name, ""))
		return ;
	if ((symbol.type == N_UNDF) && symbol.ext)
		write(1, "                ", len);
	if (symbol.type == N_UNDF && symbol.ext)
		write(1, symbol.ext ? " U " : " U ", 3);
	else if (print_sections_symbols(symbol, len) == EXIT_FAILURE)
		return ;
	write(1, symbol.name, ft_strlen(symbol.name));
	write(1, "\n", 1);
}

void	print_unsigned(size_t addr, size_t base, size_t len)
{
	char	value;

	if (len <= 0)
		return ;
	print_unsigned(addr / base, base, len - 1);
	value = HEX_STRING[(addr % base)];
	write(1, &value, 1);
}
