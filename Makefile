CC = gcc

TARGET = manager.exe

SRC_DIRS = ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := -g3 -Wall -Werror $(INC_FLAGS) -MMD -MP

all: $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.PHONY: clean

clean:
	rm -rf manager.exe
	find . -type f -name '*.o' -delete
	find . -type f -name '*.d' -delete
	find . -type f -name '*.exe' -delete

-include $(DEPS)