SRCS	:=	main.c \
			ft_atol.c \
			ft_putstr_fd.c \
			handle_error.c \
			init_stack.c \
			find.c \
			checkers.c \
			coord_comp.c \
			cmd_p.c \
			cmd_s.c \
			cmd_r.c \
			cmd_rr.c \
			sort.c \
			radix.c \
#			print.c \
#			cmds.c \
#			qsort.c \

OBJS	:=	$(SRCS:.c=.o)
NAME	:=	push_swap
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
RM		:=	rm -rf
HFILE	:=	push_swap.h
COM_MSG	:=	commit through Makefile
# AR		:=	ar -rcs

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(CFLAGS) -o push_swap $(OBJS)

clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME) *.o a.out

re		:	fclean all

sall	:
	@$(MAKE) -s all
sre		:	fclean sall

files	:
	@touch $(HFILE) $(SRCS)

norm	:
	@norminette $(HFILE) $(SRCS)
normd	:
	@norminette -R CheckDefine $(HFILE) $(SRCS)
normf	:
	@norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRCS)
norma	:	norm normd normf

commit	:
	@echo "\n"
	git status
	@echo "\n"
	git add $(SRCS) $(HFILE) Makefile .gitignore
	@echo "\n"
	@git commit -m "$(COM_MSG)"
	@echo "\n"
	git status
	@echo "\n"
	@echo '[git push] to complete'
	@echo "\n"

.PHONY	:=	all clean fclean re \
	files sall sre norm normd normf norma commit