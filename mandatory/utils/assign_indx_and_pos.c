#include "../push_swap.h"

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

void	assign_position(t_stack	*stack_b)
{
	int	i;

	i = 0;
	while (stack_b)
	{
		stack_b->position = i++;
		stack_b = stack_b->next;
	}
}