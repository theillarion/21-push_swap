/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:39:06 by illarion          #+#    #+#             */
/*   Updated: 2022/02/12 22:25:03 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uchar;

int		ft_strncmp(const char	*str1, const char	*str2, size_t n);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin(const char	*str1, const char	*str2);
char	*ft_strdup(const char	*str);
char	**ft_split(const char	*str, char symbol);
int		ft_isdigit(int symbol);
int		ft_atoi(const char	*str);
void	ft_putchar_fd(char symbol, int fd);
void	ft_putnbr_fd(int number, int fd);
void	ft_putendl_fd(char	*str, int fd);
void	ft_putstr_fd(char	*str, int fd);
void	*ft_memset(void	*str, int symbol, size_t len);
void	*ft_calloc(size_t	count, size_t	size);

#endif