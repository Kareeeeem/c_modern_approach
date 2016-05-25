# supposed to be included in the Makefiles in the chapter folders and
# ran from there. I never worked with makefiles so gotta figure out how
# to make it smarter.

CC = clang
CFLAGS = -Wall -W -O -g --std=c99
OBJDIR = bin

# this is probably a really roundabout way of doing this. Takes all the c
# files, extracts the basenames and prefixes the directory. So we fo from ex1.c
# to bin/ex1.

sources = $(wildcard *.c)
basenames = $(basename $(sources))
OBJS = $(addprefix $(OBJDIR)/, $(basenames))

all: $(OBJS)

%: %.c
	$(CC) $(CFLAGS) -lm $< -o $(OBJDIR)/$@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*
