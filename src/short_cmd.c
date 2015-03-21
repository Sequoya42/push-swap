/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:11:23 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 02:38:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (S->move && tmp->nb == S->move->nb)
		{
			while (tmp != S->lst)
			{
				if (i < (S->nepa / 2))
					ft_rra();
				else
					ft_ra();
			}
			ft_pb();
			return ;
		}
		tmp = tmp->prev;
		++i;
	}

}

int		ft_check_pa(void)
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
			return (0);
		tmp = tmp->prev;
	}
	if (S->lb)
	{
		while (S->lb)
			ft_pa();
	}
	ft_get_min();
	return (check_solved());
}
