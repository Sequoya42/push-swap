/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:43:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/23 06:03:41 by rbaum            ###   ########.fr       */
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
	if (S->tab[i][0] == '0' && S->tab[i][1] != '\0')
		return (ft_error(NULL, NULL, "Error"));
	while (S->tab[i][j])
	{
		if (!ft_isdigit(S->tab[i][j]))
			return (ft_error(NULL, NULL, "Error"));
		++j;
	}
	return (0);
}

static int			ft_doublons(int i, char **tmp)
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
	ft_clear_tab(&tmp);
	return (0);
}
