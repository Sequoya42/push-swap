/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:23:38 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 22:55:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_rev(void)
{
	if (S->last->nb == S->move->nb)
		ft_rra();
	else if (S->last->nb < S->last->prev->nb)
	{
		ft_rra();
		ft_rra();
		ft_sa();
		ft_ra();
		ft_ra();
	}
	else if (S->last->prev->nb == S->move->nb)
	{
		ft_rra();
 		ft_rra();
 		ft_sa();
 		ft_ra();
	}
	return (0);
}
