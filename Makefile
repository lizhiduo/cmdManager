CC=gcc
CFLAGS=

TAGET=test

#SRCS=$(wildcard *.c)
#SRCS=main.c cmd.c gpio.c spi.c
SRCS=main.c cmd.c spi.c gpio.c init.c

OBJS=$(SRCS:.c=.o)

$(TAGET) : $(OBJS)
	@echo $(OBJS)
	$(CC) -T sec.lds -o $@ $^

clean:
	rm -rf $(TAGET) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

