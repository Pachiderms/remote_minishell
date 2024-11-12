/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:23 by tzizi             #+#    #+#             */
/*   Updated: 2024/11/12 16:03:17 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeup(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (j + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*conc;

	size = ft_sizeup(s1, s2);
	i = 0;
	j = 0;
	conc = malloc(size * sizeof(char) + 1);
	if (conc == NULL)
		return (0);
	while (s1[i] && i + j < size)
	{
		conc[i] = s1[i];
		i++;
	}
	while (s2[j] && i + j < size)
	{
		conc[j + i] = s2[j];
		j++;
	}
	conc[j + i] = '\0';
	return (conc);
}
