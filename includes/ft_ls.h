/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:36:55 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/15 23:54:16 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/ioctl.h>
# include <stdio.h>

# define A_FLAG 	1
# define L_FLAG 	2
# define R_FLAG 	4
# define RR_FLAG 	8
# define T_FLAG 	16
# define ONE_FLAG 	32

enum				{ERRNO, USAGE, MALL_ERR};

typedef struct		s_file {
	struct s_file	*prev;
	struct s_file	*parent;
	struct s_file	*child;
	char			*path;
	char			*name;
	struct stat		stat;
	struct s_file	*next;
}					t_file;

/*
** Parsing Function
*/
int					ls_parse_flags(int ac, char **av, int *flags, int *i);

/*
** Create, traverse and free files tree
*/
t_file				*ls_new_file(void);
t_file				*ls_add_file(t_file *file);
t_file				*ls_goto_first_file(t_file *file);
t_file				*ls_reverse_files(t_file *file);
void				ls_free_files(t_file *file);

/*
** Initialize files tree
*/
t_file				*ls_init_file(char *dir, t_file *file, int *flags, \
					t_file *parent);
char				*ls_get_path(char *dir, char *file);

/*
** Core ls Function
*/
int					ls_init(int ac, char **av, int *flags, int *i);

/*
** Sorting Functions
*/
t_file				*ls_sort_files(t_file *file, int *flags);
t_file				*ls_sort_bubble(t_file *file, int *flags);
t_file				*ls_sort_alpha(t_file *file);
t_file				*ls_sort_time(t_file *file);
t_file				*ls_swap_files(t_file *file);

/*
** Printing Functions
*/
void				ls_print_files(t_file *file, int *flags);
void				ls_print_recurs(t_file *file, int *flags);
void				ls_print(t_file *file, int *flags);
void				ls_print_l(t_file *file, int *flags);

/*
** Utility Functions
*/
int					ls_file_count(t_file *file);
int					ls_max_namelen(t_file *file);
char				*ls_get_perms(mode_t st_mode);
char				ls_get_filetype(mode_t st_mode);
int					ls_get_total_blocks(t_file *file, int *flags);
char				*ls_check_xattr(char *path, char *perms);

/*
** Validation Functions
*/
int					is_ls_flag(char c);
int					is_ls_hidden(char *s);

/*
** Error Management Functions
*/
int					ls_error(char *s, int error);
int					ls_lstat_error(t_file *file);

#endif
