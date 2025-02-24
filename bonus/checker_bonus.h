/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:49 by olachgue          #+#    #+#             */
/*   Updated: 2025/02/24 08:20:20 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int					num;
	int					index;
	int					position;
	struct s_stack		*next;
}	t_stack;

t_stack	*stacklast(t_stack *stack);
t_stack	*parse_args(int argc, char **argv);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		has_duplicates(t_stack *stack);
int		add_number(t_stack **stack, int num);
int		stacksize(t_stack *stack);
int		is_sorted(t_stack *stack_a);
int		is_number(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_stack_and_exit(t_stack **stack);
void	free_stack(t_stack **stack);
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
int		is_instruction(char *s);
void	free_inst_err(char *inst, char *input_line, t_stack **stack_a);
char	*read_instructions(t_stack **stack_a);
void	free_arr(char **arr);
void	do_instruction(t_stack **stack_a, t_stack **stack_b, char *str);

#endif