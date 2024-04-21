LIBFTDIR		=	libft/
LIBFT			= 	$(LIBFTDIR)libft.a
LIBFTINC		=	-L$(LIBFTDIR) -lft
LIBFTHDR		=	$(LIBFTDIR)includes/
HDRDIR			=	includes/


SRCDIR		=	srcs/

ERRDIR		=	$(SRCDIR)error_handling/
ERRSRC		=		\
					pipex_clean				\
					pipex_error				\
					pipex_execute_error		\

ERRSRCS		=	$(addprefix $(ERRDIR), $(ERRSRC))


PIPEDIR		=	$(SRCDIR)pipe/
PIPESRC		=		\
					pipex_pipe				\
					pipex_close_pipes		\

PIPESRCS	=	$(addprefix $(PIPEDIR), $(PIPESRC))


MAINDIR		=	$(SRCDIR)main/
MAINSRC		=		\
					pipex_heredoc			\
					pipex_path				\
					pipex					\

MAINSRCS	=	$(addprefix $(MAINDIR), $(MAINSRC))


SRCAGG		=	\
					$(ERRSRCS)		\
					$(PIPESRCS)		\
					$(MAINSRCS)		\


SRCS		=	$(addsuffix .c, $(SRCAGG))


OBJDIR		=	objs/
OBJS		=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(SRCS)))
OBJDIRS		=	$(sort $(dir $(OBJS)))


NAME		=	pipex
IFLAGS		=	-I$(HDRDIR) -I$(LIBFTHDR)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
MAKE		=	make -C
SANIT		=	-fsanitize=address -g


all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFTINC)

$(LIBFT):
	$(MAKE) $(LIBFTDIR)

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFTDIR) $@

re: fclean all

.PHONY: all bonus clean fclean re
