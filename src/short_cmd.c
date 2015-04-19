/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:11:23 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 07:17:05 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_check_sub_pb(int i, t_lst *tmp)
{
	if (S->move == NULL || tmp == NULL || S->lst == NULL)
		return ;
	if (tmp->nb == S->move->nb)
	{
		while (tmp != S->lst)
		{
			if (i < (S->nepa / 2))
			{
				ft_rra();
				add_oper("rra ");
				S->flag[3] == 1 ? ft_putendl("rra ") : ft_putstr("");
			}
			else
			{
				ft_ra();
				add_oper("ra ");
				S->flag[3] == 1 ? ft_putendl("ra ") : ft_putstr("");
			}
		}
		ft_pb();
		add_oper("pb ");
		S->flag[3] == 1 ? ft_putendl("pb ") : ft_putstr("");
		return ;
	}
}

void			ft_check_pb(void)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	if (!S->last->prev || S->move == NULL || S->lst == NULL)
		return ;
	tmp = S->last;
	while (tmp)
	{
		if (S->move && S->move->nb == S->lst->nb)
		{
			ft_pb();
			add_oper("pb ");
			S->flag[3] == 1 ? ft_putendl("pb ") : ft_putstr("");
		}
		ft_check_sub_pb(i, tmp);
		tmp = tmp->prev;
		++i;
	}
}

static void		ft_check_sub_pa(void)
{
	if (!S->lst || !S->lst->next)
	{
		while (S->lb)
		{
			ft_pa();
			add_oper("pa ");
			S->flag[3] == 1 ? ft_putendl("pa ") : ft_putstr("");
		}
	}
}

int				ft_check_pa(void)
{
	t_lst		*tmp;

	ft_check_sub_pa();
	if (!S->last->prev)
		return (0);
	tmp = S->last;
	while (tmp->prev)
	{
		if (tmp->nb < tmp->prev->nb)
			return (0);
		tmp = tmp->prev;
	}
	if (S->lb)
	{
		while (S->lb)
		{
			ft_pa();
			add_oper("pa ");
			S->flag[3] == 1 ? ft_putendl("pa ") : ft_putstr("");
		}
	}
	return (0);
}
