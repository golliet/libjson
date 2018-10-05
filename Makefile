NAME = json

SRC = main.c parse.c open.c misc.c
SRCSDIR = srcs
SRCS = $(addprefix $(SRCSDIR)/, $(SRC))

OBJ = $(SRC:%.c=%.o)
OBJSDIR = obj
OBJS 		= 	$(addprefix $(OBJSDIR)/, $(OBJ))

INCLUDES 	= 	includes
LIBFTDIR	=	libft
LIB			=	libft.a
LIBD      	=   $(LIBFTDIR)/$(LIB)
HEADERLIB   =   $(LIBFTDIR)/$(INCLUDES)
LDFLAGS 	= 	-L$(LIBFTDIR) -lft

all: $(NAME)

$(NAME): $(LIBFTDIR)/$(LIB) $(OBJSDIR) $(OBJS)
	@echo ""
	gcc -g3 $(LDFLAGS) -I$(HEADERLIB) -I$(INCLUDES) $(OBJS) -o $(NAME)

$(OBJSDIR):
	@mkdir -p $(OBJSDIR);
	@sed -i -e "/add_executable/d" CMakeLists.txt
	@rm CMakeLists.txt-e
	@echo "add_executable(libjson $(SRCS) $(HEADERS))" | sed -e "s/\.\.\///g" >> CMakeLists.txt

$(LIBFTDIR)/$(LIB):
	@make -C $(LIBFTDIR)/


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADERS)
	@gcc -g3 -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)

clean:
	@make clean -C libft/
	rm -rf $(OBJSDIR)

fclean: clean
	@make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re