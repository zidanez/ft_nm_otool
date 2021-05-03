/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:29:25 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 14:42:33 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_symbol_type(t_symbol symbol, char ch)
{
	if (symbol.ext)
	{
		write(1, " ", 1);
		ch = ft_toupper(ch);
		write(1, &ch, 1);
		write(1, " ", 1);
	}
	else
	{
		write(1, " ", 1);
		ch = ft_tolower(ch);
		write(1, &ch, 1);
		write(1, " ", 1);
	}
}
