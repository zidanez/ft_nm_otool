/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:03:38 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/04 14:18:38 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	is_hostarch(cpu_type_t type)
{
	if ((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
		return (1);
	if ((type == CPU_TYPE_I386) && (sizeof(void *) == 4))
		return (1);
	return (0);
}

static void	print_otool(uint32_t i, char *filename)
{
	write(1, "\n", 1);
	write(1, filename, ft_strlen(filename));
	if (i == 0)
		write(1, PPC64_STRING, ft_strlen(PPC64_STRING));
	else
		write(1, X86_64_STRING, ft_strlen(X86_64_STRING));
}

int	handle_fat64(void *ptr, char *filename, off_t s)
{
	uint32_t			nfat;
	uint32_t			i;
	struct fat_header	*header;
	struct fat_arch_64	*arch;

	header = (struct fat_header *)ptr;
	nfat = swap_uint64(header->nfat_arch);
	arch = (struct fat_arch_64 *)(header + 1);
	i = -1;
	while (++i < nfat)
	{
		if (nfat > 1 && !i && is_hostarch(swap_uint32(arch[i + 1].cputype)))
			continue ;
		if (nfat > 1 && !is_hostarch(swap_uint32(arch[i].cputype)))
			print_otool(i, filename);
		if (nfat > 1 && !is_hostarch(swap_uint64(arch[i].cputype)))
			ft_otool(ptr + swap_uint64(arch[i].offset), NULL, s);
		else
			ft_otool(ptr + swap_uint64(arch[i].offset), filename, s);
		if (is_hostarch(swap_uint32(arch[i].cputype)))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}