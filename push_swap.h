/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:53:36 by yfurutat          #+#    #+#             */
/*   Updated: 2023/11/20 16:20:57 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OK (0)
# define OVERFLOW (1)
# define UNDERFLOW (-1)
# define POSITIVE (1)
# define NEGATIVE (-1)

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				id;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_info
{
	int	max;
	int	min;
	int	size;
	int	boarder;
}	t_id;

typedef enum e_chk
{
	YES = 0,
	NO = 1,
	ERROR = 2,
	EMPTY = 3,
}	t_chk;

long	ft_atol(const char *from_ascii);
void	ft_putchr_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

int		handle_error(char **argv, int end);
void	init_stack(t_stack **node, char **argv);
void	free_null_list(t_stack **head);
int		check_if_in_order(t_stack *stack);
int		check_order_descending(t_stack *stack);
int		lstsize_circle(t_stack *current);
int		find_median(t_stack *stk, t_id *info);
int		find_max(t_stack *stk, t_id *info);
int		find_min(t_stack *stk, t_id *info);
void	coord_comp(t_stack **stk, t_id *info);

void	my_radix(t_stack **stack_a, t_stack **stack_b, int max);
void	sort3(t_stack **stack);
void	sort4(t_stack **stk_a, t_stack **stk_b, t_id *info);
void	sort5(t_stack **stk_a, t_stack **stk_b, t_id *info);

void	push(t_stack **dst, t_stack **src);
void	swap(t_stack **current);
void	rotate(t_stack **current);
void	reverse_rotate(t_stack **current);

void	pa(t_stack **stk_a, t_stack **stk_b);
void	pb(t_stack **stk_a, t_stack **stk_b);
void	sa(t_stack **stk_a);
void	sb(t_stack **stk_b);
void	ss(t_stack **stk_a, t_stack **stk_b);
void	ra(t_stack **stk_a);
void	rb(t_stack **stk_b);
void	rr(t_stack **stk_a, t_stack **stk_b);
void	rra(t_stack **stk_a);
void	rrb(t_stack **stk_b);
void	rrr(t_stack **stk_a, t_stack **stk_b);

#endif