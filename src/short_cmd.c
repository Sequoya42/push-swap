/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:11:23 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/20 22:40:08 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_pb(void)
{
	t_lst	*tmp;
	if (!S->last)
		return ;
	tmp = S->last;
	while (tmp)
	{
		if (tmp->nb == S->move->nb)
		{
			while (tmp != S->lst)
				ft_ra(); // if blabla ra else rra
			ft_pb();
			return ;
		}
		tmp = tmp->prev;
	}

}

void		ft_check_pa(void)
{
	t_lst	*tmp;
	int		i;

	i = S->nepa;
	if (!S->lst || !S->lst->next)
	{
		while (S->lb)
			ft_pa();
	}
	tmp = S->last;
	while (tmp->prev)
	{
		if (tmp->nb < tmp->prev->nb)
			return ;
		tmp = tmp->prev;
	}
	if (S->lb)
	{
		while (S->lb)
		{
			ft_pa();

		}
		exit(0);
	}
}
