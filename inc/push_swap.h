/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:10:33 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 06:10:19 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define S (singleton())
# define MP S->tab[i][0] == '-' || S->tab[i][0] == '+'

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_lst	t_lst;
typedef struct s_oper	t_oper;

typedef struct			s_swap
{
	int					min;
	int					nepa;
	int					count;
	int					flag[5];
	char				**tab;
	t_oper				*oper;
	t_oper				*last_oper;
	t_lst				*lst;
	t_lst				*first;
	t_lst				*last;
	t_lst				*lb;
	t_lst				*first_b;
	t_lst				*lb_last;
	t_lst				*move;
}						t_swap;

struct					s_oper
{
	char				*s;
	t_oper				*next;
};

struct					s_lst
{
	int					nb;
	t_lst				*next;
	t_lst				*prev;

};

t_swap					*singleton(void);
int						verif_tab(void);

void					add_link(void);
void					add_oper(char *s);
void					print_list(void);

void					ft_sa(void);
void					ft_sb(void);
void					ft_ss(void);
void					ft_pa(void);
void					ft_pb(void);
void					ft_ra(void);
void					ft_rb(void);
void					ft_rr(void);
void					ft_rra(void);
void					ft_rrb(void);
void					ft_rrr(void);

void					ft_check_pb(void);

void					ft_get_min(void);
void					print_step(void);

int						ft_resolve(void);
int						ft_check_pa(void);
int						check_solved(void);
int						ft_check_rev(void);

#endif
