#include "push_swap_bonus.h"

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

char *read_instructions(void)
{
	char *input_line;
	char *instructions;
	char *tmp;

	input_line = get_next_line(0);
	instructions = NULL;
	while(input_line)
	{
		tmp = instructions;
		instructions = ft_strjoin(instructions, input_line);
		free(input_line);
		input_line = get_next_line(0);
	}
	return (instructions);
}

void free_arr(char **arr)
{
	int i;

	i = 0;
	if (!arr || !(*arr))
		return ;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int is_instruction(char *s)
{
	return (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb")
		|| !ft_strcmp(s, "ra") || !ft_strcmp(s, "rb")
		|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb")
		|| !ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb")
		|| !ft_strcmp(s, "ss") || !ft_strcmp(s, "rr")
		|| !ft_strcmp(s, "rrr"));
}

void do_instruction(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
	{
		sa(stack_a, 1);
	}
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

void sort_check(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	char **arr;
	int i = 0;

	arr = ft_split(moves, '\n');
	free(moves);
	while(arr && arr[i])
	{
		if (is_instruction(arr[i]))
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

void v(void)
{
	system("leaks checker");
}
int main(int ac, char **av)
{
	atexit(v);
    t_stack *stack_a;
    t_stack *stack_b;
	char *moves;
    if (ac < 2)
		return (0);
    stack_b = NULL;
    stack_a = parse_args(ac, av);
	moves = read_instructions();
	sort_check(&stack_a, &stack_b, moves);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}