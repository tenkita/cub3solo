# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 13:07:01 by tkitago           #+#    #+#              #
#    Updated: 2025/04/10 11:01:47 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c ft_atof.c\
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_2darraynew.c\
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c ft_isspace.c\
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  ft_isalnum.c ft_2darraydel.c\
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  ft_strcmp.c\
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c\
					ft_bufferiodel.c ft_bufferionew.c ft_bufferioread.c ft_joinpath.c ft_readline.c\
					ft_strgencomp.c ft_strgendel.c ft_strgenfetch.c ft_strgeninteg.c ft_strgeninit.c\
					ft_strgenstr.c ft_strjoin2.c ft_llst2array.c ft_llstlen.c ft_llstappend.c ft_llstclear.c\
					ft_llstdel.c ft_ndarraydel.c ft_strgenchr.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
					ft_calc_next_chr.c ft_calc_next_str.c ft_contain.c ft_create_file.c ft_create_random_file.c\
					ft_generate_seed.c ft_get_absolute_path.c ft_get_env.c ft_get_expanded_env.c\
        			ft_get_expanded_path.c ft_max.c ft_min.c ft_path_exist.c ft_rand_u32.c ft_strjoin_safe.c\
					ft_get_digit_cnt.c ft_utoa.c ft_chr_to_str.c ft_isequal.c ft_ismatch.c ft_strslen.c\
					ft_print_strs.c ft_isint.c ft_issign.c ft_strsdup.c ft_strtrim_safe.c\
					ft_calc_back_chr.c ft_strstr.c ft_contain_any.c ft_char.c ft_format.c ft_hex.c\
					ft_int.c ft_pointer_base.c ft_pointer.c ft_dprintf.c ft_str_count.c ft_str.c ft_tolower_all.c\
					ft_uint.c ft_unfo_output.c xmalloc.c ft_islong.c
OBJS_DIR = ./objs

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
		@mkdir -p $(@D)
		$(CC) -c $(CFLAGS) $< -o $@

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
