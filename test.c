/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:19:30 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/07 06:02:37 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*tname;
	char	*put;
	char	c;
	struct termios old_config;
	struct termios term;
	struct s_elem	*entries;

	if (!(tname = getenv("TERM")))
		error_ft_select(UNKNOW_TERM, NULL);
	if (!tgetent(NULL, tname))
		error_ft_select(UNKNOW_TERM, NULL);
	if (tcgetattr(0, &old_config) < 0 || tcgetattr(STDIN_FILENO, &term) < 0)
		error_ft_select(GET_ATTR, NULL);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	if (tcsetattr(0, 0, &term) < 0)
		error_ft_select(SET_ATTR, NULL);
	if (!(put = tgetstr("cl", NULL)))
		error_ft_select(GET_STR, "cl");
	tputs(put, 0, (void*)&ft_putchar);
	entries = parse_entry(argc, argv);
	while (entries != NULL)
	{
		ft_putstr(entries->name);
		entries = entries->next;
	}
	int fd;
	if ((fd = open("/dev/tty", O_WRONLY)) < 0)
		ft_putstr("nop");
	while (read(0, &c, 1) != 0 && c != 127)
	{
		ft_putchar_fd(c, fd);
	}
	if (!(put = tgetstr("cl", NULL)))
		error_ft_select(GET_STR, "cl");
	tputs(put, 0, (void*)&ft_putchar);
	set_back_term();
	return (0);
}
