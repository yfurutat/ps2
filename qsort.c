/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:52:36 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 13:40:16 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	k;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	k = 1;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			printf("sw %d\n", k);
			k++;
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	printf("sw piv\n");
	return (i + 1);
}

void	quick_sort(int arr[], int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort(arr, low, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high);
	}
}
