#include "push_swap_bonus.h"
#include <stdio.h>


void	assign_indxs(t_stack *stack_a)
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


void sort_check(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	char **arr;
	int i = 0;

	arr = ft_split(moves, '\n');
	

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
	assign_indxs(stack_a);
	moves = read_instructions();
	sort_check(&stack_a, &stack_b, moves);
	// printf("-------\n%s----------\n", move);
	free(moves);
    free(stack_a);
    free(stack_b);
    return (0);
}