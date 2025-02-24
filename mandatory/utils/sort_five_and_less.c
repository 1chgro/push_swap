/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:28:46 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/23 18:20:58 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack_a)
{
	sa(stack_a, 0);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*max;

	max = find_max(*stack_a);
	if (*stack_a == max)
		ra(stack_a, 0);
	else if ((*stack_a)->next == max)
		rra(stack_a, 0);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, 0);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (*stack_a != min)
	{
		if ((*stack_a)->next == min)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	if (is_sorted(*stack_a) == 0)
	{
		pb(stack_a, stack_b, 0);
		sort_three(stack_a);
		pa(stack_a, stack_b, 0);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (*stack_a != min)
	{
		if ((*stack_a)->next == min || (*stack_a)->next->next == min)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	if (is_sorted(*stack_a) == 0)
	{
		pb(stack_a, stack_b, 0);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b, 0);
	}
}
