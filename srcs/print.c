/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argirin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:45:27 by argirin           #+#    #+#             */
/*   Updated: 2017/05/20 11:45:29 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	*aff_room(t_list **room, int maillon)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *room;
	while (tmp != NULL && ++i < maillon)
		tmp = tmp->next;
	return (tmp->content);
}

void	affichage(t_lemin *data, t_list **room)
{
	int i;
	int fourmi;

	fourmi = 1;
	ft_putendl("\n\n|=====| Affichage du Parcours |=====|");
	while (data->aff_ants[data->nb_ants] != data->len_tab)
	{
		i = 0;
		while (++i < fourmi)
		{
			if (data->aff_ants[i] != data->len_tab)
			{
				write(1, "L", 1);
				ft_putnbr(i);
				write(1, "-", 1);
				ft_putstr(aff_room(room, (data->best_way[data->aff_ants[i]])));
				write(1, " ", 1);
				data->aff_ants[i] += 1;
			}
		}
		write(1, "\n", 1);
		fourmi += (fourmi <= data->nb_ants) ? 1 : 0;
	}
}

void	print_course(t_list **room, t_lemin *data)
{
	long long i;

	i = data->nb_ants;
	if (!(data->aff_ants = (int*)ft_memalloc(sizeof(int) *
							(data->nb_ants + 1))))
		return ;
	if (!data->best_way)
		return ;
	while (i >= 0)
	{
		data->aff_ants[i] = 1;
		i--;
	}
	affichage(data, room);
}

int		print_best_way(t_list **room, t_lemin *data)
{
	int		count;
	t_list	*tmp;

	tmp = *room;
	if (!tmp || !data->affichage || data->affichage[0] != data->end - 1)
		return (1);
	ft_putendl("\n|=====| Meilleur Chemin |=====|\n");
	while (--data->nb_rooms >= 0)
	{
		count = 0;
		tmp = *room;
		while (tmp != NULL)
		{
			if (data->affichage[data->nb_rooms] > 0 &&
				count + 1 == data->affichage[data->nb_rooms])
			{
				ft_putstr(tmp->content);
				if (count + 1 != data->end - 1)
					ft_putstr(" -> ");
			}
			count++;
			tmp = tmp->next;
		}
	}
	return (0);
}
