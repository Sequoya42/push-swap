/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:14:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/22 17:44:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_pa_next(void)
{
	t_lst		*tmp;

	tmp = S->lb_last;
	if (S->lb_last->prev)
	{
		S->lb_last = S->lb_last->prev;
		S->lb_last->next = NULL;
	}
	else
	{
		S->lb_last = NULL;
		S->lb = NULL;
	}
	S->nepa += 1;
	S->count++;
	free(tmp);
}

void			ft_pa(void)
{
	t_lst		*new;

	if (!S->lb)
		return ;
	new = malloc(sizeof(t_lst));
	new->nb = S->lb_last->nb;
	new->next = NULL;
	new->prev = NULL;
	if (S->lst == NULL)
	{
		S->lst = new;
		S->last = new;
	}
	else
	{
		S->lst->prev = new;
		new->next = S->lst;
		S->lst = new;
	}
	ft_pa_next();
}

static void		ft_pb_next(void)
{
	t_lst		*tmp;

	tmp = S->lst;
	if (S->lst->next)
	{
		S->lst = S->lst->next;
		S->lst->prev = NULL;
	}
	else
	{
		S->last = NULL;
		S->lst = NULL;
	}
	S->nepa -= 1;
	S->count++;
	free(tmp);
}

void			ft_pb(void)
{
	t_lst		*new;

	if (!S->lst)
		return ;
	new = malloc(sizeof(t_lst));
	new->nb = S->lst->nb;
	new->next = NULL;
	new->prev = NULL;
	if (S->lb == NULL)
	{
		S->lb = new;
		S->lb_last = new;
	}
	else
	{
		S->lb_last->next = new;
		new->prev = S->lb_last;
		S->lb_last = new;
	}
	ft_pb_next();
}
