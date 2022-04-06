/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:52:20 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/01 17:20:32 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef SYMBOLS_PRINTF
#  define FLAGS "-0.*# +\0"
#  define SPECIFIER "cspdiuxX%\0"
#  define NUMBERS "1234567890\0"
# endif

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <libft.h>

typedef struct	s_stprint
{
	char		*str;
	va_list		args;
	int			dash;
	int			zero;
	int			width;
	int			asterisk_w;
	int			dot;
	int			precision;
	int			space;
	int			asterisk_p;
	char		type;
	int			next;
	long		printed;
	int			error;
}				t_stprint;

int				ft_printf(const char *format, ...);
void			ft_print_total(t_stprint *data);
int				flags(char *str, t_stprint *data);
void			print_manager(t_stprint *data);
int				get_asterisk(t_stprint *data);
char			*zeroprecision(int n_zeros, char *str);
void			print_spaces(int num_spaces, t_stprint *data);
void			print_zeros(int num_spaces, t_stprint *data);
void			print_str(char *str, int length, t_stprint *data);
char			*ft_itoa_base(long number, char *base);
void			ft_print_char(t_stprint *data);
void			ft_print_string(t_stprint *data);
void			ft_print_int(t_stprint *data);
void			ft_print_unsigned(t_stprint *data);
void			ft_print_pointer(t_stprint *data);
void			ft_print_hex(t_stprint *data);
void			ft_print_percent(t_stprint *data);
char			*ft_strsjoin(char *s1, char *s2, int free_s1, int free_s2);
char			*ft_strupcase(char *str);

#endif
