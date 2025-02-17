/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:21:54 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/15 05:25:50 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int					num;
	int					index;
	int					position;
	struct s_stack		*next;
}	t_stack;

void	free_stack(t_stack **stack);
int		add_number(t_stack **stack, int num);
void	free_stack_and_exit(t_stack **stack);
void	pa(t_stack **a, t_stack **b, int n);
void	pb(t_stack **a, t_stack **b, int n);
void	ss(t_stack **a, t_stack **b, int n);
void	rr(t_stack **a, t_stack **b, int n);
void	rrr(t_stack **a, t_stack **b, int n);
void	sa(t_stack **a, int n);
void	sb(t_stack **b, int n);
void	ra(t_stack **a, int n);
void	rb(t_stack **b, int n);
void	rra(t_stack **a, int n);
void	rrb(t_stack **b, int n);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	assign_indxs(t_stack *stack_a);
void	assign_position(t_stack	*stack_b);
void	move_to_a(t_stack **stack_a, t_stack **stack_b);
void	move_to_b(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack_a);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		stacksize(t_stack *stack);
// int		is_comb(t_stack *stack_a, int size);
long	ft_atoi(const char *str);
t_stack	*parse_args(int argc, char **argv);
t_stack	*find_max(t_stack *stack_a);
t_stack	*find_min(t_stack *stack_a);
t_stack	*stacklast(t_stack *stack);

#endif