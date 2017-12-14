/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:11:24 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/14 19:13:40 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

static t_elem		*find_cursor(t_elem *elem)
{
	while (elem != NULL)
	{
		if (elem->cursor_on == 1)
			return (elem);
		elem = elem->next;
	}
	error_ft_select(CODING_BUG, "find_cursor");
	return (NULL);
}

void		move_cursor_right(t_elem *elem)
{
		if (elem->next != NULL)
		{
			elem->cursor_on = 0;
			elem->next->cursor_on = 1;
		}
}

void	move_cursor(t_elem *elem, char c)
{
	t_elem *tmp;

	tmp = find_cursor(elem);
	if (c == 67)
		move_cursor_right(elem);
}
