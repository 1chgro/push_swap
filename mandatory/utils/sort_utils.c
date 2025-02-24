/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:16:26 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/23 18:21:04 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*find_max(t_stack *stack_a)
{
	t_stack	*max;

	if (!stack_a)
		return (NULL);
	max = stack_a;
	while (stack_a)
	{
		if ((stack_a->num) > (max->num))
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack_a)
{
	t_stack	*min;

	if (!stack_a)
		return (NULL);
	min = stack_a;
	while (stack_a)
	{
		if ((stack_a->num) < (min->num))
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}
