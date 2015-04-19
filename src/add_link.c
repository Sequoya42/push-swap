/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:56:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 06:41:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_link(void)
{
	t_lst		*new;
	int			i;

	i = 0;
	while (S->tab[i])
	{
		new = malloc(sizeof(t_lst));
		new->nb = ft_atoi(S->tab[i]);
		new->next = NULL;
		new->prev = NULL;
		if (S->lst == NULL)
		{
			S->lst = new;
			S->last = new;
			S->first = S->lst;
		}
		else
		{
			S->last->next = new;
			new->prev = S->last;
			S->last = new;
		}
		++i;
	}
}

void			add_oper(char *s)
{
	t_oper		*new;

	if (!(new = malloc(sizeof(t_oper))))
		return ;
	new->s = s;
	new->next = NULL;
	if (S->oper == NULL)
	{
		S->oper = new;
		S->last_oper = new;
	}
	else
	{
		S->last_oper->next = new;
		S->last_oper = S->last_oper->next;
	}
}

void			print_step(void)
{
	t_oper		*tmp;
	char		*last;

	if (S->flag[0] == 0 && S->oper != NULL)
	{
		S->flag[1] == 1 ? ft_putstr(KMAG) : ft_putstr(KNRM);
		tmp = S->oper;
		while (tmp->next)
		{
			ft_putstr(tmp->s);
			tmp = tmp->next;
		}
		last = ft_strsub(tmp->s, 0, ft_strlen(tmp->s) - 1);
		ft_putstr(last);
		ft_putchar('\n');
	}
	S->flag[1] == 1 ? ft_putstr(KYEL) : ft_putstr(KNRM);
	if (S->flag[4] == 1)
	{
		ft_putstr("Number of steps : ");
		ft_putnbrendl(S->count);
	}
	ft_putstr(KNRM);
}

void			print_list(void)
{
	t_lst		*tmp;

	if (S->flag[2] == 0)
		return ;
	S->flag[1] == 1 ? ft_putstr(KGRN) : ft_putstr(KNRM);
	ft_putstr("pile a : ");
	tmp = S->last;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	S->flag[1] == 1 ? ft_putstr(KBLU) : ft_putstr(KNRM);
	ft_putstr("pile b : ");
	tmp = S->lb;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->next;
	}
	ft_putstr(KNRM);
	ft_putstr("\n\n");
}
