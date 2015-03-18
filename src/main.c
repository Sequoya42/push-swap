/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:21:57 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 07:22:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap		*singleton(void)
{
	static t_swap	swap;

	return (&swap);
}

int			ft_testa(void)
{
	int i = 0;
	ft_pb();
	ft_pb();
	ft_pb();
	print_list();
	while (i++ < 4)
	{
		if (check_solved())
			return (1);
		ft_check_pa();
		ft_putnbrendl(S->move->nb);
		print_list();
		ft_putendl(S->oper);
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 1)
		return (ft_error(NULL, NULL, "too few arguments"));
	S->tab = ft_strdup_tab(av + 1);
	S->lst = NULL;
	S->lb = NULL;
	S->oper = ft_strnew(1);
	if (S->tab == NULL)
		return (-1);
	if ((verif_tab()) == -1)
		return (-1);
	add_link();
	print_list();
	if (check_solved())
	{
		ft_putendl("Already in the right order");
		return (1);
	}
	while (ft_resolve() != 1)
	print_list();
	return (0);
}
