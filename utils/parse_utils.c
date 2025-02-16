/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:33:53 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/15 05:32:00 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->num == check->num)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	add_number(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = stacklast(*stack);
	last->next = new;
	return(1);
}
