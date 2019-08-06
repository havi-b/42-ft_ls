/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havi <havi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:02:24 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/12 11:55:44 by havi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../libft.h"

typedef union		u_data {
	void			*data;
	double			f;
	long double		u_lf;
}					t_data;

typedef struct		s_flags {
	char			left_just;
	char			padding;
	char			pos_neg;
	char			hash;
	char			space;
}					t_flags;

typedef struct		s_size {
	int				width;
	char			dot;
	int				prcsn;
}					t_size;

typedef struct		s_len {
	char			h;
	char			hh;
	char			l;
	char			ll;
	char			j;
	char			z;
	char			u_l;
}					t_len;

typedef struct		s_id {
	struct s_id		*prev;
	int				index;
	int				va_index;
	int				dollar;
	t_data			data;
	char			*s;
	int				n;
	char			id;
	char			*space;
	t_flags			*flags;
	t_size			*size;
	t_len			*len;
	struct s_id		*next;
}					t_id;

typedef struct		s_va {
	struct s_va		*prev;
	int				va_index;
	t_data			data;
	char			id;
	t_len			*len;
	struct s_va		*next;
}					t_va;

/*
** Create, traverse and free nodes/list
*/
t_id				*new_node(void);
t_id				*add_node(t_id *buff);
t_id				*first_node(t_id *buff);
t_id				*goto_index(t_id *buff, int i);
t_flags				*new_flags(void);
t_size				*new_size(void);
t_len				*new_len(void);
void				free_list(t_id *buff);

/*
** Create, traverse and free va nodes/list
*/
t_va				*new_va();
t_va				*add_va(t_va *va);
t_va				*first_va(t_va *va);
t_va				*goto_va(int i, t_va *va);
void				free_va(t_va *va);

/*
** Parse through format string and fill nodes/list
*/
t_id				*parse(const char *restrict format, va_list args, \
					int *i, t_id *buff);
t_id				*parse_arg_index(const char *restrict format, int *i, \
					t_id *buff);
int					find_va_index(t_id *buff);
t_flags				*parse_flags(const char *restrict format, int *i);
t_size				*parse_size(const char *restrict format, va_list args, \
					int *i);
void				parse_width(const char *restrict format, va_list args, \
					int *i, t_size *size);
void				parse_prcsn(const char *restrict format, va_list args, \
					int *i, t_size *size);
t_len				*parse_len(const char *restrict format, int *i);
t_id				*parse_id(const char *restrict format, va_list args, \
					int *i, t_id *buff);
t_id				*parse_string(const char *restrict format, int *i, \
					t_id *buff);
char				*parse_space(const char *restrict format, int *i);

/*
** Initialize nodes/list and pass off to proper function based on id
*/
t_id				*validate(t_id *buff);
void				route(t_id *buff);

/*
** Handle 'c'
*/
void				make_char_str(t_id *buff);
void				init_char_format(t_id *buff);

/*
** Handle 's'
*/
void				make_str_str(t_id *buff);
void				init_str_format(t_id *buff);
void				init_str_prcsn(t_id *buff);

/*
** Handle 'p, P'
*/
void				make_pntr_str(t_id *buff);
void				init_pntr_format(t_id *buff);

/*
** Handle 'd, D, i'
*/
void				make_int_str(t_id *buff);
char				*init_int_len(t_len *len, intmax_t i);
void				init_int_format(t_id *buff);

/*
** Handle 'o, O, u, U, x, X'
*/
void				make_uint_str(t_id *buff);
char				*init_uint_len(t_len *len, void *n, int base, int upper);
void				init_uint_format(t_id *buff);

/*
** Handle 'f, F'
*/
void				make_flt_str(t_id *buff);
void				init_flt_format(t_id *buff);

/*
** Handle '%'
*/
void				make_percent_str(t_id *buff);

/*
** Handle 'n'
*/
void				make_n(t_id *buff);

/*
** Sizing for output string
*/
void				init_prcsn(t_id *buff);
void				init_width(t_id *buff);
void				fix_width(t_id *buff);

/*
** Handle flags
*/
void				check_pos_neg(t_id *buff);
char				*init_pos_neg(char *s);
void				check_hash(t_id *buff);
char				*init_hash(char *s, char id);
void				check_space(t_id *buff);
char				*init_space(char *s);
void				check_padding(t_id *buff);
void				init_padding(t_id *buff);

/*
** Handle Wildcard (ex. "%*.*d or %*.5x, or %5.*o")
*/
void				init_wildcard(const char *restrict format, int *i, \
					int *dst, va_list args);

/*
** Handle Dollar sign (ex. "%2$d")
*/
void				init_dollar(t_id *buff, va_list args);
void				copy_data(t_id *dst, t_id *src);
t_va				*make_va(t_id *buff);
void				get_va_len(t_id *buff, int *n, int *va_len);
void				init_va(t_id *buff, t_va *va, va_list args);
void				init_va_id(t_id *buff, t_va *va);
void				init_va_data(t_va *va, va_list args);
void				copy_va(t_id *buff, t_va *va);

/*
** Validation Functions
*/
int					is_id(char c);
int					notstring_id(char c);
int					isnum_id(char c);
int					isint_id(char c);
int					isuint_id(char c);
int					isupper_id(char c);
int					isflt_id(char c);
int					ispntr_id(char c);
int					isflag(char c);
int					islen(char c);
int					is_plusminus(char c);
int					isuhash_id(char c);
int					is_valid_hash(t_id *buff);
int					is_valid_fmt(const char *restrict format, int *i);

/*
** Main printf Functions
*/
int					ft_printf(const char *restrict format, ...);
t_id				*make_buff(const char *restrict format, va_list args, \
					int *i);
int					print_strings(t_id *buff);
void				print_char_str(t_id *buff);

#endif
