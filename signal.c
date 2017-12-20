/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:56:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/20 16:55:54 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void	handle_resize(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;

	if (reload_size(g_elem, g_infos) == 1)
		print(g_elem, g_infos);
}

void	handle_fg(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;
	struct termios	term;

	init_term(&term);
	if (reload_size(g_elem, g_infos) == 1)
		print(g_elem, g_infos);
//	signal(SIGTSTP, SIG_DFL);
}

void	handle_ctrlz(void)
{
//	ft_putstr("abc");
//	ioctl(0, TIOCSTI, "\n");
	set_back_term();
/*	if (tputs(tgetstr("te", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR_BACK, "te");
	if (tputs(tgetstr("ve", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR_BACK, "ve");*/
//	ft_putstr("fgh");
//	signal(SIGTSTP, SIG_DFL);
}

void	handle_signal(void)
{
	signal(SIGTSTP, (void*)handle_ctrlz);
	signal(SIGCONT, (void*)handle_fg);
	signal(SIGWINCH, (void*)handle_resize);
}
