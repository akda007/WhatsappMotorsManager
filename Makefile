CC = gcc

TARGET = manager.exe

SRC_DIRS = ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := -Wall -Werror $(INC_FLAGS) -MMD -MP

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.PHONY: clean

clean:
	rm -rf manager.exe
	find . -type f -name '*.o' -delete
	find . -type f -name '*.d' -delete

-include $(DEPS)