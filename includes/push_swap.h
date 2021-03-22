/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:58:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/22 16:27:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "core.h"

int				solve_heap(t_val *val);

/*
** ALGOS
*/

int				case_three(t_val *val);
int				algo_02(t_val *val);
int				algo_03(t_val *val);
int				swap_sort(t_val *val);

/*
****************
** ALGO UTILS **
****************
*/

/*
** CHUNK SORT UTILS
*/

int				select_rotation(int *h, int value, UINT size);
int				min_or_max_is_nearest(int *h, UINT size);
int				get_max_value(int *h, UINT size);
int				get_min_value(int *h, UINT size);

typedef struct	s_median
{
	int			median;
	size_t		i;
	int			j;
	int			a;
	int			b;
	int			key;
}				t_median;

int				get_heap_median(int *h, UINT size);
int				has_number_inferior_median(int *h, int median, UINT size);

typedef struct	s_cs
{
	int			max;
	int			min;
	int			min_or_max;
	int			value;
	int			rotation;
}				t_cs;

int				step_02(t_val *val);

void			step_02_apply_change(t_val *val, t_cs *cs, int *nb_top_nbr);
int				step_02_loop(t_val *val, int *nb_top_nbr);
int				step_02_rotate_heap(t_val *val,
int nb_top_nbr, int default_size);

/*
** SIMPLE SORT UTILS
*/

int				is_max_value(int *tab, int size);
int				is_min_value(int *tab, int size);
int				min_r(int *tab, int size, int value);
int				min_rr(int *tab, int size, int value);
int				is_next_min_value(int *tab, int size);

typedef struct	s_ss
{
	int			max;
	int			min;
	int			next_min;
	int			min_found;
	int			swap_b;
}				t_ss;

/*
** HUNTER ALGO (My Sort Algorithm)
*/

typedef struct	s_hchunk
{
	int			value;
	t_bool		result;
}				t_hckunk;

typedef struct	s_chunk
{
	int			**range;
	UINT		nb_chunks;
}				t_chunk;

typedef struct	s_poids
{
	int			nbr;
	UINT		poids;
}				t_poids;

typedef struct	s_hunter
{
	t_poids		*a;
	UINT		size_a;
	t_poids		*b;
	UINT		size_b;
}				t_hunter;

int	hunter_algo(t_val *val);

#endif
