/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:57:55 by fnancy            #+#    #+#             */
/*   Updated: 2021/04/24 13:53:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int			ft_nm(void *ptr)
{
	uint32_t	magic;

	magic = *(uint32_t *)ptr;
	reset_sections();

	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (handle_macho64(ptr));
	return (-1);
}

int main(int argc, char **argv) {

    struct stat buf;
	void		*ptr;
	char		*filename;
	int			fd;

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(filename, "Permission denied.", 1));
	else if (fd == -1)
		return (ft_error(filename, "No such file or directory.", 2));
	if (fstat(fd, &buf) < 0)
		return (ft_error(filename, "Permission denied.", 3));
	if (S_ISDIR(buf.st_mode))
		return (ft_error(filename, "Is a directory.", 4));
    
    ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	ft_nm(ptr);
    munmap(ptr, buf.st_size);
	return (1);
    
}
