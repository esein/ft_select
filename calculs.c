/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:52:33 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/12 14:15:54 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		calculs_elem_size(t_elem *elem, t_infos *infos)
{
	int		x;

	while (elem != NULL)
	{
		infos->nb_elem++;
		x = ft_strlen(elem->name);
		if (infos->max_size_elem > x)
			infos->max_size_elem = x;
		infos->max_size_all += x;
		elem = elem->next;
	}
}
void		calculs_win(t_infos *infos)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, infos->ws);
	infos->nb_per_line = infos->ws.col / 
}

void		calculs(t_elem *entries, t_infos *infos)
{
	calculs_elem_size(entries, infos);
	calculs_win(infos);
}
