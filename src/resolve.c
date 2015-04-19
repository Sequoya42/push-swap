/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 07:33:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_tri_rev(void)
{
	t_lst			*tmp;

	tmp = S->last;
	while (tmp->prev)
	{
		if (tmp->nb > tmp->prev->nb)
			return (0);
		tmp = tmp->prev;
	}
	ft_sa();
	ft_rra();
	add_oper("sa rra ");
	return (1);
}

static void			ft_check_double_swap(void)
{
	t_lst			*tmp1;
	t_lst			*tmp2;

	tmp1 = S->lst->next->next;
	tmp2 = tmp1->next;
	if (S->lst->nb > S->lst->next->nb && tmp2->nb < tmp1->nb)
	{
		ft_pb();
		ft_pb();
		ft_ss();
		ft_pa();
		ft_pa();
		add_oper("pb pb ss pa pa ");
		S->flag[3] == 1 ? ft_putendl("pb pb ss pa pa ") : ft_putstr("");
	}
}

static void			ft_check_swap(void)
{
	ft_get_min();
	if (S->lst->next && S->lst)
	{
		if (S->lst->next->nb == S->min && S->lst->nb > S->lst->next->nb)
		{
			ft_sa();
			add_oper("sa ");
			S->flag[3] == 1 ? ft_putendl("sa ") : ft_putstr("");
		}
	}
	else if (S->lst->next && S->lst->next->next && S->lst->next->next->next)
		ft_check_double_swap();
}

int					ft_resolve(void)
{
	ft_get_min();
	if (ft_nb_tab(S->tab) == 1)
		return (1);
	if (ft_nb_tab(S->tab) == 3)
		ft_tri_rev();
	ft_check_rev();
	ft_check_swap();
	ft_check_pa();
	ft_get_min();
	if (check_solved())
		return (1);
	ft_check_pb();
	return (0);
}
