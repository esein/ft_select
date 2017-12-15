/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:17:26 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/16 00:02:14 by gcadiou          ###   ########.fr       */
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
		if (elem->selected == 1)
		{
			ft_putstr(elem->name);
			ft_putchar(' ');
		}
		elem = elem->next;
	}
}

int		reload_size(t_elem *entries, t_infos *infos)
{
	if (entries == NULL)
		error_ft_select(CODING_BUG, "lol");
	if (tputs(tgetstr("cl", NULL), 0, (void*)&putchar_select))
		error_ft_select(GET_STR, "cl");
	if (calculs_win(infos) != 0)
		return (0);
	return (1);
}

int			ft_select_loop(t_elem *elem, t_infos *infos)
{
	char				c[4] = {0, 0, 0, 0};
	char				x;

	while (read(0, &c, 4))
	{
		x = 0;
		if (c[0] == '\033' && c[1] == 0)
			return (0);
		if (c[0] == 10 && c[1] == 0)
			return (1);
		if (c[0] == 114 && c[1] == 0)
			if (reload_size(elem, infos) == 1)
				x = 2;
		if (c[0] == 27 && c[1] == 91)
			x = move_cursor(elem, infos, c[2]);
		if (SELECT_CHAR(c[0]) && c[1] == 0)
			x = select_elem(elem, c[0]);
		if (x == 3)
			calculs(elem, infos);
		if (x == 2)
			calculs_win(infos);
		if (x > 0)
			print(elem, infos);
		/*
		ft_putnbr(c[0]);
		ft_putchar('\n');
		ft_putnbr(c[1]);
		ft_putchar('\n');
		ft_putnbr(c[2]);
		*/
		ft_bzero(c, 4);
	}
	return (1);
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
	if (ft_select_loop(entries, &infos) == 1)
	{
		set_back_term();
		send(entries);
	}
	else
		set_back_term();
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
