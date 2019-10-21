NAME=42sh

SRCS=simplist_constructors.c \
	simplist_delete.c \
	simplist_node_utilities.c \
	simplist_operators.c \
	simplist_utilities.c

OBJS=$(SRCS:.c=.o)

OBJS_DIR=build
SRCS_DIR=srcs
OBJS_PATH=$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH=$(addprefix $(SRCS_DIR)/, $(SRCS))
INCLUDES=includes

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_PATH) $(INCLUDES)/simplist.h
	ar rc $(OBJS_DIR)/*.c simplist.a
	ranlib simplist.a

$(OBJS_PATH): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
