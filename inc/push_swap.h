/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:10:33 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/18 06:15:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			PUSH_SWAP
# define		PUSH_SWAP

# include "libft.h"

#define S (singleton())
#define MP S->tab[i][0] == '-' || S->tab[i][0] == '+'

typedef struct		s_lst	t_lst;

typedef struct		s_swap
{
	int				min;
	char			*oper;
	char			**tab;
	t_lst			*lst;
 	t_lst			*first; 
  	t_lst			*last; 
	t_lst			*lb;
 	t_lst			*first_b; 
  	t_lst			*lb_last;
  	t_lst			*lv;
  	t_lst			*move;
 }					t_swap;

struct s_lst
{
	int				nb;
	t_lst			*next;
 	t_lst			*prev;

};

t_swap				*singleton(void);
int					verif_tab(void);

void				add_link(void);
void				print_list(void);

void				ft_sa(void);
void				ft_sb(void);
void				ft_ss(void);
void				ft_pa(void);
void				ft_pb(void);
void				ft_ra(void);
void				ft_rb(void);
void				ft_rr(void);
void				ft_rra(void);
void				ft_rrb(void);
void				ft_rrr(void);

void				ft_check_pa(void);
void				ft_get_min(void);
int					ft_resolve(void);
int					check_solved(void);		

#endif
