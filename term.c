/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:10:11 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/11 15:28:55 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

int			init_term(struct termios *term)
{
	if (!(tname = getenv("TERM")))
		error_ft_select(UNKNOW_TERM, NULL);
	return (0);
}

void			set_back_term(void)
{
	struct termios term;

	if (tcgetattr(STDIN_FILENO, &term) < 0)
		error_ft_select(GET_ATTR, NULL);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	if (tcsetattr(STDIN_FILENO, 0, &term) < 0)
		error_ft_select(SET_ATTR, " back");
}
