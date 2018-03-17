/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:45:36 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 19:45:37 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_list	*read_file()
{
	t_list	*ptr;
	t_list	*head;
	char	*line;

	line = 0;
	if (get_next_line(0, &line) > 0)
		ptr = ft_lstnew(line, ft_strlen(line));
	else
		ft_exit();
	head = ptr;
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		ptr->next = ft_lstnew(line, ft_strlen(line));
		ptr = ptr->next;
		ft_strdel(&line);
	}
	return (head);
}
