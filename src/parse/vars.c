/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 01:30:35 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 20:17:03 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "basic.h"
#include "env.h"
#include "my_printf.h"

static bool	ft_is_dollar(char *line)
{
	int		i;
	bool	sq;
	bool	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !dq)
			sq = !sq;
		else if (line[i] == '\"' && !sq)
			dq = !dq;
		if (line[i] == '$' && !sq)
		{
			if (line[i + 1] == '$' || line[i + 1] == '?'
				|| my_isalnum(line[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_globbercat(char *dest, char *var, int *i, t_shinf *sh)
{
	char	*aux;
	char	*aux2;

	if (!var)
		return (NULL);
	if (!(my_strcmp(var, "$?")))
	{
		my_sbufferf(&aux, "%d", sh->status_code);
		(*i) += 2;
	}
	else if (!(my_strcmp(var, "$$")))
	{
		my_sbufferf(&aux, "%d", getpid());
		(*i) += 2;
	}
	else if (get_env_index(sh, var) >= 0)
		aux = my_strdup(get_env_var(sh, var)->value);
	else
		aux = my_strdup("");
	free(var);
	if (aux == NULL)
		return (NULL);
	aux2 = my_strjoin(dest, aux);
	return (free(aux), aux2);
}

static char	*ft_get_glob(char *line, int *i)
{
	size_t	l;
	char	*var;

	l = 1;
	if (!line)
		return (NULL);
	if (line[0] == '$' && line[1] == '$')
		return (my_strdup("$$"));
	if (line[0] == '$' && line[1] == '?')
		return (my_strdup("$?"));
	while (line[l] && (my_isalnum(line[l]) || line[l] == '_'))
		l++;
	if (!l)
		return (NULL);
	var = NULL;
	my_sbufferf(&var, "%.*s", l, &line[1]);
	if (!var)
		return (NULL);
	(*i) += l;
	return (var);
}

static char	*ft_globber(char *line, int *i, t_shinf *sh)
{
	char	*dest;
	char	*aux;

	aux = my_strdup("");
	if (!aux)
		return (NULL);
	while (line[*i])
	{
		if (line[*i] == '$' && line[*i] == '?' && !ft_is_sq(line, *i))
			dest = ft_globbercat(aux, my_strdup("$?"), i, sh);
		else if (line[*i] == '$' && !ft_is_sq(line, *i))
			dest = ft_globbercat(aux, ft_get_glob(line + *i, i), i, sh);
		if (!dest)
			return (free(aux), NULL);
		free(aux);
		aux = my_strjoin(dest, &line[*i]);
		free(dest);
		dest = NULL;
	}
	return (aux);
}

int	apply_vars(t_shinf *sh, char **line)
{
	char	*aux;
	int		i;

	i = 0;
	if (ft_is_dollar(*line))
	{
		aux = ft_globber(*line, &i, sh);
		if (!aux)
			return (0);
		free(*line);
		*line = aux;
		return (1);
	}
	return (0);
}
