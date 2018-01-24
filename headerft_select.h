/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerft_select.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:01:46 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/22 16:39:23 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFT_SELECT_H
# define HEADERFT_SELECT_H

# include "Libft/libft.h"
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# define USAGE "usage: ft_select [name ...]"

/*
** Error Codes
*/
# define UNKNOW_TERM  1
# define NO_ARG       2
# define GET_ATTR     3
# define GET_STR      4
# define SET_ATTR     5
# define IOCTL_FAIL   6
# define GET_STR_BACK 7
# define NO_SIZE      8
# define CODING_BUG   9
# define C_FT_BUG    10

# define SPACE_ELEM    2

/*
** 3rd bit Arrow value (c[2])
*/
# define UP_CHAR      65
# define DOWN_CHAR    66
# define RIGHT_CHAR   67
# define LEFT_CHAR    68

# define SELECT_CHAR(c) (c == ' ' || c == 'a' || c == 'u' || c == 'w')

typedef struct		s_infos
{
	struct winsize	ws;
	int				nb_elem;
	int				max_size_elem;
	int				max_size_all;
	int				nb_per_line;
	int				nb_line;
}					t_infos;

typedef struct		s_elem
{
	char			*name;
	int				name_len;
	int				selected;
	int				cursor_on;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

int					error_ft_select(int error_code, char *str);

void				handle_signal(void);
void				handle_resize(void);

void				putchar_select(char c);

void				select_exit(t_elem *entries);

int					reload_size(t_elem *entries, t_infos *infos);

void				init_term(struct termios *term);
void				set_back_term(void);

struct s_elem		*parse_entry(int argc, char **argv);
struct s_elem		*del_elem(t_elem *entries);
struct s_elem		*del_selected(t_elem *entries);

int					calculs_win(struct s_infos *infos);
void				calculs_elem_size(t_elem *entries, struct s_infos *infos);
int					calculs(struct s_elem *entries, struct s_infos *infos);

int					move_cursor(t_elem *elem, t_infos *infos, char c);
void				move_right(t_elem *elem);
void				move_left(t_elem *elem);

int					select_elem(t_elem *elem, char c);

int					print(struct s_elem *entries, struct s_infos *infos);

void				send(struct s_elem *entries);

struct s_elem		*free_all(t_elem *entries);

#endif
