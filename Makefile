NAME = WebServ

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -Iincludes

SRCS_DIR = srcs

SRCS = $(shell find $(SRCS_DIR) -type f -name '*.cpp')

BUILD_DIR = build

OBJ = $(SRCS:$(SRCS_DIR)/%.cpp=$(BUILD_DIR)/%.o)


all: $(NAME)


$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all