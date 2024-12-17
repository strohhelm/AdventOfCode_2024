/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:30:40 by pstrohal          #+#    #+#             */
/*   Updated: 2024/12/16 14:48:36 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/src/libft.h"
#include "../get_next_line/get_next_line.h"


long find_min(t_list *lst)
{
	t_list *tmp = lst;
	t_list *minptr = NULL;
	long min = LONG_MAX;
	long val;
	int i = 0;
	while (tmp)
	{
		if ((long)*(int *)(tmp->content) < min && (long)*(int *)(tmp->content) > 0)
		{
			minptr = tmp;
			min = (long)*(int *)(tmp->content);
			val = i;
		}
		tmp = tmp->next;
		i++;
	}
	printf("%ld ", val);
	val = *(int *)(minptr->content);
	*(int *)(minptr->content) = -1;
	return (val);
}

int main(void)
{
	t_list *list1 = NULL;
	t_list *list2 = NULL;
	t_list *ind;
	char *str;
	int *tmp;
	int size = 0;
	
	int fd = open("input1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("fd open failed!");
		exit(1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = (int *)malloc(sizeof(int));
		*tmp = ft_atoi(str);
		ft_lstadd_back(&list1, ft_lstnew(tmp));
		tmp = (int *)malloc(sizeof(int));
		*tmp = ft_atoi(ft_strrchr(str, ' '));
		ft_lstadd_back(&list2, ft_lstnew(tmp));
		free(str);
		size++;
	}
	close (fd);
	long dist = 0;
	printf("hallo %d\n", size);
	long val1;
	long val2;
	while (size-- > 0)
	{
		val1 = find_min(list1);
		val2 = find_min(list2);
		dist += (val1 > val2) ? (val1 - val2) : (val2 - val1);
	}

	printf("%ld\n", dist);
	return (0);
}