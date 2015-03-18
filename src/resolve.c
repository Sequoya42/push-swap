/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 04:08:35 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_get_min(void)
{
	S->min = S->lst->nb;
	while (S->lst)
	{
		if (S->min > S->lst->nb)
			S->min = S->lst->nb;
		S->lst = S->lst->next;
	}
}

void		ft_check_swap();
void		ft_resolve(void)
{
	ft_get_min();
	ft_check_swap();
	if (S->lst->nb > S->lst->next->nb)
	{
		ft_sa();
		oper = ft_strjoin(oper, "sa ");
	}
	
}
