/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:23:15 by glashli           #+#    #+#             */
/*   Updated: 2022/02/02 23:56:27 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_get_count_lines(const char	*str, char symbol)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == symbol)
			count++;
		i++;
	}
	count++;
	return (count);
}

static char	**ft_get_strs(char	**new_str, const char	*str,
	size_t count, char symbol)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	m;

	k = 0;
	i = 0;
	while (k < count && str[i])
	{
		j = i;
		while (str[j] && str[j] != symbol)
			j++;
		new_str[k] = (char *)malloc((j - i + 2) * sizeof(char));
		if (new_str[k] == NULL)
			return (NULL);
		m = 0;
		while (i <= j)
			new_str[k][m++] = str[i++];
		new_str[k++][m] = '\0';
	}
	new_str[k] = NULL;
	return (new_str);
}

char	**ft_split_new(const char *str, char symbol)
{
	size_t	count;
	size_t	i;
	char	**new_str;

	i = 0;
	count = ft_get_count_lines(str, symbol);
	if (count == 0)
	{
		new_str = (char **)malloc(1 * sizeof(char *));
		new_str[0] = NULL;
		return (new_str);
	}
	new_str = (char **)malloc((count + 1) * sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_get_strs(new_str, str, count, symbol);
	if (new_str == NULL)
	{
		while (i < count && new_str[i])
			free(new_str[i++]);
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
