/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:21:57 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 04:25:31 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap		*singleton(void)
{
	static t_swap	swap;

	return (&swap);
}

void		ft_testa(void)
{
	int i = 0;
	print_list();
	while (i++ < 33)
	{
		ft_pb();
		ft_pb();
		ft_pa();
		ft_ss();
		print_list();
	}
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
	ft_resolve();
	print_list();
	write(1, S->oper, ft_strlen(S->oper) -1);
	ft_putchar('\n');
	return (0);
}
