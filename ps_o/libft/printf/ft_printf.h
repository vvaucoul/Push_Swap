/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:20:42 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 12:55:45 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		g_chars;

int		ft_pisdigit(int c);
int		ft_patoi(const char *str);
size_t	ft_pstrlen(const char *s);
size_t	ft_wstrlen(const wchar_t *s);
void	ft_pputchar(char c);
void	ft_putwchar(wchar_t c);
void	ft_pputstr(char const *s);
void	ft_putwstr(wchar_t *str);
void	ft_pputnbr(int n);
void	ft_printlnbr(long int n);
void	ft_printaddr(unsigned long int n);
void	ft_printhex(int n, char c);
void	ft_printulhex(unsigned long long int n, char c);
void	ft_printoct(int n);
void	ft_printloct(long int n);
void	ft_printuloct(unsigned long long int n);
void	ft_printunbr(unsigned int n);
void	ft_printulnbr(unsigned long int n);
int		ft_is_specifier(char c);
int		ft_is_modifier(char c);
int		ft_is_flag(char c);
int		*ft_create_array(int *mod_array, const char *format, int *i);
int		ft_print_specifier(const char *format, int *i, va_list ap);
void	ft_print_d(int *array, va_list ap, char c);
void	ft_print_u(int *array, va_list ap, char c);
void	ft_print_o(int *array, va_list ap, char c);
void	ft_print_h(int *array, va_list ap, char c);
void	ft_print_s(int *array, va_list ap);
void	ft_print_ws(int *array, va_list ap);
void	ft_print_c(int *array, va_list ap);
void	ft_print_wc(int *array, va_list ap);
void	ft_print_let(int *array, char c);
int		ft_printf(const char *format, ...);

#endif
