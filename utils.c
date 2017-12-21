/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:08:50 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/21 15:59:50 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		select_exit(t_elem *entries)
{
	while (entries->next != NULL)
	{
		entries = entries->next;
		entries->prev = ft_free(entries->prev);
	}
	if (entries->prev != NULL)
		entries->prev = ft_free(entries->prev);
	entries = ft_free(entries);
	exit(0);
}

void		putchar_select(char c)
{
	write(2, &c, 1);
}
