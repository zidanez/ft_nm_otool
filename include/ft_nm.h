/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:48:33 by fnancy            #+#    #+#             */
/*   Updated: 2021/04/24 14:39:52 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define HEX_STRING "0123456789abcdef"
# define SYMBOL_SIZE 512

typedef struct s_symbol
{
	char		name[SYMBOL_SIZE];
	uint8_t		type;
	uint8_t		ext;
	uint8_t		sect;
	uint64_t	value;
}				t_symbol;

typedef struct s_section
{
	uint32_t	index;
	uint32_t	text;
	uint32_t	data;
	uint32_t	bss;
}				t_section;

int				ft_error(char *filename, char *msg, int errnum);
t_section		*sections(void);
void			reset_sections(void);

t_symbol		*sort_symbols(t_symbol *symbols, uint32_t size);

void			set_ppc(u_int8_t ppc);
uint32_t		ppc_32(uint32_t n);
uint64_t		ppc_64(uint64_t n);

uint32_t		swap_uint32(uint32_t n);
uint64_t		swap_uint64(uint64_t n);

int				print_sections_symbols(t_symbol symbol, size_t len);
void			print_symbols(t_symbol symbol, size_t len);
void			print_unsigned(size_t addr, size_t base, size_t len);

#endif
