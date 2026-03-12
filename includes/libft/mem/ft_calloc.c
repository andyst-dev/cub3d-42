/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:13:49 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:13:49 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate and zero-initialize memory
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	ptr = (void *)malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
