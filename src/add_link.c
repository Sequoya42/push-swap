/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:56:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 23:25:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
//	t_oper		*tmp;
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
/* 	else */
/* 	{ */
/* 		tmp = S->oper; */
/* 		while (tmp->next) */
/* 			tmp = tmp->next; */
/* 		tmp->next = new; */
/* 	} */
}

void			print_step(void)
{
	t_oper		*tmp;

	ft_putstr(KMAG);
	ft_putchar('\n');
	tmp = S->oper;
	while (tmp)
	{
		ft_putstr(tmp->s);
		tmp = tmp->next;
		
	}
	ft_putchar('\n');
	ft_putstr("Number of steps : ");
	ft_putnbrendl(S->count);
}

void			print_list(void)
{
	t_lst		*tmp;

	ft_putstr(KGRN);
	ft_putstr("pile a : ");
	tmp = S->last;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	ft_putstr(KBLU);
	ft_putstr("pile b : ");
	tmp = S->lb;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->next;
	}
	ft_putstr(KNRM);
	ft_putchar('\n');
}
