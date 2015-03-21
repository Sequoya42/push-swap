/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 22:55:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_check_swap(void)
{
	t_lst		*tmp1;
	t_lst		*tmp2;

	if (S->lst->next->next)
	{
		tmp1 = S->lst->next->next;
		tmp2 = tmp1->next;
		 if (S->lst->nb > S->lst->next->nb)
			ft_sa();
		 else if (S->lst->nb > S->lst->next->nb && tmp2->nb < tmp1->nb)
		{
			ft_pb();
			ft_pb();
			ft_ss();
			ft_pa();
			ft_pa();
		}
	}
	return (0);
}

int			ft_resolve(void)
{

	ft_check_pa();
 	ft_get_min();
	if (check_solved())
		return (1);
 	ft_check_swap();
	ft_check_pb();
 	ft_check_rev(); 
	return (0);
}

/* si a trie et b trie alors push a puis fini */
/* B doffice trie vu quon ajoute sur b dans un certain ordre */
