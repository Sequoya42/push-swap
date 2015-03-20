/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 00:45:01 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/19 17:05:24 by rbaum            ###   ########.fr       */
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
	tmp->next = S->lst;
	S->last = S->last->prev;
	S->last->next = NULL;
	tmp->prev = NULL;
	S->lst->prev = tmp;
	S->lst = S->lst->prev;
	S->oper = ft_strjoin(S->oper, "rra ");
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
	tmp->prev = S->lb_last;
	S->lb = S->lb->next;
	S->lb->prev = NULL;
	tmp->next = NULL;
	S->lb_last->next = tmp;
	S->lb_last = S->lb_last->next;
	S->oper = ft_strjoin(S->oper, "rrb ");
}

void            ft_rrr(void)
{
    ft_rra();
    ft_rrb();
	S->oper = ft_strsub(S->oper, 0, ft_strlen(S->oper) - 6);
	S->oper = ft_strjoin(S->oper, "rrr ");
}
