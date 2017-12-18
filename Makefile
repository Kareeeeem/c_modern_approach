# This makefile is modeled after the example on this page.
# https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html

CFLAGS = -g -Wall -Wextra -std=c99

OBJDIR = bin
basenames = $(basename $(wildcard *.c))
OBJS = $(addprefix $(OBJDIR)/, $(basenames))

$(OBJDIR)/%: %.c
	$(CC) $(CFLAGS) -lm $< -o $@

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
