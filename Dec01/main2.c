/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:30:40 by pstrohal          #+#    #+#             */
/*   Updated: 2024/12/16 14:53:43 by pstrohal         ###   ########.fr       */
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


int find_amount(t_list *lst, int val)
{
	t_list *tmp = lst;
	t_list *minptr = NULL;
	int i = 0;
	while (tmp)
	{
		if ((long)*(int *)(tmp->content) == val)
		{
			i++;
		}
		tmp = tmp->next;
	}
	
	return (i);
}

int main(void)
{
	t_list *list1 = NULL;
	t_list *list2 = NULL;
	t_list *ind;
	char *str;
	int *tmp;
	int size = 0;
	
	int fd = open("input2.txt", O_RDONLY);
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
	long similarity = 0;
	printf("hallo %d\n", size);
	int val1;
	int val2;
	while (size-- > 0)
	{
		val1 = (long)*(int *)(list1->content);
		val2 = find_amount(list2, val1);
		similarity += val1 * val2;
		list1 = list1->next;
	}

	printf("%ld\n", similarity);
	return (0);
}