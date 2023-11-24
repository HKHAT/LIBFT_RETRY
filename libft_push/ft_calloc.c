/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:58:11 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/19 15:33:34 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (size && nmemb >= SIZE_MAX / size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem != NULL)
		ft_bzero(mem, nmemb * size);
	return (mem);
}
