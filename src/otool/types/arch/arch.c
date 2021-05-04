/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:04:53 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 19:35:43 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void	print_archive_name(char *filename)
{
	write(1, "Archive : ", 10);
	write(1, filename, ft_strlen(filename));
	write(1, "\n", 1);
}

int	handle_arch(void *ptr, char *filename, off_t s)
{
	struct ar_hdr	*header;
	char			*str;
	size_t			len;

	print_archive_name(filename);
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
		ft_otool(ptr + sizeof(struct ar_hdr) + len - 1, NULL, s);
		ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	}
	return (EXIT_SUCCESS);
}
