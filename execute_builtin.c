/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:35:19 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/12 10:35:53 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exec_builtin(t_cmd *cmd, t_data *data)
{
    if (ft_strcmp(cmd->name, "echo") == 0)
        ft_echo(cmd);
    else if (ft_strcmp(cmd->name, "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd->name, "cd") == 0)
        ft_cd(cmd);
    else if (ft_strcmp(cmd->name, "env") == 0)
        ft_env(data->envp);    
    else if (ft_strcmp(cmd->name, "export") == 0)
        ft_export(cmd, data);
}