/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:10:11 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/21 18:07:47 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

int			reload_size(t_elem *entries, t_infos *infos)
{
	if (entries == NULL)
		error_ft_select(CODING_BUG, "reload_size");
	if (tputs(tgetstr("cl", NULL), 0, (void*)&putchar_select))
		error_ft_select(GET_STR, "cl");
	if (calculs_win(infos) != 0)
		return (0);
	return (1);
}

void		init_term(struct termios *term)
{
	char	*name;

	if (!(name = getenv("TERM")))
		error_ft_select(UNKNOW_TERM, "check TERM env variable");
	if (!(tgetent(NULL, getenv("TERM"))))
		error_ft_select(UNKNOW_TERM, "try another one");
	if (tcgetattr(STDIN_FILENO, term) < 0)
		error_ft_select(GET_ATTR, "init_term");
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	if (tcsetattr(STDIN_FILENO, 0, term) < 0)
		error_ft_select(SET_ATTR, "init_term");
	if (tputs(tgetstr("ti", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR, "ti");
	if (tputs(tgetstr("vi", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR, "vi");
}

void		set_back_term(void)
{
	struct termios term;

	if (tputs(tgetstr("te", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR_BACK, "te");
	if (tputs(tgetstr("ve", NULL), 0, (void*)putchar_select) == ERR)
		error_ft_select(GET_STR_BACK, "ve");
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		error_ft_select(GET_ATTR, "set_back_term");
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	if (tcsetattr(STDIN_FILENO, 0, &term) < 0)
		error_ft_select(SET_ATTR, "set_back_term");
}
