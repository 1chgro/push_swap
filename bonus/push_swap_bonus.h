
#ifndef CHECKER_H
#define CHECKER_H


#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int					num;
	int					index;
	int					position;
	struct s_stack		*next;
}	t_stack;



void	free_stack_and_exit(t_stack **stack);
long	ft_atoi(const char *str);
t_stack	*stacklast(t_stack *stack);
t_stack	*parse_args(int argc, char **argv);
int	has_duplicates(t_stack *stack);
int	add_number(t_stack **stack, int num);
int	is_number(char *str);
char	**ft_split(char const *s, char c);
int	ft_strcmp(const char *s1, const char *s2);
void	free_stack(t_stack **stack);
int	stacksize(t_stack *stack);

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

#endif