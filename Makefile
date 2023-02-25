ENCODER			= encoder
DECODER			= decoder

CFLAGS			= -g3 -Wall -Werror -Wextra
LFLAGS			= -lft
INCLUDES		= -I./includes -I$(LIBFT_INC)
LIBS			= -L./libs/libft

#libft
LIBFT_PATH		= ./libs/libft
LIBFT_INC		= $(LIBFT_PATH)/includes
LIBFT			= $(LIBFT_PATH)/libft.a

#source encoder
SRC_DIR			=	./srcs/
ENCODER_PATH	= 	encoder/
SRC_ENCODER		=	$(ENCODER_PATH)encoder.c			\
					$(ENCODER_PATH)utils.c				\
					$(ENCODER_PATH)huffman.c			\
					$(ENCODER_PATH)create_dat_file.c	\
					$(ENCODER_PATH)translation_table.c	\
					$(ENCODER_PATH)decoder_run.c
E_SRCS			= 	$(addprefix $(SRC_DIR), $(SRC_ENCODER))

#source decoder
DECODER_PATH	=	decoder/
SRC_DECODER		=	$(DECODER_PATH)decoder.c			\
					$(DECODER_PATH)utils.c				\
					$(DECODER_PATH)read_dat_file.c		\
					$(DECODER_PATH)responses.c
D_SRCS			= $(addprefix $(SRC_DIR), $(SRC_DECODER))

#objects
OBJS_DIR		= ./objects/
E_OBJS			= $(addprefix $(OBJS_DIR),$(SRC_ENCODER:%.c=%.o))
D_OBJS			= $(addprefix $(OBJS_DIR),$(SRC_DECODER:%.c=%.o))

#colors
GRENN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

all: $(ENCODER) $(DECODER)

$(ENCODER): $(LIBFT) $(OBJS_DIR) $(E_OBJS)
	@gcc $(CFLAGS) $(E_OBJS) $(LFLAGS) $(LIBS) -o $(ENCODER)
	@echo " $(CYAN)$(ENCODER): $(GRENN)Done!"
	@echo -n "$(RESET)"

$(DECODER): $(LIBFT) $(OBJS_DIR) $(D_OBJS)
	@gcc $(CFLAGS) $(D_OBJS) $(LFLAGS) $(LIBS) -o $(DECODER)
	@echo " $(CYAN)$(DECODER): $(GRENN)Done!"
	@echo -n "$(RESET)"

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(ENCODER_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(DECODER_PATH))

$(OBJS_DIR)%o: $(SRC_DIR)%c
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(ENCODER)
	@rm -f $(DECODER)

re: fclean all

coffee:
	@make -sC $(LIBFT_PATH) coffee

.PHONY: all clean fclean re coffee