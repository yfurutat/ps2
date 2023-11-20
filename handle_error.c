/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:57:54 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 14:49:07 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 17L
int	check_dup(int *tmp, int end)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < (size_t)end)
	{
		j = i + 1;
		while (j < (size_t)end)
		{
			if (tmp[i] == tmp[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// 10L
int	check_size(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

// 20L
int	handle_error(char **argv, int end)
{
	int		*tmp;
	int		ret;
	size_t	i;

	ret = check_size(argv);
	if (ret == 1)
		return (ret);
	tmp = (int *)malloc(sizeof(int) * end);
	if (tmp == NULL)
		return (1);
	i = 0;
	while (i < (size_t)end)
	{
		tmp[i] = ft_atol(argv[i]);
		i++;
	}
	ret = check_dup(tmp, end);
	free(tmp);
	tmp = NULL;
	return (ret);
}
