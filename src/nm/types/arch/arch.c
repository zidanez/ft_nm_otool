/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:41:40 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 14:53:14 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	handle_arch(void *ptr, char *filename, off_t s)
{
	struct ar_hdr	*header;
	char			*str;
	size_t			len;

	ptr += SARMAG;
	header = (struct ar_hdr *)ptr;
	ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	while (ptr)
	{
		header = (struct ar_hdr *)ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return (EXIT_FAILURE);
		str = ptr + sizeof(struct ar_hdr);
		if (ptr + (ft_atoi(header->ar_size) + sizeof(struct ar_hdr)) > ptr + s)
			return (EXIT_FAILURE);
		print_arch_file_name(filename, str);
		len = ft_strlen(str);
		while (!str[len++])
			;
		ft_nm(ptr + sizeof(struct ar_hdr) + len - 1, filename, s, 0);
		ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	}
	return (EXIT_SUCCESS);
}
