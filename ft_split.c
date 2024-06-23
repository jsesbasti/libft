/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:10:24 by jsebasti          #+#    #+#             */
/*   Updated: 2024/02/13 05:21:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	sum;
	int	in_word;
	int	i;

	sum = 0;
	i = -1;
	in_word = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != c && in_word == 0)
		{
			++sum;
			in_word = 1;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (sum);
}

static int	word_len(const char *str, int i, char c)
{
	int		len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**malloc_error(char **new, int j)
{
	while (j-- >= 0)
		free(new[j]);
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**new;

	if (!s)
		return (NULL);
	new = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_len(s, i, c));
		if (!new[j])
			return (malloc_error(new, j));
		i += word_len(s, i, c);
		++j;
	}
	new[j] = 0;
	return (new);
}
