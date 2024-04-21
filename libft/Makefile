HDRDIR			=	includes/

SRCDIR			=	srcs/
FT_PRE			=	ft_

CHARDIR			=	$(SRCDIR)char_utils/
CHARSRC			=		\
						isalnum		\
						isalpha		\
						isascii		\
						isdigit		\
						isprint		\
						isspace		\

CHARSRCS		=	$(addprefix $(CHARDIR)$(FT_PRE), $(CHARSRC))


MEMDIR			=	$(SRCDIR)mem_utils/
MEMSRC			=		\
						bzero		\
						calloc		\
						memchr		\
						memclear	\
						memcmp		\
						memcpy		\
						memmove		\
						memset		\
						
MEMSRCS			=	$(addprefix $(MEMDIR)$(FT_PRE), $(MEMSRC))


STRDIR			=	$(SRCDIR)str_utils/
STRSRC			=		\
						atoi			\
						free_ft_split	\
						itoa			\
						split			\
						strchr			\
						strcmp			\
						strdup			\
						strendptr		\
						striteri		\
						strjoin			\
						strlcat			\
						strlcpy			\
						strlen			\
						strmapi			\
						strncmp			\
						strnstr			\
						strrchr			\
						strtrim			\
						substr			\
						tolower			\
						toupper			\
						
STRSRCS			=	$(addprefix $(STRDIR)$(FT_PRE), $(STRSRC))


PRNTDIR			=	$(SRCDIR)print_utils/
PRNTSRC			=		\
						putchar_fd		\
						putstr_fd		\
						putendl_fd		\
						putnbr_fd		\
						
PRNTSRCS		=	$(addprefix $(PRNTDIR)$(FT_PRE), $(PRNTSRC))


LSTDIR			=	$(SRCDIR)lst_utils/
LSTSRC			=		\
						lstnew			\
						lstadd_front	\
						lstsize			\
						lstlast			\
						lstadd_back		\
						lstdelone		\
						lstclear		\
						lstiter			\
						lstmap			\
						lstprint		\
						lstmin			\
						lstmax			\
						lstrotate		\
						lstrevrotate	\
						lstswap			\
						lstpush			\
						lstfind_index	\

						
LSTSRCS			=	$(addprefix $(LSTDIR)$(FT_PRE), $(LSTSRC))


ERRDIR			=	$(SRCDIR)err_utils/
ERRSRC			=		\
						error		\

ERRSRCS			=	$(addprefix $(ERRDIR)$(FT_PRE), $(ERRSRC))


GNLDIR			=	$(SRCDIR)get_next_line/
GNLSRC			=		\
						get_next_line			\
						get_next_line_utils		\

GNLSRCS			=	$(addprefix $(GNLDIR), $(GNLSRC))


PRNTFDIR		=	$(SRCDIR)ft_printf/
PRNTFSRC		=		\
						atowp			\
						in				\
						nbrlen_base		\
						printchar		\
						printstring		\
						printnbr		\
						buffer_utils	\
						format_addr		\
						format			\
						printf			\

PRNTFSRCS		=	$(addprefix $(PRNTFDIR)$(FT_PRE), $(PRNTFSRC))


SRC_AGG			=	\
					$(CHARSRCS)		\
					$(MEMSRCS)		\
					$(STRSRCS)		\
					$(PRNTSRCS)		\
					$(LSTSRCS)		\
					$(ERRSRCS)		\
					$(GNLSRCS)		\
					$(PRNTFSRCS)	\

SRCS			=	$(addsuffix .c, $(SRC_AGG))

OBJDIR			=	objs/
OBJS			=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(SRCS)))
OBJDIRS			=	$(sort $(dir $(OBJS)))

NAME			=	libft.a
IFLAGS			=	-I$(HDRDIR)
CC				=	cc
CFLAGS 			=	-Wall -Wextra -Werror -c
AR				=	ar -rcs
RM				=	rm -rf

UP				=	\033[1A
FLUSH			=	\033[2K


all: $(NAME)

bonus: all

$(NAME): $(OBJDIRS) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
