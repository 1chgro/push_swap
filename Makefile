NAME= push_swap
FLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS= mandatory/push_swap.c\
	mandatory/utils/operations/reverse.c\
	mandatory/utils/operations/push.c\
	mandatory/utils/operations/rotate.c\
	mandatory/utils/operations/swap.c\
	mandatory/utils/ft_atoi.c\
	mandatory/utils/stack_utils.c\
	mandatory/utils/parse.c\
	mandatory/utils/parse_utils.c\
	mandatory/utils/sort_utils.c\
	mandatory/utils/sort_five_and_less.c\
	mandatory/utils/sort.c\
	mandatory/utils/assign_indx_and_pos.c\
	mandatory/utils/sort_more_than_five.c

OBJS= $(SRCS:.c=.o)


BNS_SRCS= bonus/checker_bonus.c\
		bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c\
		bonus/libft/ft_atoi_bonus.c bonus/parse_bonus.c bonus/parse_utils_bonus.c\
		bonus/stack_utils_bonus.c bonus/libft/ft_split_bonus.c bonus/libft/ft_strcmp_bonus.c\
		bonus/operations/push_bonus.c bonus/operations/reverse_bonus.c \
		bonus/operations/rotate_bonus.c bonus/operations/swap_bonus.c bonus/check_utils_bonus.c

BNS_HDRS= bonus/checker_bonus.h bonus/get_next_line/get_next_line.h

BNS_OBJS=$(BNS_SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS) mandatory/push_swap.h
	@cc  ${FLAGS} ${OBJS} -o $(NAME)
	@echo "Done: excutable is ready"

bonus: $(BNS_OBJS) $(BNS_HDRS)
	cc ${FLAGS} ${BNS_OBJS} -o checker

%.o:%.c 
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(BNS_OBJS)
	@echo "Done: cleaning objects"

fclean: clean
	@rm -rf $(NAME) checker
	@echo "Done: cleaned all"

re: fclean all