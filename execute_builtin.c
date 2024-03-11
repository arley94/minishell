/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:35:19 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/11 13:00:53 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exec_builtin(t_cmd *cmd, char **envp)
{
    if (ft_strcmp(cmd->name, "echo") == 0)
        ft_echo(cmd);
    else if (ft_strcmp(cmd->name, "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd->name, "cd") == 0)
        ft_cd(cmd);
    else if (ft_strcmp(cmd->name, "env") == 0)
        ft_env(envp);    
    //else if (ft_strcmp(cmd->name, "export") == 0)
    //    ft_export(cmd, data);
}