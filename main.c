/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:19:30 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/02 22:18:09 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

int		main(int argc, char **argv)
{
	char	*tname;
	char	*put;
	char	c;
	struct termios old_term;
	struct termios term;
	struct s_elem	*entries;

	if (!(tname = getenv("TERM")))
		error_ft_select(UNKNOW_TERM, NULL);
	if (!tgetent(NULL, tname))
		error_ft_select(UNKNOW_TERM, NULL);
	if (tcgetattr(0, &old_term) < 0 || tcgetattr(STDIN_FILENO, &term) < 0)
		error_ft_select(GET_ATTR, NULL);
	ft_putnbr(term.c_cc[VERASE]);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	if (tcsetattr(0, 0, &term) < 0)
		error_ft_select(SET_ATTR, NULL);
	if (!(put = tgetstr("cl", NULL)))
		error_ft_select(GET_STR, "cl");
	tputs(put, 0, (void*)&ft_putchar);
	while (read(0, &c, 1) != 0 && c != '\n');
	entries = parse_entry(argc, argv);
	while (entries != NULL)
	{
		ft_putstr(entries->name);
		entries = entries->next;
	}
	if (tcsetattr(0, 0, &old_term) < 0)
		error_ft_select(SET_ATTR, " back");
	return (0);
}
