NAME = pipex


# MANDATORY
LIST = make_cmd.c pipex.c pipex_utils.c child.c

HDR_INCL = ./include/

HDR = pipex.h pipex_bonus.h

HDR_PIPEX = ${addprefix ${HDR_INCL}, ${HDR}}

OBJ1 = ${patsubst %.c,%.o,${LIST}}

CC = gcc

FLAGS = -Wall -Werror -Wextra

UNITS_INCL = ./units/

UNITS_FUNC = ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c


# GNL
GNL_INCL = ./gnl/

GNL_FUNC = get_next_line.c get_next_line_utils.c


# BONUS
UNITS_INCL_B = ./bonus/

UNITS_FUNC_B = pipex_bonus.c check_here_doc.c make_cmd_b.c in_out.c pipex_utils_b.c child_b.c


UNITS = ${addprefix ${UNITS_INCL}, ${UNITS_FUNC}}

UNITS_B = ${addprefix ${UNITS_INCL_B}, ${UNITS_FUNC_B}}

UNITS_GNL = ${addprefix ${GNL_INCL}, ${GNL_FUNC}}


# .c ---> .o (all)
OBJ2 = ${patsubst %.c,%.o,${UNITS}}

OBJ_B = ${patsubst %.c,%.o,${UNITS_B}}

OBJ_GNL = ${patsubst %.c,%.o,${UNITS_GNL}}


%.o : %.c ${HDR_PIPEX}
	${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJ1} ${OBJ2}
				${CC} ${FLAGS} ${OBJ1} ${OBJ2} -o ${NAME}

all: ${NAME}

bonus:	${OBJ_GNL} ${OBJ_B} ${OBJ2}
			${CC} ${FLAGS} ${OBJ_GNL} ${OBJ_B} ${OBJ2} -o ${NAME}

clean:
	rm -f ${OBJ1}
	rm -f ${OBJ2}
	rm -f ${OBJ_B}
	rm -f ${OBJ_GNL}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONNY : all bonus clean fclean re
