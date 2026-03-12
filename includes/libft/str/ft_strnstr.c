/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:16:01 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:16:01 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Locate a substring in a string with a maximum length
char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < size)
	{
		k = 0;
		while (str[i + k] && str[i + k] == to_find[k]
			&& to_find[k] && i + k < size)
			k++;
		if (!to_find[k])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
