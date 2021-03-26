/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:04:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:34:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "core.h"

# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_CHECKER_READ_INPUT 0

# define SUCCESS GREEN
# define FAILURE RED

# define MIN_TERM_X 54
# define MIN_TERM_Y 16

# define BAR_MAX 30
# define BAR_MIN 1

# define HEADER "- HEAP A -\t- HEAP B -"

/*
** CHECKER FUNCTIONS
*/

int				read_input(t_val *val);
int				get_operation(const char *str);
void			init_array(int (*operations[11])(t_val *val, t_bool print));

/*
** BONUS PART
*/

typedef	struct	s_term
{
	size_t		term_x;
	size_t		term_y;
}				t_term;

/*
** Usage :
** (t_range){value, old_min, old_max, new_min, new_max},
*/

typedef struct	s_range
{
	int			value;
	int			old_min;
	int			old_max;
	int			new_min;
	int			new_max;
}				t_range;

/*
** PREVISUALISATION / UTILS
*/

void			gotoxy(int x, int y);
void			clear_screen(void);
int				init_term(t_term *term);
void			join_static_str(char str[], char *add);
void			reset_static_str(char str[], UINT size);

/*
** LAST ACTIONS
*/

void			update_last_action_heap_a(t_val *val, int action, int i);
void			update_last_color_action_heap_a(t_val *val, int action, int i);
void			update_last_action_heap_b(t_val *val, int action, int i);
void			update_last_color_action_heap_b(t_val *val, int action, int i);
void			update_last_text(t_val *val, int action);

/*
** VISUAL UTILS BARS
*/

int				map_range_clamped(t_range range);
void			select_color(int size);

/*
** VISUAL / DEBUG - BONUS
*/

void			preview_heaps(t_val *val, t_term term, int action);
void			preview_bar(t_val *val, t_term term, int action);
void			print_heap(int *h, size_t size);
void			print_heaps(t_val *val);
int				update_visualisation(t_val *val, int action);

/*
** VISUAL USEFULL FUNCTIONS
*/

void			v_draw_str(char c, UINT n, t_bool newline);
UINT			v_get_left_position(t_term term, char *str, UINT decal);
UINT			v_get_right_position(t_term term, char *str, UINT decal);
UINT			v_get_center_position(t_term term, char *str, UINT decal);
UINT			v_get_special_position(UINT decal);

#endif
