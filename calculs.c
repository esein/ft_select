/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:52:33 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/20 16:55:56 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		init_infos(t_infos *infos)
{
	infos->nb_elem = 0;
	infos->max_size_elem = 0;
	infos->max_size_all = 0;
	infos->nb_per_line = 0;
	infos->nb_line = 0;
}

void		calculs_elem_size(t_elem *elem, t_infos *infos)
{
	while (elem != NULL)
	{
		infos->nb_elem++;
		if (infos->max_size_elem < elem->name_len)
			infos->max_size_elem = elem->name_len;
		infos->max_size_all += elem->name_len;
		elem = elem->next;
	}
}
int			calculs_win(t_infos *infos)
{
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &(infos->ws)) < 0)
		return (error_ft_select(IOCTL_FAIL, "calculs_win"));
	if (infos->ws.ws_col < (infos->max_size_elem + SPACE_ELEM))
		return (error_ft_select(NO_SIZE, NULL));
	else
	{
		infos->nb_per_line =
						infos->ws.ws_col / (infos->max_size_elem + SPACE_ELEM);
		infos->nb_line = infos->nb_elem / infos->nb_per_line;
		if (infos->ws.ws_row < (infos->nb_line + SPACE_ELEM))
			return (error_ft_select(NO_SIZE, NULL));
	}
	return (0);
}

int			calculs(t_elem *entries, t_infos *infos)
{
	init_infos(infos);
	calculs_elem_size(entries, infos);
	if (calculs_win(infos) != 0)
		return (NO_SIZE);
	return (0);
}
