/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:15:22 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 18:59:16 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

uint8_t	*get_ppc(void)
{
	static u_int8_t	ppc = 0;

	return (&ppc);
}

void	set_ppc(u_int8_t ppc)
{
	*get_ppc() = ppc;
}

uint32_t	ppc_32(uint32_t n)
{
	uint8_t	ppc;

	ppc = *get_ppc();
	if (ppc != 0)
		return (swap_uint32(n));
	return (n);
}

uint64_t	ppc_64(uint64_t n)
{
	uint8_t	ppc;

	ppc = *get_ppc();
	if (ppc != 0)
		return (swap_uint64(n));
	return (n);
}
