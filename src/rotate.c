/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 23:11:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 22:08:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_ra(void)
{
	t_lst		*tmp;

	if (!S->last || !S->last->prev)
		return ;
	if (!S->last->prev->prev)
	{
		ft_sa();
		return ;
	}
	S->last->next = S->lst;
	tmp = S->last;
	S->last = S->lst;
	S->lst = S->lst->next;
	S->lst->prev = NULL;
	S->last->prev = tmp;
	S->count++;
}

void			ft_rb(void)
{
	t_lst		*tmp;

	if (!S->lb || !S->lb->next)
		return ;
	if (!S->lb->next->next)
	{
		ft_sb();
		return ;
	}
	S->lb->prev = S->lb_last;
	tmp = S->lb;
	S->lb = S->lb_last;
	S->lb->prev->next = NULL;
	S->lb_last = S->lb_last->prev;
	S->lb->next = tmp;
	S->count++;
}

void			ft_rr(void)
{
	ft_ra();
	ft_rb();
	S->count++;
}
