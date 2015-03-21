/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 05:31:47 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 01:51:47 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void            ft_get_min(void)
{
    t_lst       *tmp;

	if (!S->lst)
		return ;
    tmp = S->last;
    S->min = S->last->nb;
    while (S->last->prev)
    {
        if (S->min > S->last->nb)
            S->min = S->last->nb;
        S->last = S->last->prev;
    }
	if (S->min > S->lst->nb)
		S->min = S->lst->nb;
	ft_putendl("-----------");
	ft_putnbrendl(S->min);
	ft_putnbrendl(S->lst->nb);
	if (S->move)
		ft_putnbrendl(S->move->nb);
	ft_putendl("-----------");
    S->last = tmp;
}

int             check_solved(void)
{
    t_lst       *tmp;

    tmp = S->last;
    if (!tmp->prev && !S->lb)
        return (1);
    while (tmp->prev)
    {
        if (tmp->nb == S->min)// Ten es ici
        {
            S->move = tmp;
            return (0);
        }
        tmp = tmp->prev;
    }
	if (tmp->nb == S->min)
		S->move = tmp;
    if (!S->lb)
        return (1);
    return (0);
}
