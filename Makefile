NAME= push_swap
SRCS= push_swap.c\
	utils/operations/push.c\
	utils/operations/reverse.c\
	utils/operations/rotate.c\
	utils/operations/swap.c\
	utils/ft_atoi.c\
	utils/stack_utils.c\
	utils/parse.c\
	utils/parse_utils.c\
	utils/sort_utils.c\
	utils/sort_little.c\
	utils/sort.c

OBJS= $(SRCS:.c=.o)
# FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS) push_swap.h
	@cc  ${FLAGS} ${OBJS} -o $(NAME)
	@echo "Done: excutable is ready"

%.o:%.c 
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "Done: cleaning objects"

fclean: clean
	@rm -rf $(NAME)
	@echo "Done: cleaned all"

re: fclean all