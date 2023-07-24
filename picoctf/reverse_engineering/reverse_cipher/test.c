#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int value = '\x05';
	printf("%x %c %d\n", value, (char)value, value);

	return(EXIT_SUCCESS);
}
