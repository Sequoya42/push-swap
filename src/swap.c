/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:22:46 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/22 17:44:49 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sa(void)
{
	int			tmp;

	if (!S->lst || !S->lst->next)
		return ;
	tmp = S->lst->nb;
	S->lst->nb = S->lst->next->nb;
	S->lst->next->nb = tmp;
	S->count++;
}

void			ft_sb(void)
{
	int			tmp;

	if (!S->lb || !S->lb->next)
		return ;
	tmp = S->lb->nb;
	S->lb->nb = S->lb->next->nb;
	S->lb->next->nb = tmp;
	S->count++;
}

void			ft_ss(void)
{
	ft_sa();
	ft_sb();
	S->count--;
}
