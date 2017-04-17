CFLAGS=-Wall -g

symmetric_encript:
	gcc -o symmetric_encrypt symmetric_encrypt.c $(CFLAGS)
clean:
	rm -f symmetric_encrypt

