/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:58 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/20 18:37:09 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_instruction(char *s, int flag)
{
	if (flag != 0)
	{
		return (!ft_strcmp(s, "sa\n") || !ft_strcmp(s, "sb\n")
			|| !ft_strcmp(s, "ra\n") || !ft_strcmp(s, "rb\n")
			|| !ft_strcmp(s, "pa\n") || !ft_strcmp(s, "pb\n")
			|| !ft_strcmp(s, "rra\n") || !ft_strcmp(s, "rrb\n")
			|| !ft_strcmp(s, "ss\n") || !ft_strcmp(s, "rr\n")
			|| !ft_strcmp(s, "rrr\n"));
	}
	return (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb")
		|| !ft_strcmp(s, "ra") || !ft_strcmp(s, "rb")
		|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb")
		|| !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb")
		|| !ft_strcmp(s, "ss") || !ft_strcmp(s, "rr")
		|| !ft_strcmp(s, "rrr"));
}

void	free_inst_err(char *inst, char *input_line, t_stack **stack_a)
{
	if (inst)
		free(inst);
	if (input_line)
		free(input_line);
	free_stack_and_exit(stack_a);
}

char	*read_instructions(t_stack **stack_a)
{
	char	*input_line;
	char	*instructions;
	char	*tmp;

	input_line = get_next_line(0);
	instructions = NULL;
	while (input_line)
	{
		if (!is_instruction(input_line, 1))
			free_inst_err(instructions, input_line, stack_a);
		tmp = instructions;
		instructions = ft_strjoin(tmp, input_line);
		free(input_line);
		input_line = get_next_line(0);
	}
	return (instructions);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !(*arr))
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	do_instruction(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		sa(stack_a, 1);
	else if (ft_strcmp(str, "sb") == 0)
		sb(stack_b, 1);
	else if (ft_strcmp(str, "ss") == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pa") == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pb") == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "ra") == 0)
		ra(stack_a, 1);
	else if (ft_strcmp(str, "rb") == 0)
		rb(stack_b, 1);
	else if (ft_strcmp(str, "rr") == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "rra") == 0)
		rra(stack_a, 1);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(stack_b, 1);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(stack_a, stack_b, 1);
}
