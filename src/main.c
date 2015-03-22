/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:21:57 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/22 02:31:49 by rbaum            ###   ########.fr       */
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

static int		  ft_flags(char *av)
{
	int i;

	i = 0;
	while (i < 5)
		S->flag[i++] = 0;
	i = 1;
	if (av[0] == '-')
	{
		while (av[i])
		{
			S->flag[0] = av[i] == 's' ? 1 : S->flag[0];
			S->flag[1] = av[i] == 'c' ? 1 : S->flag[1];
			S->flag[2] = av[i] == 'p' ? 1 : S->flag[2];
			S->flag[3] = av[i] == 'l' ? 1 : S->flag[3];
			S->flag[4] = av[i] == 'n' ? 1 : S->flag[4];
			++i;
		}
		i = 0;
		while (i < 5)
			if (S->flag[i] == 1)
				return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{

	if (ac == 1)
		return (ft_error(NULL, NULL, "too few arguments"));
	if (ft_flags(av[1]) == 1)
		S->tab = ft_strdup_tab(av + 2);
	else
		S->tab = ft_strdup_tab(av + 1);
	if (ft_init_all() == -1)
		return (-1);
	print_list();
	while (ft_resolve() != 1)
	{
		print_list();
	}
	print_list();
	print_step();
	return (0);
}

/* ./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"` */
