/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:21:57 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 23:27:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* RETIRE les fichiers de la libft que tu utilises pas, etre sur d'utiliser que malloc free write et rien dautre. laisse que ce aue tu utilise supprime le reste */
/* regler lenroule de 200 elements 20 GO de memoire tout ca tout ca */

t_swap		*singleton(void)
{
	static t_swap	swap;

	return (&swap);
}

int		ft_init_all(void)
{
	S->lst = NULL;
	S->move = NULL;
	S->lb = NULL;
	S->count = 0;
	if (S->tab == NULL)
		return (-1);
	if ((verif_tab()) == -1)
		return (-1);
	add_link();
	S->nepa = ft_nb_tab(S->tab);
	return (0);
}

int			main(int ac, char **av)
{

	if (ac == 1)
		return (ft_error(NULL, NULL, "too few arguments"));
	S->tab = ft_strdup_tab(av + 1);
	if (ft_init_all() == -1)
		return (-1);
	print_list();
	while (ft_resolve() != 1)
		ft_putendl(S->last_oper->s);//print_list();
	print_list();
	print_step();
	return (0);
}

/* ./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"` */
