/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 05:36:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_check_swap(void)
{
	t_lst		*tmp1;
	t_lst		*tmp2;

	if (S->lst->next->next)
	{
		tmp1 = S->lst->next->next;
		tmp2 = tmp1->next;
		if (S->lst->nb > S->lst->next->nb && tmp2 > tmp1)
		{
			ft_pb();
			ft_pb();
			ft_ss();
			ft_pa();
			ft_pa();
			S->oper = ft_strjoin(S->oper, "pb pb ss pa pa ");
		}
	}
	else if (S->lst->nb > S->lst->next->nb)
	{
		ft_sa();
		S->oper = ft_strjoin(S->oper, "sa ");
	}
}

int			ft_resolve(void)
{
	if (check_solved())
		return (1);
	ft_get_min();
	ft_check_swap();
	if (check_solved())
		return (1);
	

	return (0);
}

/* si a trie et b trie alors push a puis fini */
