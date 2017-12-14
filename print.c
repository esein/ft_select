/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:25:01 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/14 19:18:14 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		print_name(t_elem *elem)
{
	/*
	 * faire un check pour les couleurs ici
	*/
	if (elem->cursor_on == 1)
	{
	// mettre le tput aui correspond
	}
	if (elem->selected == 1)
	{
	// mettre le tput aui correspond
	}
	ft_putstr_fd(elem->name, 0);
}

int			print(struct s_elem *elem, struct s_infos *infos)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (elem != NULL)
	{
		if (x >= infos->nb_per_line)
		{
			write(0, "\n", 1);
			x = 0;
			y++;
		}
		print_name(elem);
		ft_putchar_nb_fd(0, ' ',
				(infos->max_size_elem - elem->name_len + SPACE_ELEM));
		x++;
		elem = elem->next;
	}
	return (0);
}
