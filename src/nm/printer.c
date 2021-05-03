/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:34:41 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 14:36:31 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	print_sections_symbols(t_symbol symbol, size_t len)
{
	if (symbol.type == N_ABS || symbol.type == N_SECT || symbol.type == N_INDR)
		print_unsigned(symbol.value, 16, len);
	if (symbol.type == N_ABS)
		print_symbol_type(symbol, 'a');
	else if (symbol.type == N_INDR)
		print_symbol_type(symbol, 'i');
	else if (symbol.type == N_SECT)
	{
		if (symbol.sect == sections()->bss)
			print_symbol_type(symbol, 'b');
		else if (symbol.sect == sections()->data)
			print_symbol_type(symbol, 'd');
		else if (symbol.sect == sections()->text)
			print_symbol_type(symbol, 't');
		else
			print_symbol_type(symbol, 's');
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
		print_symbol_type(symbol, 'u');
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

void	print_file_name(char *filename)
{
	write(1, "\n", 1);
	write(1, filename, ft_strlen(filename));
	write(1, ":\n", 2);
}

void	print_arch_file_name(char *filename, char *symbol)
{
	write(1, "\n", 1);
	write(1, filename, ft_strlen(filename));
	write(1, "(", 1);
	write(1, symbol, ft_strlen(symbol));
	write(1, "):\n", 3);
}
