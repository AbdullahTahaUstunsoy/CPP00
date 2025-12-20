NAME = phonebook
SRCS = main.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -c $(SRCS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re