/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:11:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/21 11:39:39 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <unistd.h>
# include <stdlib.h>

/*
** # include <stdio.h>
** # include <string.h>
*/

/*
** Bonus Headers
*/

# include <sys/ioctl.h>
# include <termcap.h>

# define DEBUG_TIME_TO_WAIT 60000
# define UINT size_t

typedef	int	t_bool;
# define TRUE 1
# define FALSE 0

/*
** Idees bonus, 	-t : time ms
** 					-b : type d'affichage, bar ou nombres
*/

/*
** COLORS
*/

# define NORMAL "\e[0m"
# define BOLD "\e[1m"

# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define CYAN "\e[1;36m"

typedef struct	s_val
{
	int			*a;
	int			*b;
	size_t		size_a;
	size_t		size_b;

	int			print_output;
	int			bonus_visualize;
	int			bonus_last_change;
	int			display_bar;

	int			nb_operation;
}				t_val;

/*
** SWAP
**
** Swap les 2 premières valeurs des piles
*/

int				sa(t_val *val);
int				sb(t_val *val);
int				ss(t_val *val);

/*
** PUSH
**
** Push first value to top of a or top of b
*/

int				pa(t_val *val);
int				pb(t_val *val);

/*
** ROTATE
**
** Décale toutes les positions de A || B de 1 vers le haut
** Le premier élément devient le dernier
*/

int				ra(t_val *val);
int				rb(t_val *val);
int				rr(t_val *val);

/*
** REVERSE ROTATE
**
** rotate inversé
** le dernier élément devient le premier
*/

int				rra(t_val *val);
int				rrb(t_val *val);
int				rrr(t_val *val);

/*
** Init
*/

t_val			*init_param(int argc, char **argv);
int				is_bonus_flag(const char *str);
int				is_valid_arg(const char *str);
int				has_doublon(char **tab);
/*
** Utils
*/

int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				print_error(const char *str, int error);
int				free_val(t_val *val);
void			*free_tab(char **tab, void *ret);
int				ft_strcmp(const char *s1, const char *s2);
int				heap_solved(t_val *val);
int				ft_isdigit(int c);
char			**parse_arg(int argc, char **argv);
char			*ft_strdup(const char *s1);
void			print_output(t_val *val, const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(const char *str, int fd);
char			*ft_itoa(int n);
long long		ft_atoull(const char *str);

/*
** TAB Utils
*/

int				*ft_move_tab_down(int *tab, size_t *size);
int				*ft_move_tab_up(int *tab, size_t *size);
size_t			ft_tablen(const int *str);
size_t			ft_ctablen(char **tab);
int				*ft_realloc_int(int *tab, int new_size, int size);
size_t			ft_fulltablen(char **tab);
void			print_tab(char **tab);

/*
** SORT
*/

int				*ft_select_sort(int *nbr, size_t size);

#endif
