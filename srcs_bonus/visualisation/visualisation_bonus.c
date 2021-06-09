/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:49:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:46:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PREVIEW_BAR 0

# include "../includes/core.h"
# include <sys/ioctl.h>
# include <termcap.h>
# include <stdio.h>

void preview_text(t_val *val)
{
    usleep(DEBUG_TIME_TO_WAIT);
    static int nb_coups = 0;
    static int mi = 0;
    if (mi == 0)
        mi = val->size_a;
    int i;

    i = 0;
    system("clear");
    //usleep(50);
    printf(CYAN BOLD);
    for (size_t i = 0; i < 54; i++) {
        printf("#");
    }
    printf(RED);
    printf("\n\t- HEAP A -\t\t- HEAP B -\n");
    printf("\n");
    printf(GREEN);
    while (i < mi)
    {
        printf("\t    %d\t\t\t    %d\n", i <= (int)val->size_a ? val->a[i] : 0, i <= (int)val->size_b ? val->b[i] : 0);
        ++i;
    }
    ++nb_coups;
    printf(YELLOW);
    printf("\n\tNombre de coups : [%d]\n", nb_coups);
    printf(NORMAL);
    //usleep(DEBUG_TIME_TO_WAIT);
    printf(NORMAL);
}
/*
static int clamp_int(int value, int min, int max, int rmin, int rmax)
{
    int NewValue;

    //printf("clamp int\t|\tValue [%d] | min [%d] | max [%d] | newmin [%d] | newmax [%d]\n", value, min, max, rmin, rmax);
    NewValue = (((value - min) * (rmax - rmin)) / (max - min)) + rmin;
    return (NewValue);
}

static int get_max_value(int *tab)
{
    int max;

    max = 0;
    for (size_t i = 0; tab[i]; i++) {
        if (tab[i] > max)
            max = tab[i];
    }
    return (max);
}

static int get_min_value(int *tab)
{
    int max;

    max = tab[0];
    for (size_t i = 0; tab[i]; i++) {
        if (tab[i] < max)
            max = tab[i];
    }
    return (max);
}
*/
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}


void preview_bar(t_val *val)
{
    /*
    struct winsize w;
    ioctl(1, TIOCGWINSZ, &w);
    int start_x_a = (w.ws_col / 2) - (ft_strlen("HEAP A") * 4);
    int start_x_b = (w.ws_col / 2) + ((ft_strlen("HEAP B") * 4) - (ft_strlen("HEAP B") - 1));
    int start_y_a = 5;
    int start_y_b = 5;

    static int draw_line_max_y = 0;
    //if (draw_line_max_y == 0)
    //    draw_line_max_y = val->size_a; //> val->size_b ? val->size_a : val->size_b;

    //gotoxy(0, 0);
    //printf("col [%d] row [%d]\n", w.ws_row, w.ws_col);
    //gotoxy(0, 0);
    //clear_screen();

    system("clear");
    gotoxy(0, 0);
    ft_putstr_fd(CYAN, 1);
    for (size_t i = 0; i < w.ws_col; i++) {
        ft_putstr_fd("#", 1);
    }
    gotoxy((w.ws_col / 2) - (ft_strlen("HEAP A") * 4), 3);
    printf("HEAP A");
    gotoxy((w.ws_col / 2) + ((ft_strlen("HEAP B") * 4) - (ft_strlen("HEAP B") - 1)), 3);
    printf("HEAP B");

    gotoxy(start_x_a, start_y_a);

    printf(GREEN);
    for (size_t i = 0; i < val->size_a; i++) {
        printf("[%d]\t", val->a[i]);
        for (size_t j = 0; j < val->a[i]; j++) {
            printf("#");
        }
        printf("\n");
        gotoxy(start_x_a, start_y_a + i);
    }

    usleep(500);
    gotoxy(start_x_b, start_y_b);
    printf(YELLOW);

    for (size_t i = 0; i < val->size_b; i++) {
        printf("[%d]\t", val->b[i]);
        for (size_t j = 0; j < val->b[i]; j++) {
            printf("#");
        }
        printf("\n");
        gotoxy(start_x_b, start_y_b + i);
    }
    ft_putstr_fd(CYAN, 1);
    printf("\n");
    usleep(DEBUG_TIME_TO_WAIT);

    //printf("val->size_b [%d]\n", val->size_b);
    //exit(0);
*/

    int max_a = val->size_a <= 0 ? 0 : val->size_a;
    int max_b = val->size_b <= 0 ? 0 : val->size_b;
    static int nb_coups = 0;
    static int mi = 0;
    if (mi == 0)
        mi = max_a > max_b ? max_a : max_b;
    int i;

    i = 0;
    //usleep(DEBUG_TIME_TO_WAIT);
    system("clear");
    printf(CYAN BOLD);
    //for (size_t i = 0; i < w.ws_row; i++) {
    //    printf("#");
    //}

    printf(RED);
    gotoxy(0, 0);
    printf("\n\t- HEAP A -\t\t\t\t- HEAP B -\n");
    printf("\n");
    printf(GREEN);
    while (i < mi)
    {
        int maxval= val->a[i];
        //maxval = clamp_int(val->a[i], get_min_value(val->a), get_max_value(val->a), 1, 30);
        maxval = maxval > 30 ? 30 : maxval;
        //for (int z = 0; z < clamp_int(val->a[i], get_min_value(val->a), get_max_value(val->a), 1, 10); z++) {
        gotoxy(8, 4);
        if (i < (int)val->size_a)
        for (int z = 0; z < maxval; z++) {
            if (val->a[i] < 10)
                printf(GREEN);
            else if (val->a[i] < 20)
                printf(YELLOW);
            else if (val->a[i] < 30)
                printf(RED);
            gotoxy(8 + z, 4 + i);
            printf("#");
        }
        //printf("val [%d]\n", get_max_value(val->a) - val->a[i]);
        //for (int z = 0; z < clamp_int(val->b[i], get_min_value(val->b), get_max_value(val->b), 1, 10); z++) {
        gotoxy(48, 4);
        //maxval = clamp_int(val->b[i], get_min_value(val->b), get_max_value(val->b), 1, 30);
        maxval= val->b[i];
        maxval = maxval > 30 ? 30 : maxval;
        if (i < (int)val->size_b)
        for (int z = 0; z < maxval; z++) {
            if (val->b[i] < 10)
                printf(GREEN);
            else if (val->b[i] < 20)
                printf(YELLOW);
            else if (val->b[i] < 30)
                printf(RED);
            gotoxy(48 + z, 4 + i);
            printf("#");
        }
        ++i;
    }

    ++nb_coups;
	gotoxy(48, 32);
    printf(YELLOW"\n\tNombre de coups : [%d]", nb_coups);
    gotoxy(8, 24);
    printf(YELLOW);
    printf(NORMAL);
    usleep(DEBUG_TIME_TO_WAIT);
    printf(NORMAL);

}

void update_visualisation(t_val *val)
{
	if (!val->bonus_visualize)
		return ;
    if (!PREVIEW_BAR)
        preview_text(val);
    else
        preview_bar(val);
}
