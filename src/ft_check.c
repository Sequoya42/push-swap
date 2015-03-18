/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 05:31:47 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 06:26:07 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void            ft_get_min(void)
{
    t_lst       *tmp;

    tmp = S->lst;
    S->min = S->lst->nb;
    while (S->lst->next)
    {
        if (S->min > S->lst->nb)
            S->min = S->lst->nb;
        S->lst = S->lst->next;
    }
    S->lst = tmp;
}

int             check_solved(void)
{
    t_lst       *tmp;

    tmp = S->last;

    if (!tmp->prev && !S->lb)
        return (1);
    while (tmp->prev)
    {
        if (tmp->nb < tmp->prev->nb)
        {
            S->move = tmp;
            return (0);
        }
        tmp = tmp->prev;
    }
    if (!tmp->prev && !S->lb)
    {
        ft_putendl("Solved");
        return (1);
    }
    return (0);
}
