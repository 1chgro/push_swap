
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

#endif