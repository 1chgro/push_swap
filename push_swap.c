/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:33:38 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/15 05:35:44 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	v(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	// atexit(v);
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_args(argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	indexing(stack_a);
	t_stack *tmp = stack_a;
	printf("Before sorting:\n");
	while(tmp)
	{
		printf("num: %d| index: %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
	sort_stack(&stack_a, &stack_b);
	printf("-----------------------------------\n");
	printf("After sorting:\n");
	tmp = stack_b;
	while(tmp)
	{
		printf("num: %d\t\t\t| index: %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
