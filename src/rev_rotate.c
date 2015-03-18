/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 00:45:01 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 02:15:58 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void            ft_rra(void)
{
	t_lst		*tmp;

	if (!S->last || !S->last->prev)
		return ;
	if (!S->last->prev->prev)
	{
		ft_sa();
		return ;
	}
	tmp = S->last;
	S->last = S->last->prev;
	tmp->prev = NULL;
	S->lst->prev = tmp;
	S->lst = S->lst->prev;
}

void            ft_rrb(void)
{
    t_lst       *tmp;

	if (!S->lb || !S->lb->next)
		return ;
	if (!S->lb->next->next)
	{
		ft_sb();
		return ;
	}
	tmp = S->lb;
	S->lb = S->lb->next;
	tmp->next = NULL;
	S->lb_last->next = tmp;
	S->lb_last = S->lb_last->next;
}

void            ft_rrr(void)
{
    ft_rra();
    ft_rrb();
}
