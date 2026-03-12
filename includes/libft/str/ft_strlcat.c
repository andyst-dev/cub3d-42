/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:30 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:15:31 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Append the string src to the end of dest. It will append at most
//size - strlen(dest) - 1 characters. It will then NUL-terminate,
//unless size is less than strlen(dest).
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(dest);
	index = 0;
	while (dest[index])
		index++;
	i = 0;
	while (src[i] && (i + index + 1) < (size))
	{
		dest[index + i] = src[i];
		i++;
	}
	if (i < size)
		dest[index + i] = '\0';
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dst_len);
}
