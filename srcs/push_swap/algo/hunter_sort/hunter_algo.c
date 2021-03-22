/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/22 16:48:41 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** DEBUG
*/

# include <stdio.h>

static void print_hunter(t_hunter *hunter, int print_a)
{
	int i;
	int mi;

	i = 0;
	mi = print_a ? hunter->size_a : hunter->size_b;
	while (i < mi)
	{
		printf("- [%d] : [%d] | POIDS [%ld]\n", i, print_a ? hunter->a[i].nbr : hunter->b[i].nbr, print_a ? hunter->a[i].poids : hunter->b[i].poids);
		++i;
	}
	printf(" - Hunter %s = [%ld]\n", print_a ? "HEAP A" : "HEAP B", print_a ? hunter->size_a : hunter->size_b);
}

/*
** UTILS
*/

static t_poids	get_nbr_poids(int *h, UINT size, int value)
{
	t_poids	poids;
	int		*sorted_tab;
	int		i;

	i = 0;
	sorted_tab = ft_select_sort(h, size);
	while (sorted_tab[i] != value && (UINT)i < size)
		++i;
	free(sorted_tab);
	poids.nbr = value;
	poids.poids = i;
	return (poids);
}

static int	init_hunter_sort(t_val *val, t_hunter *hunter)
{
	UINT	i;

	if (!(hunter->a = malloc(sizeof(t_poids) * (val->size_a + 1))))
		return (-1);
	if (!(hunter->b = malloc(sizeof(t_poids) * (val->size_b + 1))))
		return (-1);
	i = 0;
	while (i < val->size_a)
	{
		hunter->a[i] = get_nbr_poids(val->a, val->size_a, val->a[i]);
		++i;
	}
	hunter->size_a = val->size_a;
	i = 0;
	while (i < val->size_b)
	{
		hunter->b[i] = get_nbr_poids(val->b, val->size_b, val->b[i]);
		++i;
	}
	hunter->size_b = val->size_b;
	return (0);
}

static int free_hunter(t_hunter *hunter)
{
	free(hunter->a);
	free(hunter->b);
	return (0);
}

/*
** Sort Hunter !
*/

static int get_nearest_rounded_value(int nb)
{
	int result;
	int is_already_rounded;
	UINT nb_div;
	t_bool is_neg;

	if (nb < 0)
	{
		nb = -nb;
		is_neg = TRUE;
	}
	nb_div = 1;
	//printf("### Nearest rounded value ###\n");
	if (nb % 10)
		is_already_rounded = FALSE;
	else
		is_already_rounded = TRUE;
	//printf("is is_already_rounded = [%d]\n", is_already_rounded);
	while (nb > 9)
	{
		nb /= 10;
		nb_div *= 10;
	}
	//printf("NB Div = [%ld] | nb = [%d]\n", nb_div, nb);
	result = (nb * nb_div) + (is_already_rounded == FALSE ? 10 : 0);
	//printf("Result = [%d]\n", result);
	return (result * (is_neg ? -1 : 1));
}

static t_chunk init_chunks(t_val *val)
{
	int start_value;
	int i;
	int j;
	int min;
	int max;
	t_chunk chunk;

	min = get_min_value(val->a, val->size_a);
	start_value = get_nearest_rounded_value(min);
 	min = min < 0 ? -min : min;
	max = get_nearest_rounded_value(get_max_value(val->a, val->size_a));
	chunk.nb_chunks = (min + max) / 20;
	if (val->size_a % (min + max) != 0)
		++chunk.nb_chunks;
	if (chunk.nb_chunks <= 0)
		chunk.nb_chunks = 1;
	chunk.range = malloc(sizeof(int) * val->size_a + 1);

	printf("StartValue = [%d]\n", start_value);
	printf("NB Chunks [%ld]\n", chunk.nb_chunks);

	j = 0;
	while (j < (int)chunk.nb_chunks)
	{
		i = 0;
		chunk.range[j] = malloc(sizeof(int) * val->size_a + 1);
		printf("# Malloc Range [%d]\n", j);
		while (i < 20)
		{
			chunk.range[j][i] = start_value;
			printf("\t- Add range [%d]\n", chunk.range[j][i]);
			++i;
			++start_value;
		}
		chunk.range[j][i] = 0;
		++j;
	}
	chunk.range[j] = NULL;
	return (chunk);
}

static t_bool value_is_in_chunk(int value, int *range)
{
	int i;

	i = 0;
	while (range[i])
	{
		if (value == range[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

static int get_min_value_in_chunk(int *h, int *range)
{
	int min;
	int i;

	i = 0;
	min = h[0];
	while (h[i])
	{
		if (h[i] < min && value_is_in_chunk(h[i], range))
			min = h[i];
		++i;
	}
	return (min);
}

static t_hckunk get_first_value_in_heap_by_chunk_from_end(int *h, UINT size, int *range)
{
	UINT i;

	i = size - 1;
	while (i > 0)
	{
		if (value_is_in_chunk(h[i], range))
			return ((t_hckunk){h[i], TRUE});
		--i;
	}
	return ((t_hckunk){h[0], FALSE});
}

static t_hckunk get_first_value_in_heap_by_chunk_from_start(int *h, UINT size, int *range)
{
	UINT i;

	i = 0;
	while (i < size)
	{
		if (value_is_in_chunk(h[i], range))
			return ((t_hckunk){h[i], TRUE});
		++i;
	}
	return ((t_hckunk){h[0], FALSE});
}

static int get_nbr_pos_in_heap(int *h, UINT size, int value)
{
	UINT i;

	i = 0;
	while (i < size)
	{
		if (value == h[i])
			return (i);
		++i;
	}
	return (i);
}

static int get_nb_moves_to_first_position(UINT size, int pos)
{
	int med;
	int val;

	med = size / 2;
	if (pos > med)
		val = size - pos;
	else
		val = pos;
	return (val);
}


static int hunter_sort(t_val *val)
{
	t_chunk chunk;

	chunk = init_chunks(val);

	printf("### [%ld] Chunks ###\n", chunk.nb_chunks);
	for (size_t i = 0; i < chunk.nb_chunks; i++) {
		printf("# chunk [%ld] | Range : [", i);
		for (int j = 0; j < 20; j++) {
			printf("%d, ", chunk.range[i][j]);
		}
		printf("]\n");
	}

	printf("\n\n######################\n\n");

	while (val->size_a > 0)
	{

	int try = 0;
	t_hckunk hold_first = (t_hckunk){0, FALSE};
	t_hckunk hold_second = (t_hckunk){0, FALSE};

	while (hold_first.result == FALSE)
	{
		hold_first = get_first_value_in_heap_by_chunk_from_start(val->a, val->size_a, chunk.range[try]);
		++try;
	}
	try = 0;
	while (hold_second.result == FALSE)
	{
		hold_second = get_first_value_in_heap_by_chunk_from_end(val->a, val->size_a, chunk.range[try]);
		++try;
	}

	printf("Hold First = [%d]\n", hold_first.value);
	printf("Hold Second = [%d]\n", hold_second.value);

	int many_move_hf = get_nb_moves_to_first_position(val->size_a, get_nbr_pos_in_heap(val->a, val->size_a, hold_first.value));
	int many_move_hs = get_nb_moves_to_first_position(val->size_a, get_nbr_pos_in_heap(val->a, val->size_a, hold_second.value));

	printf("NMoves HF [%d]\n", many_move_hf);
	printf("NMoves HS [%d]\n", many_move_hs);

		if (val->a[0] == hold_first.value || val->a[0] == hold_second.value)
			pb(val);
		if (val->b[0] < val->b[1])
			sb(val);
		if (many_move_hf < many_move_hs)
			ra(val);
		else
			rra(val);
	}
	while (val->size_b > 0)
		pa(val);
	return (0);
}


/*
** HunterFunction Called
*/

int	hunter_algo(t_val *val)
{

	// a faire si medium est pas ouf
	//t_hunter hunter;

	//init_hunter_sort(val, &hunter);
	//print_hunter(&hunter, TRUE);
	//print_hunter(&hunter, FALSE);

	// medium part

	hunter_sort(val);










	//free_hunter(&hunter);
	return (0);
}
