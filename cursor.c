/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:11:24 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/22 16:16:38 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		move_right(t_elem *elem)
{
	if (elem->next != NULL)
	{
		elem->cursor_on = 0;
		elem->next->cursor_on = 1;
	}
	else if (elem->prev != NULL)
	{
		elem->cursor_on = 0;
		while (elem->prev != NULL)
			elem = elem->prev;
		elem->cursor_on = 1;
	}
}

void		move_left(t_elem *elem)
{
	if (elem->prev != NULL)
	{
		elem->cursor_on = 0;
		elem->prev->cursor_on = 1;
	}
	else if (elem->next != NULL)
	{
		elem->cursor_on = 0;
		while (elem->next != NULL)
			elem = elem->next;
		elem->cursor_on = 1;
	}
}

int			move_down(t_elem *elem, t_infos *infos)
{
	int		x;
	t_elem	*tmp;

	x = 0;
	tmp = elem;
	if (infos->nb_line < 2)
		return (0);
	while (infos->nb_per_line > x)
	{
		if ((elem = elem->next) == NULL)
			return (0);
		x++;
	}
	tmp->cursor_on = 0;
	elem->cursor_on = 1;
	return (1);
}

int			move_up(t_elem *elem, t_infos *infos)
{
	int		x;
	t_elem	*tmp;

	x = 0;
	tmp = elem;
	if (infos->nb_line < 2)
		return (0);
	while (infos->nb_per_line > x)
	{
		if ((elem = elem->prev) == NULL)
			return (0);
		x++;
	}
	tmp->cursor_on = 0;
	elem->cursor_on = 1;
	return (1);
}

int			move_cursor(t_elem *elem, t_infos *infos, char c)
{
	if (elem->next == NULL && elem->prev == NULL)
		return (0);
	while (elem != NULL)
	{
		if (elem->cursor_on == 1)
			break ;
		elem = elem->next;
	}
	if (elem == NULL)
		error_ft_select(CODING_BUG, "move_cursor");
	if (c == RIGHT_CHAR)
		move_right(elem);
	if (c == LEFT_CHAR)
		move_left(elem);
	if (c == UP_CHAR)
		return (move_up(elem, infos));
	if (c == DOWN_CHAR)
		return (move_down(elem, infos));
	return (1);
}
