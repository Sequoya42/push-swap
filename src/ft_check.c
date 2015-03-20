/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 05:31:47 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/20 18:04:38 by rbaum            ###   ########.fr       */
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
//	if (S->min > S->lst->nb)
//		S->min = S->lst->nb;
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
        if (tmp->nb < tmp->prev->nb)// Ten es ici
        {
            S->move = tmp;
            return (0);
        }
        tmp = tmp->prev;
    }
    if (!tmp->prev && !S->lb)
        return (1);
    return (0);
}
