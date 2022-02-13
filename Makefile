#target to compile all files
CC = gcc
CFLAGS = -g -O0 -std=gnu99

create: 
	$(CC) $(CFLAGS) -o amort main.c account.c amortTable.c

# clean:
# 	rm -rf *o create
