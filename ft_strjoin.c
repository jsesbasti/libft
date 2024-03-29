/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:08:23 by jsebasti          #+#    #+#             */
/*   Updated: 2024/02/13 05:07:48 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		res[i] = ((char *)s1)[i];
	while (++j < len2)
		res[i + j] = ((char *)s2)[j];
	return (res);
}
