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
#include <stdio.h>




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
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
