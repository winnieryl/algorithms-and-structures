CC=gcc

ODIR=obj

_OBJ = sort.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -g -c -o $@ $<

sort: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o