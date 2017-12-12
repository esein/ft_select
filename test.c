/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:19:30 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/12 14:15:55 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*tname;
	char	*put;
	char	c[4] =  {0, 0, 0, 0};
	char	fleche[3] = {27, 91, 67};
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
//	term.c_lflag &= ~ISIG;
//	cfmakeraw(&term);
	if (tcsetattr(0, 0, &term) < 0)
		error_ft_select(SET_ATTR, NULL);
	if (!(put = tgetstr("ti", NULL)))
		error_ft_select(GET_STR, "ti");
	tputs(put, 0, (void*)&putchar_select);
	if (!(put = tgetstr("vi", NULL)))
		error_ft_select(GET_STR, "vi");
	tputs(put, 0, (void*)&putchar_select);
//	if (!(put = tgetstr("so", NULL)))
//		error_ft_select(GET_STR, "cl");
//	tputs(put, 0, (void*)&putchar_select);
	entries = parse_entry(argc, argv);
	while (entries != NULL)
	{
		ft_putstr(entries->name);
		entries = entries->next;
	}
	int fd;
//	if ((fd = open("/dev/tty", O_WRONLY)) < 0)
//		ft_putstr("nop");
	while (read(0, &c, 4))
	{
		if (c[0] == '\033' && c[1] == 0)
			break;
		if (memcmp(c, U_ARROW, 3) == 0)
			ft_putstr_fd("lol", 0);
/*			ft_putnbr(c[0]);
			ft_putchar(' ');
			ft_putnbr(c[1]);
			ft_putchar(' ');
			ft_putnbr(c[2]);
			ft_putchar(' ');
			ft_putnbr(c[3]);
			ft_putchar(10);
//			ft_putchar('\n');
//			ft_putchar_fd(c, 2);
//			ft_putchar('\n');
		write(2, &c, 4);
		ft_putchar(10);
	//	write(2, "\033[C", 3);*/
		ft_bzero(c, 4);
	}
//	if (!(put = tgetstr("cl", NULL)))
//		error_ft_select(GET_STR, "cl");
//	tputs(put, 0, (void*)&putchar_select);
//	set_back_term();
	if (!(put = tgetstr("ve", NULL)))
		error_ft_select(GET_STR, "ve");
	tputs(put, 0, (void*)&putchar_select);
	if (!(put = tgetstr("te", NULL)))
		error_ft_select(GET_STR, "te");
	tputs(put, 0, (void*)&putchar_select);
	if (tcsetattr(0, 0, &old_config) < 0)
		error_ft_select(SET_ATTR, NULL);
	ft_putstr("return");
	return (0);
}
