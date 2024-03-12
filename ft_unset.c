/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:17 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/12 10:12:30 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	ft_unset(t_cmd *cmd, t_data *data)
{
	t_llist	*aux_envp;
	t_llist *temp;
	t_list	*names;

	aux_envp = data->envp;
	names = cmd->args;
	while (names)
	{
		temp = aux_envp;
		while (aux_envp)
		{
			if(ft_strncmp(aux_envp->name, names, ft_charfind(names, "=")) == 0 || ft_strcmp(aux_envp, names) == 0)
			{
				llst_remove(&aux_envp);
				break;
				
			}
			aux_envp = aux_envp->next;
		}
		names = names->next;
		temp = aux_envp;
	}
	return (0);
}*/
