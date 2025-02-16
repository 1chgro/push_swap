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

static int	chunk(int size)
{
	if (size > 100)
		return (34);
	return (16);
}

void move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	int chunk_size = chunk(stacksize(*stack_a));
	while(*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index < i + chunk_size)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else
			ra(stack_a, 0);
	}
}


void	give_position(t_stack	*stack_b)
{
	int	i;

	i = 0;
	while (stack_b)
	{
		stack_b->position = i++;
		stack_b = stack_b->next;
	}
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


void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pos;

	size = stacksize(*stack_b);
	while (size)
	{
		give_position(*stack_b);
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
