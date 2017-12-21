/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:56:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/21 16:10:15 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void	handle_int(void)
{
	extern t_elem	*g_elem;

	set_back_term();
	signal(SIGINT, SIG_DFL);
	select_exit(g_elem);
}

void	handle_resize(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;

	if (reload_size(g_elem, g_infos) == 1)
		print(g_elem, g_infos);
}

void	handle_ctrlz(void)
{
	set_back_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
	tputs(tgetstr("dl", NULL), 0, (void*)putchar_select);
}

void	handle_fg(void)
{
	extern t_elem	*g_elem;
	extern t_infos	*g_infos;
	struct termios	term;

	init_term(&term);
	if (reload_size(g_elem, g_infos) == 1)
		print(g_elem, g_infos);
	signal(SIGTSTP, (void*)handle_ctrlz);
}

void	handle_signal(void)
{
	signal(SIGTSTP, (void*)handle_ctrlz);
	signal(SIGCONT, (void*)handle_fg);
	signal(SIGINT, (void*)handle_int);
	signal(SIGWINCH, (void*)handle_resize);
}
