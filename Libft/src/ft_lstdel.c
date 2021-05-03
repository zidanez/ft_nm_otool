/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:58:22 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 15:53:42 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*nxt_it;
	t_list	*nxt_nxt;

	ptr = *alst;
	nxt_it = ptr->next;
	while (nxt_it->next != NULL)
	{
		nxt_nxt = nxt_it->next;
		del(nxt_it->content, nxt_it->content_size);
		free(nxt_it);
		nxt_it = nxt_nxt;
	}
	del(nxt_it->content, nxt_it->content_size);
	free(nxt_it);
	del(ptr->content, ptr->content_size);
	free(ptr);
	nxt_nxt = NULL;
	ptr = NULL;
	nxt_it = NULL;
	*alst = NULL;
}
