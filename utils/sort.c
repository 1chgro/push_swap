/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:37 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/15 05:36:12 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(t_stack *stack_a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack_a)
		return ;
	tmp1 = stack_a;
	while (tmp1)
	{
		tmp2 = stack_a;
		tmp1->index = 0;
		while (tmp2)
		{
			if (tmp2->num < tmp1->num)
				tmp1->index++;
			if (tmp2->num == tmp1->num && tmp2 != tmp1)
				free_stack_and_exit(&stack_a);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	move_to_b(stack_a, stack_b);
	move_to_a(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}
