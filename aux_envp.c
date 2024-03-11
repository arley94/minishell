/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:53:28 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/11 12:58:50 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	*get_envp(char **envp)
{
	int		i;
    t_llist	*list;
	char	*name;
	char	*value;
	
	i = 0;
	list = NULL;
	name = NULL;
	value = NULL;
	while (envp[i])
	{
		name = ft_substr(envp[i], 0, ft_charfind(envp[i], '='));
        value = ft_substr(envp[i], ft_charfind(envp[i], '=') + 1, 
				ft_strlen(envp[i]));
		lst_add_back(&list, lst_add_new(name, value));
		i++;
	}
	return (list);
}

void	print_env(t_llist *llst, char *print1, char *print2)
{
	t_llist     *aux;
	char		*name;
	char		*value;

	if (!llst)
		return ;
	aux = llst;
	while (aux)
	{
		name = aux->name;
		value = aux->value;
		if (!value)
		{
			if (print2)
				printf(print2, (char *)name);
		}
		else if (!value[0])
			printf(print1, (char *)name, "");
		else
			printf(print1, (char *)name, (char *)value);
        aux = aux->next;
	}
}