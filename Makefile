# Exe. file name
TARGET = run

CC=gcc
# compiling flags here
CFLAGS12365= -g -Wall

GTKFLAGS123= -export -rdynamic `pkg-config --cflags --libs gtk+-3.0`

SRCS = $(wildcard *.c)
ODIR = obj
_OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS12365) -g -rdynamic -o $@ $^ $(GTKFLAGS123)
	@echo "Linking complete!"

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS12365) -rdynamic -c $< -o $@ $(GTKFLAGS123)
	@echo "Compiled "$<" successfully!"

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
	@echo "Cleanup complete!"
