/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:23:38 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 07:27:41 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_do_the_dance(int i)
{
	if (S->last->nb < S->last->prev->nb && i != 0 && S->last->nb != S->min)
	{
		ft_rra();
		ft_rra();
		ft_sa();
		ft_ra();
		ft_ra();
		add_oper("rra rra sa ra ra ");
		S->flag[3] == 1 ? ft_putendl("rra rra sa ra ra ") : ft_putstr("");
	}
}

static void		ft_sub_check(void)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	tmp = S->lst;
	if (S->last->prev == NULL || S->nepa < 4)
		return ;
	if (S->lst->next)
	{
		while (i < (S->nepa - 2))
		{
			if (S->lst->nb > S->lst->next->nb)
			{
				i = 0;
				break ;
			}
			S->lst = S->lst->next;
			++i;
		}
		S->lst = tmp;
		ft_do_the_dance(i);
	}
}

int				ft_check_rev(void)
{
	if (S->move != NULL && S->last->nb == S->move->nb)
		ft_rra();
	ft_sub_check();
	if (S->last->prev == NULL)
		return (0);
	if (S->move == NULL)
		return (0);
	if (S->last->prev != NULL && S->move != NULL)
		if (S->last->prev->nb == S->move->nb)
		{
			ft_rra();
			ft_rra();
			ft_sa();
			ft_ra();
			add_oper("rra rra sa ra");
			S->flag[3] == 1 ? ft_putendl("rra rra sa ra ") : ft_putstr("");
		}
	return (0);
}
