/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerft_select.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:01:46 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/12 14:06:31 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFT_SELECT_H
# define HEADERFT_SELECT_H

# include "Libft/libft.h"
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define USAGE "usage: ft_select [name ...]"

# define UNKNOW_TERM  1
# define NO_ARG       2
# define GET_ATTR     3
# define GET_STR      4
# define SET_ATTR     5
# define GET_STR_BACK 6

#define SPACE_ELEM 2

typedef struct		s_infos
{
	struct winsize	ws;
	int		nb_elem;
	int		max_size_elem;
	int		max_size_all;
	int		nb_per_line;
}					t_infos;

typedef struct		s_elem
{
	char			*name;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

int				error_ft_select(int error_code, char *str);

void			init_term(struct termios *term);
void			set_back_term(void);

void			putchar_select(char c);

struct s_elem	*parse_entry(int argc, char **argv);

void			calculs(struct s_elem *entries, struct s_infos *infos);
void			calculs_elem_size(struct s_elem *entries, struct s_infos *infos);

int				print(struct s_elem *entries);

void			send(struct s_elem *entries);

#endif
