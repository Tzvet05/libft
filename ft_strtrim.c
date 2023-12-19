/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:19:49 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/07 13:04:18 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_in(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strndup(char *s, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s[0])
		len = 0;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*start_trim;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	start_trim = (char *)s1;
	while (start_trim[0] && ft_in(start_trim[0], set))
		start_trim++;
	while (start_trim[i])
	{
		if (!ft_in(start_trim[i], set))
			len = i;
		i++;
	}
	new_str = ft_strndup(start_trim, len + 1);
	if (!new_str)
		return (NULL);
	return (new_str);
}
