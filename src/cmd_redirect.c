/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:12:07 by tzizi             #+#    #+#             */
/*   Updated: 2024/11/18 17:06:10 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_fd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (ft_strcmp(cmd[i], ">>") == 0)
		{
			if (cmd[i + 1])
			{
				if (access(cmd[i + 1], W_OK) == 0)
					return (open(cmd[i + 1], O_WRONLY | O_APPEND));
			}
			return (-1);
		}
		if (ft_strcmp(cmd[i], ">") == 0)
		{
			if (cmd[i + 1])
			{
				if (access(cmd[i + 1], W_OK) == 0)
					return (open(cmd[i + 1], O_WRONLY | O_TRUNC));
			}
			return (-1);
		}
	}
	return (1);
}