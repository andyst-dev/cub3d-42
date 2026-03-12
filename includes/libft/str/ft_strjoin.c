/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:25 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:15:26 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Concatenate two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		p;
	char	*ptr;

	i = 0;
	p = 0;
	ptr = malloc((sizeof(char)) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[p] = s1[i];
		p++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[p] = s2[i];
		p++;
		i++;
	}
	ptr[p] = '\0';
	return (ptr);
}
