/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:03:54 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 14:14:23 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	parse_segments_32(struct load_command *lc)
{
	struct segment_command	*seg;
	struct section			*sect;
	uint32_t				i;

	seg = (struct segment_command *)lc;
	sect = (struct section *)((void *)seg + sizeof(*seg));
	i = -1;
	while (++i < ppc_32(seg->nsects))
	{
		if (!ft_strcmp((sect + i)->sectname, SECT_TEXT) \
			&& !ft_strcmp((sect + i)->segname, SEG_TEXT))
			sections()->text = sections()->index + 1;
		else if (!ft_strcmp((sect + i)->sectname, SECT_DATA) \
			&& !ft_strcmp((sect + i)->segname, SEG_DATA))
			sections()->data = sections()->index + 1;
		else if (!ft_strcmp((sect + i)->sectname, SECT_BSS) \
			&& !ft_strcmp((sect + i)->segname, SEG_DATA))
			sections()->bss = sections()->index + 1;
		++(sections()->index);
	}
}

static void	print_nm_32(uint32_t nsyms, uint32_t symoff,
						uint32_t stroff, void *ptr)
{
	struct nlist	*list;
	char			*strtable;
	char			*str;
	uint32_t		i;
	t_symbol		*symbols;

	list = ptr + symoff;
	strtable = (char *)ptr + stroff;
	i = 0;
	symbols = (t_symbol *)malloc(sizeof(t_symbol) * nsyms);
	while (i < nsyms)
	{
		str = strtable + ppc_32(list[i].n_un.n_strx);
		ft_strncpy(symbols[i].name, str, SYMBOL_SIZE);
		symbols[i].type = list[i].n_type & N_TYPE;
		symbols[i].ext = list[i].n_type & N_EXT;
		symbols[i].sect = list[i].n_sect;
		symbols[i].value = ppc_32(list[i].n_value);
		++i;
	}
	symbols = sort_symbols(symbols, nsyms);
	i = 0;
	while (i < nsyms)
		print_symbols(symbols[i++], 8);
	free(symbols);
}

int	handle_macho32(void *ptr, char *filename)
{
	uint32_t				ncmds;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	if (filename)
		print_file_name(filename);
	header = (struct mach_header *)ptr;
	set_ppc(swap_uint32(header->cputype) == CPU_TYPE_POWERPC);
	ncmds = ppc_32(header->ncmds);
	lc = ptr + sizeof(struct mach_header);
	while (ncmds--)
	{
		if (ppc_32(lc->cmd) == LC_SEGMENT)
			parse_segments_32(lc);
		if (ppc_32(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_nm_32(ppc_32(sym->nsyms), ppc_32(sym->symoff), \
						ppc_32(sym->stroff), ptr);
		}
		lc = (void *)lc + ppc_32(lc->cmdsize);
	}
	return (0);
}
