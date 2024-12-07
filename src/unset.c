/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:53 by zamgar            #+#    #+#             */
/*   Updated: 2024/11/18 15:04:55 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_var_exists(t_main *main, char *cmd)
{
	int		i;
	int		j;
	char	*arg;

	i = 0;
	j = 0;
	arg = ft_strdup(&ft_strchr(cmd, ' ')[1]);
	while (i < main->env_len)
	{
		while (main->env[i][j] != '=')
		{
			if (arg[j] == main->env[i][j])
				j++;
			else
				break ;
			if (main->env[i][j] == '=')
				return (free(arg), i);
		}
		j = 0;
		i++;
	}
	free(arg);
	return (-1);
}

int	check_syntax_unset(char *cmd)
{
	int		i;
	char	*arg;

	i = 0;
	if (ft_strncmp(cmd, "unset ", 6) != 0)
		return (0);
	arg = ft_strdup(&ft_strchr(cmd, ' ')[1]);
	if (ft_strncmp(arg, "_", -1) == 0)
		return (free(arg), 0);
	while (arg[i])
	{
		if (arg[i] == '=')
			return (free(arg), 0);
		i++;
	}
	free(arg);
	return (1);
}

void	unset(t_main *main, char *cmd)
{
	int		i;
	int		j;
	int		var_to_unset;
	char	**tmp;

	i = 0;
	j = 0;
	if (check_syntax_unset(cmd) == 0)
		return ;
	var_to_unset = check_var_exists(main, cmd);
	if (var_to_unset == -1)
		return ;
	tmp = (char **)malloc(sizeof(char *) * main->env_len + 1);
	while (i < main->env_len)
	{
		tmp[i] = ft_strdup(main->env[i]);
		i++;
	}
	free_old_env(main->env, main->env_len);
	main->env = (char **)malloc(sizeof(char *) * (main->env_len - 1) + 1);
	i = 0;
	while (i < main->env_len)
	{
		if (i == var_to_unset)
			i++;
		main->env[j] = ft_strdup(tmp[i]);
		i++;
		j++;
		if (i == var_to_unset)
			i++;
	}
	free_old_env(tmp, main->env_len);
	main->env_len -= 1;
	return ;
}
