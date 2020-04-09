##
## EPITECH PROJECT, 2020
## Makefile-gen by Clement Muth [WSL: Debian]
## File description:
## Makefile
##

## ========================================================================== ##
PATH_DISPLAY		=	source/display/
SRC_DISPLAY		=


## ========================================================================== ##
PATH_ERROR		=	source/error/
SRC_ERROR		=	error_handling.c	\


## ========================================================================== ##
PATH_INIT		=	source/init/
SRC_INIT		=	init_value.c	\


## ========================================================================== ##
PATH_PROCESS	=	source/process/
SRC_PROCESS		=	derivation.c	\
					process.c	\

## ========================================================================== ##
SRC				=	main.c	\
					$(addprefix $(PATH_DISPLAY), $(SRC_DISPLAY))	\
					$(addprefix $(PATH_ERROR), $(SRC_ERROR))	\
					$(addprefix $(PATH_INIT), $(SRC_INIT))	\
					$(addprefix $(PATH_PROCESS), $(SRC_PROCESS))	\

BIN				= 	109titration

CC				= 	gcc

OBJ 			= 	$(SRC:.c=.o)

RM				=	rm -rf

CFLAGS			=	-W -Wall -Werror

LDFLAGS			=	-Iinclude/ -Llibrary \
					-l_stat	\
					-l_string	\
					-l_maths	\

DFLAGS			=	-g -Wfatal-errors -Wpedantic -Wextra \
					-Wnonnull -Wmain -Wmissing-attributes -Wsequence-point -pg

all:			$(BIN)

$(BIN):			lib $(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(CFLAGS)

lib:
				@$(MAKE) -C library/_string/
				@$(MAKE) -C library/_stat/
				@$(MAKE) -C library/_maths/

clean:
				$(RM) $(OBJ)
				@$(MAKE) -C library/_string/ clean
				@$(MAKE) -C library/_stat/ clean
				@$(MAKE) -C library/_maths/ clean

fclean:			clean
				$(RM) $(BIN)
				@$(MAKE) -C library/_string/ fclean
				@$(MAKE) -C library/_stat/ fclean
				@$(MAKE) -C library/_maths/ fclean

re_lib:
				@$(MAKE) -C library/_string/ re
				@$(MAKE) -C library/_stat/ re
				@$(MAKE) -C library/_maths/ re

re:				fclean all

.PHONY:			 all, fclean, re, library

## ========================================================================== ##
%.o:	%.c
	@gcc -g -o $@ -c $(LDFLAGS) $<