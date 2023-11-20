// #include "push_swap.h"



// void	push(t_stack **dst, t_stack **src)
// {
// 	t_stack	*tmp;
// 	int		flag_sole;

// 	if (*src == NULL)
// 		return ;
// 	tmp = (*src)->next;
// 	flag_sole = 0;
// 	if ((*src)->next == *src)
// 		flag_sole = 1;
// 	((*src)->prev)->next = (*src)->next;
// 	((*src)->next)->prev = (*src)->prev;
// 	if (*dst != NULL)
// 	{
// 		(*src)->next = *dst;
// 		(*src)->prev = (*dst)->prev;
// 		((*dst)->prev)->next = *src;
// 		(*dst)->prev = *src;
// 		*dst = (*dst)->prev;
// 	}
// 	if (*dst == NULL)
// 	{
// 		*dst = *src;
// 		(*dst)->next = *dst;
// 		(*dst)->prev = *dst;
// 	}
// 	*src = tmp;
// 	if (flag_sole)
// 		*src = NULL;
// }
	// if (!flag_sole)
	//src->prev->next = src->next
	//src->next->prev = src->prev
	//src->next = dst
	//src->prev = dst->prev
	// *src = (*src)->next;
	//dst = src
	//dst->next = dst
	//dst->prev = dst
	//src->next

	//src->next = src


// void	go_swap(t_stack **stk_a, t_stack **stk_b, int stk_id)
// {
// 	if (stk_id == A)
// 	{
// 		ft_putstr_fd("sa\n", STDOUT_FILENO);
// 		swap(stk_a);
// 	}
// 	else if (stk_id == B)
// 	{
// 		ft_putstr_fd("sb\n", STDOUT_FILENO);
// 		swap(stk_b);
// 	}
// 	else if (stk_id == BOTH)
// 	{
// 		ft_putstr_fd("ss\n", STDOUT_FILENO);
// 		swap(stk_a);
// 		swap(stk_b);
// 	}
// }

// void	go_rotate(t_stack **stack, int stk_id)
// {
// 	if (stk_id == A)
// 		ft_putstr_fd("ra\n", STDOUT_FILENO);
// 	if (stk_id == B)
// 		ft_putstr_fd("rb\n", STDOUT_FILENO);
// 	rotate(stack);
// }

// void	go_rotate(t_stack **stack, int stk_id)
// {
// 	if (stk_id == A)
// 		ft_putstr_fd("rra\n", STDOUT_FILENO);
// 	if (stk_id == B)
// 		ft_putstr_fd("rrb\n", STDOUT_FILENO);
// 	reverse_rotate(stack);
// }
