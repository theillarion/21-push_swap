/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:23:19 by glashli           #+#    #+#             */
/*   Updated: 2022/02/03 00:30:08 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 256
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"

typedef unsigned char	t_uchar;

char	*get_next_line(int fd);
char	**ft_split_new(const char *str, char symbol);

#endif