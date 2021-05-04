/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:45:29 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 18:30:50 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

t_section	*sections(void)
{
	static t_section	sections = {0, 0, 0, 0};

	return (&sections);
}

void	reset_sections(void)
{
	sections()->index = 0;
	sections()->text = 0;
	sections()->data = 0;
	sections()->bss = 0;
}
