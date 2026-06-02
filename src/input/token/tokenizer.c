/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaizoun <yzaizoun@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:41:16 by yzaizoun          #+#    #+#             */
/*   Updated: 2026/05/29 14:41:36 by yzaizoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include "linked_list.h"

bool	tokenize(char *line, t_list *tokens)
{
	char	*token;
	bool	sq;
	bool	dq;

	token = line;
	sq = 0;
	dq = 0;
	while (token)
	{
		if (!is_tokenizable(token, tokens))
			return (false);
		token = add_token(token, tokens, &sq, &dq);
	}
	/*we have to add a check here to say if there are single or doble quotes open*/
	return (true);
}
