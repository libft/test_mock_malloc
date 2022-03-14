TARGET := libft_test_mock_malloc.so

CC := clang
CCLD := clang
-include local.mk
CFLAGS := -Weverything -Wno-poison-system-directories -Werror -std=c99 -pedantic
# LDFLAGS := -Wl,--wrap=malloc
SRCS := main.c
OBJS := $(SRCS:%.c=%.o)

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: $(TARGET)
clean:
	$(Q)rm -rf *.o
	$(Q)rm -rf *.d
fclean: clean
	$(Q)rm -rf $(TARGET)
re: fclean all
.PHONY: all clean fclean re

$(TARGET): $(OBJS)
	$(Q)$(CCLD) -fPIC -shared $(LDFLAGS) -o $@ -ldl -- $^

%.o: %.c
	$(Q)$(CC) -fPIC $(CFLAGS) -o $@ -MMD -c -- $<

-include $(SRCS:%.c=%.d)
