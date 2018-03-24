/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:36:49 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/09 10:45:36 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_count_word(char const *s, char c)
{
	int		word;
	int		i;

	i = 1;
	word = 0;
	while (s[i])
	{
		if (i == 1 && s[0] != c)
			word++;
		if (s[i] != c && s[i - 1] == c && s[i])
			word++;
		i++;
	}
	return (word);
}