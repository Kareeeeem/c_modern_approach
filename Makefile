# supposed to be included in the Makefiles in the chapter folders and
# ran from there. I never worked with makefiles so gotta figure out how
# to make it smarter.

CFLAGS = -Wall -Wextra -std=c99
OBJDIR = bin

# this is probably a really roundabout way of doing this. Takes all the c
# files, extracts the basenames and prefixes the directory. So we go from ex1.c
# to bin/ex1

sources = $(wildcard *.c)
basenames = $(basename $(sources))
OBJS = $(addprefix $(OBJDIR)/, $(basenames))

all: $(OBJS)

$(OBJDIR)/%: %.c $(OBJDIR)
	$(CC) $(CFLAGS) -lm $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
