/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:56:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/18 20:06:14 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void	handle_resize(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;

	if (reload_size(g_elem, g_infos) == 1)
	{
		print(g_elem, g_infos);
	//	ft_putst("lol");
	}
}

void	handle_fg(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;

	if (reload_size(g_elem, g_infos) == 1)
		print(g_elem, g_infos);
}

void	handle_ctrlz(void)
{
	set_back_term();
}

void	handle_signal(void)
{
	signal(SIGTSTP, (void*)handle_ctrlz);
	signal(SIGCONT, (void*)handle_fg);
	signal(SIGWINCH, (void*)handle_resize);
}
