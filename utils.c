/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:08:50 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/22 17:22:20 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

t_elem		*free_all(t_elem *entries)
{
	if (entries == NULL)
		return (NULL);
	while (entries->next != NULL)
	{
		entries = entries->next;
		entries->prev = ft_free(entries->prev);
	}
	if (entries->prev != NULL)
		entries->prev = ft_free(entries->prev);
	return (entries = ft_free(entries));
}

void		select_exit(t_elem *entries)
{
	free_all(entries);
	exit(0);
}

void		putchar_select(char c)
{
	write(2, &c, 1);
}
