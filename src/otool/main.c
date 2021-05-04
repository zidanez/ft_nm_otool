/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:06:50 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/04 14:19:55 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	ft_otool(void *ptr, char *filename, off_t size)
{
	uint32_t	magic;
	char		*filename_cpy;

	filename_cpy = filename;
	magic = *(uint32_t *)ptr;
	reset_sections();
	if (magic == AR_MAGIC || magic == AR_CIGAM)
		return (handle_arch(ptr, filename_cpy, size));
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (handle_macho64(ptr, filename, size));
	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		return (handle_macho32(ptr, filename, size));
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		return (handle_fat32(ptr, filename_cpy, size));
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		return (handle_fat64(ptr, filename_cpy, size));
	ft_error(filename_cpy, INV_OBJ, EXIT_FAILURE);
	return (-1);
}

int	read_file(char *filename)
{
	int			fd;
	struct stat	buf;
	void		*ptr;

	fd = open(filename, O_RDONLY);
	if (fd == -1 && errno == EACCES)
		return (ft_error(filename, "Permission denied.", 1));
	else if (fd == -1)
		return (ft_error(filename, "No such file or directory.", 2));
	if (fstat(fd, &buf) < 0)
		return (ft_error(filename, "Permission denied.", 3));
	if (S_ISDIR(buf.st_mode))
		return (ft_error(filename, "Is a directory.", 4));
	ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == MAP_FAILED)
		return (EXIT_FAILURE);
	ft_otool(ptr, filename, buf.st_size);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*filename;

	if (argc < 2)
		return (read_file("a.out"));
	i = 0;
	while (++i < argc)
	{
		filename = argv[i];
		read_file(filename);
	}
	return (EXIT_SUCCESS);
}
