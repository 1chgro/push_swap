/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:40:18 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/20 18:41:47 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk(int size)
{
	if (size > 100)
		return (34);
	return (16);
}

static int	is_comb(t_stack *stack_a)
{
	int	dif;
	int	count;

	count = 0;
	while (stack_a && stack_a->next)
	{
		dif = (stack_a->index) - (stack_a->next->index);
		if (dif == 2 || dif == 3 || dif == 4)
			count++;
		stack_a = stack_a->next;
	}
	if (count >= 15)
		return (1);
	return (0);
}

int	find_max_position(t_stack *stack_b)
{
	t_stack	*max;

	max = find_max(stack_b);
	while (stack_b)
	{
		if (stack_b == max)
			return (stack_b->position);
		stack_b = stack_b->next;
	}
	return (-1);
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	chunk_size;

	chunk_size = chunk(stacksize(*stack_a));
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= (i + chunk_size))
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else if (is_comb(*stack_a))
			rra(stack_a, 0);
		else
			ra(stack_a, 0);
	}
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pos;

	size = stacksize(*stack_b);
	while (size)
	{
		assign_position(*stack_b);
		pos = find_max_position(*stack_b);
		if (pos <= size / 2)
		{
			while (pos--)
				rb(stack_b, 0);
		}
		else
		{
			while (pos++ != size)
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b, 0);
		size--;
	}
}
