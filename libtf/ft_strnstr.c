/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:40:45 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/30 21:40:47 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*(big + i) && i < len)
	{
		n = 0;
		while (*(big + i + n) == *(little + n) && *(little + n) && (i
				+ n) < len)
			++n;
		if (*(little + n) == 0)
			return ((char *)big + i);
		++i;
	}
	return (NULL);
}
