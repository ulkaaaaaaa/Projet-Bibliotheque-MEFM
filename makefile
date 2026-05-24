 EXEC = cy_bibliotech
CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c donnee.c fichiers.c metier.c interface.c

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC) $(EXEC).exe
