NAME	= push_swap
BONUS_NAME = checker
CC		= cc
LIBFT	= libft/libft.a
RM		= rm -f
SRC		=	functions.c\
			stack_op_1.c\
			stack_op_2.c\
			instructions_1.c\
			instructions_2.c\
			sort_2.c\
			basic_cases.c
PSP		=	push_swap.c

SRC_BONUS= 	checker.c\
			get_next_line.c\
			get_next_line_utils.c\
			ins_bonus_1.c\

OBJ			= $(SRC:.c=.o)
OBJ_PSP		= $(PSP:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $^

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_PSP) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_PSP) $(LIBFT)

$(BONUS_NAME) : $(OBJ) $(OBJ_BONUS) $(LIBFT)

$(OBJ) : $(SRC)
	$(CC) -c $(SRC)

$(LIBFT):
	make -C ./libft

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	$(RM) $(OBJ_PSP)
	make -C libft clean	

bonus: $(BONUS_NAME) 

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) -o $@ $(OBJ_BONUS) $(OBJ) $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	make -C ./libft fclean

re : fclean all
	make -C libft re