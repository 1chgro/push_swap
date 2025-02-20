/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:54 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/20 18:35:28 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort_check(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(moves, '\n');
	free(moves);
	while (arr && arr[i])
	{
		if (is_instruction(arr[i], 0))
			do_instruction(stack_a, stack_b, arr[i]);
		else
		{
			free_arr(arr);
			free_stack(stack_a);
			free_stack(stack_b);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	free_arr(arr);
	if (is_sorted(*stack_a) && !stacksize(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*moves;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_args(ac, av);
	moves = read_instructions(&stack_a);
	sort_check(&stack_a, &stack_b, moves);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
