include ../config.h

SRC       = gdbwrapper.c interface.c
CLIENT    = client.o
CLIENT    = client.c
OBJ       = $(SRC:.c=.o)
CFLAGS32  += -Wpointer-arith -Wextra -fPIC -g3 -Wall				 \
			-Iinclude/ $(DYNOPT) $(BUILDOP) 			 \
	  		-I../libgdbwrap/include/			      	 \
			-I../libaspect/include/				      	 \
			-I../librevm/include/				      	 \
			-I../libelfsh/include/				      	 \
			-I../libe2dbg/include/				      	 \
			-I../libstderesi/include/			      	 \
			-I../libetrace/include/			      	 \
			-I../libedfmt/include/				      	 \
			-I../libasm/include/				      	 \
			-I../libui/include/					 \
			-I../libmjollnir/include/ -DERESI32			      	 

LDFLAGS32 +=		-L../libaspect/ -laspect32				 


NAME      = libgdbwrap

CC      ?= gcc
LD      ?= ld
AR	= ar rc
RANLIB  = ranlib

all  :  all32

all32:	$(OBJ)
	$(AR) $(NAME).a $(OBJ)
	$(RANLIB) $(NAME).a
	$(LD) -r $(OBJ) -o $(NAME).o 

client:
	$(CC) $(CLIENT) $(CFLAGS32) $(LDFLAGS32) libgdbwrap.a -o client

clean:
	rm -f $(OBJ) $(OBJ) *~ *\# \#* .\#* 
	rm -f include/*~ include/*\# include/\#* include/.\#* 

fclean:	clean
	rm -f $(NAME).a $(NAME).o *.o client

%.o:	%.c
	$(CC) $(CFLAGS32) -c -o $@ $<