/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 04:26:35 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_get_min(void)
{
	t_lst		*tmp;

	tmp = S->lst;
	S->min = S->lst->nb;
	
	while (S->lst)
	{
		if (S->min > S->lst->nb)
			S->min = S->lst->nb;
		S->lst = S->lst->next;
	}
	S->lst = tmp;
}

void			ft_check_swap(void)
{
	t_lst		*tmp1;
	t_lst		*tmp2;

	tmp1 = S->lst->next->next;
	tmp2 = S->lst->next->next->next;
	if (S->lst->nb > S->lst->next->nb && tmp2 > tmp1)
	{
		ft_pb();
		ft_pb();
		ft_ss();
		ft_pa();
		ft_pa();
		S->oper = ft_strjoin(S->oper, "pb pb ss pa pa ");
	}
	else if (S->lst->nb > S->lst->next->nb)
	{
		ft_sa();
		S->oper = ft_strjoin(S->oper, "sa ");
	}
}
void			ft_resolve(void)
{
	ft_get_min();
	ft_check_swap();
}
