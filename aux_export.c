/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:11:01 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/07 21:11:19 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int valid_name(char *str)
{
    int i;

    i = 0;
    if (!ft_isalpha(str[0]) || str[0] != '_')
        return (0);
    while (str[i])
    {
        if (!ft_isalnum(str[i]) || str[i] != '-')
            return (0);
        i++;    
             
    }
    return (1);
}

char    *new_env_name(char *str)
{
    char	*name;
	int 	i;
	
	i = 0;
	name = (char *) malloc((ft_charfind(str, '=') + 1) * sizeof(char));
	if (!name)
		return (0);
	name = ft_substr(str, 0, ft_charfind(str, '='));
	if (!valid_name(name))
	{
            printf("export: \'%s\': not a valid identifier", name);
			return ;
	}
	if (ft_strchr(str, '='))
    {
		while (name[i])
			i++;
		name[i] = '=';
		i++;
	}
	name[i] = '\0';
	return (name);
}

char    *new_env_value(char *str)
{
	char	*value;
	int 	len;
	int		i;
	
	i = 0;
	len = ft_strlen(str);
    if (str[len - 1] == '=')
		value = ft_strdup("");
	else
	{
		value = (char *) malloc((len - ft_charfind(str, '=')) * sizeof(char));
		if (!value)
			return (0);
		value = ft_substr(str, ft_charfind(str, '=') + 1, ft_strlen(str));
	}
	while (value[i])
		i++;
	value[i] = '\0';
	return (value);
}
