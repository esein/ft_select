/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:21:35 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/07 04:03:11 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

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
