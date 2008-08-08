SRC       = gdbwrapper.c 
CLIENT    = client.c
OBJ       = $(SRC:.c=.o)
CFLAGS    = -Iinclude/ -Wall -g3 -ansi -Werror
NAME      = libgdbwrap

CC      ?= gcc
LD      ?= ld
AR	= ar rc
RANLIB  = ranlib

all:	$(OBJ)
	$(AR) $(NAME).a $(OBJ)
	$(RANLIB) $(NAME).a
	$(LD) -r $(OBJ) -o $(NAME).o $(LDFLAGS)

client:
	$(CC) $(CLIENT) $(CFLAGS) libgdbwrap.a -o client

clean:
	rm -f $(OBJ) $(OBJ) *~ *\# \#* .\#* 
	rm -f include/*~ include/*\# include/\#* include/.\#* 

fclean:	clean
	rm -f $(NAME).a $(NAME).o *.o client

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<