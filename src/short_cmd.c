/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:11:23 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 23:23:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_sub_pb(int i, t_lst *tmp)
{
	if (S->move && tmp->nb == S->move->nb)
	{
		while (tmp != S->lst)
		{
			if (i < (S->nepa / 2))
			{
				ft_rra();
				add_oper("rra ");
			}
			else
			{
				ft_ra();
				add_oper("ra ");
			}
		}
		ft_pb();
		return ;
	}
}

void		ft_check_pb(void)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	if (!S->last)
		return ;
	tmp = S->last;
	while (tmp)
	{
		if (S->move && S->move->nb == S->lst->nb)
			ft_pb();
		ft_check_sub_pb(i, tmp);
		tmp = tmp->prev;
		++i;
	}

}

int		ft_check_pa(void)
{
	t_lst	*tmp;

	if (!S->lst || !S->lst->next)
	{
		while (S->lb)
			ft_pa();
	}
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
			ft_pa();
	}
	return (0);
}
