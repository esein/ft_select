/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:17:26 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/14 19:13:46 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

void		handle_signal(void)
{
	
}

void		send(struct s_elem *elem)
{
	while (elem != NULL)
	{
		ft_putchar(' ');
		ft_putstr(elem->name);
		elem = elem->next;
	}
}

void		reload_size(t_elem *entries, t_infos *infos)
{
	if (tputs(tgetstr("cl", NULL), 0, (void*)&putchar_select))
		error_ft_select(GET_STR, "cl");
	if (calculs_win(infos) == 0)
		print(entries, infos);
}

void		ft_select_loop(t_elem *elem, t_infos *infos)
{
	char				c[4] = {0, 0, 0, 0};

	while (read(0, &c, 4))
	{
		if (c[0] == '\033' && c[1] == 0)
			break;
		if (c[0] == 114 && c[1] == 0)
			reload_size(elem, infos);
		if (c[0] == 27 && c[1] == 91)
			move_cursor(elem, c[2]);
/*		ft_putnbr(c[0]);
		ft_putchar('\n');
		ft_putnbr(c[1]);
		ft_putchar('\n');
		ft_putnbr(c[2]);*/
		ft_bzero(c, 4);
	}
}

int			main(int argc, char **argv)
{
	struct termios		term;
	struct s_elem		*entries;
	struct s_infos		infos;

	if (argc < 2)
		return (error_ft_select(NO_ARG, USAGE));
	handle_signal();
	entries = parse_entry(argc, argv);
	init_term(&term);
	if (calculs(entries, &infos) == 0)
		print(entries, &infos);
	ft_select_loop(entries, &infos);
	set_back_term();
	send(entries);
/*	ft_putnbr(infos.ws.ws_col);
	ft_putchar(' ');
	ft_putnbr(infos.nb_per_line);
	ft_putchar(' ');
	ft_putnbr(infos.ws.ws_row);
	ft_putchar(' ');
	ft_putnbr(infos.nb_line);
	ft_putchar(' ');
	ft_putnbr(infos.nb_elem);*/
	return (0);
}
