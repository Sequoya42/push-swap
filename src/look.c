/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:56:31 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 05:59:34 by rbaum            ###   ########.fr       */
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

void			print_current(void)
{
	ft_putstr(KMAG);
	ft_putchar('\n');
	write(1, S->oper, ft_strlen(S->oper) -1);
	ft_putchar('\n');
}
void			print_step(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	//print_current();
	ft_putstr(KCYN);
	ft_putstr("Number of operations : ");
	while (S->oper[i])
	{
		if (S->oper[i] == ' ')
			++j;
		++i;
	}
	ft_putnbrendl(j);
}


void			print_list(void)
{
	t_lst		*tmp;

	ft_putstr(KGRN);
	ft_putstr("pile a : ");
//	ft_putstr(KNRM);
	tmp = S->last;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	ft_putstr(KBLU);
	ft_putstr("pile b : ");
//	ft_putstr(KNRM);
	tmp = S->lb;
	while (tmp)
	{
		ft_putnbrn(tmp->nb);
		tmp = tmp->next;
	}
	ft_putchar('\n');
//	print_current();

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 05:31:47 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 02:23:02 by rbaum            ###   ########.fr       */
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
    if (!tmp->prev && !S->lb)
        return (1);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:21:57 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 05:56:11 by rbaum            ###   ########.fr       */
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
	S->oper = ft_strnew(1);
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
	while (ft_resolve() != 1)
		print_list();

	print_step();
	print_list();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:23:38 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/20 17:11:48 by rbaum            ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:14:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 00:57:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_pa_next(void)
{
	if (S->lb_last->prev)
	{
		S->lb_last = S->lb_last->prev;
		S->lb_last->next = NULL;
	}
	else
	{
		S->lb_last = NULL;
		S->lb = NULL;
	}
	S->nepa += 1;
}

void			ft_pa(void)
{
	t_lst		*new;

	if (!S->lb)
		return ;
	new = malloc(sizeof(t_lst));
	new->nb = S->lb_last->nb;
	new->next = NULL;
	new->prev = NULL;
	if (S->lst == NULL)
	{
		S->lst = new;
		S->last = new;
	}
	else
	{
		S->lst->prev = new;
		new->next = S->lst;
		S->lst = new;
	}
	ft_pa_next();
	S->oper = ft_strjoin(S->oper, "pa ");
}

static void		ft_pb_next(void)
{
	if (S->lst->next)
	{
		S->lst = S->lst->next;
		S->lst->prev = NULL;
	}
	else
	{
		S->last = NULL;
		S->lst = NULL;
	}
	S->nepa -= 1;
}

void			ft_pb(void)
{
	t_lst		*new;

	if (!S->lst)
		return ;
	new = malloc(sizeof(t_lst));
	new->nb = S->lst->nb;
	new->next = NULL;
	new->prev = NULL;
	if (S->lb == NULL)
	{
		S->lb = new;
		S->lb_last = new;
	}
	else
	{
		S->lb_last->next = new;
		new->prev = S->lb_last;
		S->lb_last = new;
	}
	ft_pb_next();
	S->oper = ft_strjoin(S->oper, "pb ");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 03:48:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 05:46:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_check_swap(void)
{
	t_lst		*tmp1;
	t_lst		*tmp2;

	if (S->lst->next->next)
	{
		tmp1 = S->lst->next->next;
		tmp2 = tmp1->next;
		 if (S->lst->nb > S->lst->next->nb)
			ft_sa();
		 else if (S->lst->nb > S->lst->next->nb && tmp2->nb < tmp1->nb)
		{
			ft_pb();
			ft_pb();
			ft_ss();
			ft_pa();
			ft_pa();
		}
	}
	return (0);
}

int			ft_resolve(void)
{

	if (ft_check_pa() == 1)
		return (1);
 	ft_get_min();
	if (check_solved())
		return (1);
	ft_check_pb();
 	ft_check_swap();
//	sleep(1);
 	ft_check_rev(); 
/* 	ft_putnbrendl(S->min); */
/* 	ft_putnbrendl(S->move->nb); */
	return (0);
}

/* si a trie et b trie alors push a puis fini */
/* B doffice trie vu quon ajoute sur b dans un certain ordre */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 00:45:01 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/19 17:05:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void            ft_rra(void)
{
	t_lst		*tmp;

	if (!S->last || !S->last->prev)
		return ;
	if (!S->last->prev->prev)
	{
		ft_sa();
		return ;
	}
	tmp = S->last;
	tmp->next = S->lst;
	S->last = S->last->prev;
	S->last->next = NULL;
	tmp->prev = NULL;
	S->lst->prev = tmp;
	S->lst = S->lst->prev;
	S->oper = ft_strjoin(S->oper, "rra ");
}

void            ft_rrb(void)
{
    t_lst       *tmp;

	if (!S->lb || !S->lb->next)
		return ;
	if (!S->lb->next->next)
	{
		ft_sb();
		return ;
	}
	tmp = S->lb;
	tmp->prev = S->lb_last;
	S->lb = S->lb->next;
	S->lb->prev = NULL;
	tmp->next = NULL;
	S->lb_last->next = tmp;
	S->lb_last = S->lb_last->next;
	S->oper = ft_strjoin(S->oper, "rrb ");
}

void            ft_rrr(void)
{
    ft_rra();
    ft_rrb();
	S->oper = ft_strsub(S->oper, 0, ft_strlen(S->oper) - 6);
	S->oper = ft_strjoin(S->oper, "rrr ");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 23:11:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/20 17:53:26 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_ra(void)
{
	t_lst		*tmp;

	if (!S->last || !S->last->prev)
		return ;
	if (!S->last->prev->prev)
	{
		ft_sa();
		return ;
	}
	S->last->next = S->lst;
	tmp = S->last;
	S->last = S->lst;
	S->lst = S->lst->next;
	S->lst->prev = NULL;
	S->last->prev = tmp;
	S->oper = ft_strjoin(S->oper, "ra ");
}

void			ft_rb(void)
{
	t_lst		*tmp;

	if (!S->lb || !S->lb->next)
		return ;
	if (!S->lb->next->next)
	{
		ft_sb();
		return ;
	}
	S->lb->prev = S->lb_last;
	tmp = S->lb;
	S->lb = S->lb_last;
	S->lb->prev->next = NULL;
	S->lb_last = S->lb_last->prev;
	S->lb->next = tmp;
	S->oper = ft_strjoin(S->oper, "rb ");
}

void			ft_rr(void)
{
	ft_ra();
	ft_rb();
	S->oper = ft_strsub(S->oper, 0, ft_strlen(S->oper) - 6);
	S->oper = ft_strjoin(S->oper, "rr ");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:11:23 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 02:38:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_pb(void)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	if (!S->last)
		return ;

	tmp = S->last;
	while (tmp)
	{

		if (S->move && S->move->nb == S->lst->nb)
			ft_pb();
		if (S->move && tmp->nb == S->move->nb)
		{
			while (tmp != S->lst)
			{
				if (i < (S->nepa / 2))
					ft_rra();
				else
					ft_ra();
			}
			ft_pb();
			return ;
		}
		tmp = tmp->prev;
		++i;
	}

}

int		ft_check_pa(void)
{
	t_lst	*tmp;
	int		i;

	i = S->nepa;
	if (!S->lst || !S->lst->next)
	{
		while (S->lb)
			ft_pa();
	}
	tmp = S->last;
	while (tmp->prev)
	{
		if (tmp->nb < tmp->prev->nb)
			return (0);
		tmp = tmp->prev;
	}
	if (S->lb)
	{
		while (S->lb)
			ft_pa();
	}
	ft_get_min();
	return (check_solved());
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:22:46 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/19 17:04:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sa(void)
{
	int			tmp;

	if (!S->lst || !S->lst->next)
		return ;
	tmp = S->lst->nb;
	S->lst->nb = S->lst->next->nb;
	S->lst->next->nb = tmp;
	S->oper = ft_strjoin(S->oper, "sa ");
}

void			ft_sb(void)
{
	int			tmp;

	if (!S->lb || !S->lb->next)
		return ;
	tmp = S->lb->nb;
	S->lb->nb = S->lb->next->nb;
	S->lb->next->nb = tmp;
	S->oper = ft_strjoin(S->oper, "sb ");
}

void			ft_ss(void)
{
	ft_sa();
	ft_sb();
	S->oper = ft_strsub(S->oper, 0, ft_strlen(S->oper) - 6);
	S->oper = ft_strjoin(S->oper , "ss ");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:43:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/20 17:02:40 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			verif_itoa(int i)
{
	int				l;
	int				k;
	char			*tmp;

	l = 0;
	k = MP ? 1 : 0;
	tmp = ft_strnew(ft_strlen(S->tab[i]));
	while (l < 5)
	{
		tmp[l] = S->tab[i][k++];
		++l;
	}
	if (ft_atoi(tmp) > 21474)
		return (ft_error(NULL, NULL, "Error"));
	if (S->tab[i][0] == '-' ? ft_atoi(S->tab[i] + 6) > 83648 :
		ft_atoi(S->tab[i] + 5) > 83647)
		return (ft_error(NULL, NULL, "Error"));
	return (0);
}

static int			ft_unvalid(int i)
{
	int				j;

	j = 0;
	if (MP)
		j++;
	if (MP ? ft_strlen(S->tab[i]) > 11 : ft_strlen(S->tab[i]) > 10)
		return (ft_error(NULL, NULL, "Error"));
	else if (MP ? ft_strlen(S->tab[i]) == 11 : ft_strlen(S->tab[i]) == 10)
	{
		if ((verif_itoa(i)) == -1)
			return (-1);
	}
	while (S->tab[i][j])
	{
		if (!ft_isdigit(S->tab[i][j]))
			return (ft_error(NULL, NULL, "Error"));
		++j;
	}
	return (0);
}

int					ft_doublons(int i, char **tmp)
{
	int				l;

	l = 0;
	while (tmp[l])
	{
		if (!ft_strcmp(S->tab[i], tmp[l]))
			return (ft_error(NULL, NULL, "Error"));
		l++;
	}
	return (0);
}

int					verif_tab(void)
{
	int				i;
	int				k;
	char			**tmp;

	i = 0;
	if ((tmp = malloc(sizeof(char *) * (ft_nb_tab(S->tab) + 1))) == NULL)
		return (ft_error(NULL, NULL, "Malloc failed"));
	k = 0;
	while (k <= ft_nb_tab(S->tab))
	{
		tmp[k] = NULL;
		++k;
	}
	while (S->tab[i])
	{
		if ((ft_doublons(i, tmp)) == -1)
			return (-1);
		if ((ft_unvalid(i)) == -1)
			return (-1);
		tmp[i] = ft_strdup(S->tab[i]);
		++i;
	}
	return (0);
}
