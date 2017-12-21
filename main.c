/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:17:26 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/21 18:10:01 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

struct s_infos	*g_infos;
struct s_elem	*g_elem;

void				send(struct s_elem *elem)
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

struct s_elem		*key_actions(t_elem *elem, char *c, t_infos *infos, int *x)
{
	if (c[0] == 27 && c[1] == 91)
		*x = move_cursor(elem, infos, c[2]);
	if (SELECT_CHAR(c[0]) && c[1] == 0)
		*x = select_elem(elem, c[0]);
	if ((c[0] == 127 && c[1] == 0) || (ft_memcmp(c, DELETE, 4) == 0))
	{
		if ((elem = del_elem(elem)) == NULL)
			return (NULL);
		else
			*x = 3;
	}
	if (c[0] == 'd' && c[1] == 0)
	{
		if ((elem = del_selected(elem)) == NULL)
			return (NULL);
		else
			*x = 3;
	}
	return (elem);
}

struct s_elem		*ft_select_loop(t_elem *elem, t_infos *infos)
{
	char				c[4];
	int					x;

	ft_bzero(c, 4);
	while (read(0, &c, 4))
	{
		x = 0;
		if (c[0] == '\033' && c[1] == 0)
			return (NULL);
		if (c[0] == 10 && c[1] == 0)
			return (elem);
		if ((elem = key_actions(elem, c, infos, &x)) == NULL)
			return (NULL);
		if (x == 3)
			calculs(elem, infos);
		if (x == 2)
			calculs_win(infos);
		if (x > 0)
			print(elem, infos);
		ft_bzero(c, 4);
		g_infos = infos;
		g_elem = elem;
	}
	return (elem);
}

int					main(int argc, char **argv)
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
	g_infos = &infos;
	g_elem = entries;
	entries = ft_select_loop(entries, &infos);
	set_back_term();
	if (entries != NULL)
		send(entries);
	return (0);
}
