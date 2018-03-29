/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argirin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:37:28 by argirin           #+#    #+#             */
/*   Updated: 2017/05/20 11:37:31 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		error(void)
{
	ft_putendl("ERROR");
	return (-1);
}

void	init_data(t_lemin *data)
{
	data->a = 0;
	data->b = 0;
	data->end = 0;
	data->start = 0;
	data->error = 0;
	data->nb_ants = 0;
	data->nb_rooms = 1;
	data->len_tab = 0;
}

int		main(void)
{
	t_lemin	data;
	t_list	*room;

	room = NULL;
	init_data(&data);
	if (get_infos(&data, &room) == -1 || data.links == 0 || data.start == 0 ||
		data.end == 0 || !solve(&data) || print_best_way(&room, &data))
		return (error());
	print_course(&room, &data);
	return (0);
}
