/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:17:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/15 23:44:41 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		select_current(t_elem *elem)
{
	if (elem->selected == 1)
		elem->selected = 0;
	else
		elem->selected = 1;
	move_right(elem);
}

void		select_all(t_elem *elem)
{
	while (elem != NULL)
	{
		elem->selected = 1;
		elem = elem->next;
	}
}

void		unselect_all(t_elem *elem)
{
	while (elem != NULL)
	{
		elem->selected = 0;
		elem = elem->next;
	}
}

void		select_group(t_elem *elem, t_elem *first)
{
	first = elem;
	while (elem != NULL)
	{
		if (elem->selected == 1)
		{
			while (elem != first)
			{
				elem->selected = 1;
				elem = elem->next;
			}
			elem->selected = 1;
			break;
		}
		elem = elem->prev;
	}
}

int		select_elem(t_elem *elem, char c)
{
	t_elem *first;

	first = elem;
	while (elem != NULL)
	{
		if (elem->cursor_on == 1)
			break;
		elem = elem->next;
	}
	if (elem == NULL)
		error_ft_select(CODING_BUG, "select_elem");
	if (c == ' ')
		select_current(elem);
	if (c == 'a')
		select_all(first);
	if (c == 'u')
		unselect_all(first);
	if (c == 'w')
		select_group(elem, first);
	return (1);
}
