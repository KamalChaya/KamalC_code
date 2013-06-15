#include <stdio.h>
#include <stdlib.h>


int main() {
	char *file_name = 'test.txt';
	FILE *file;
	char buffer[2];
	int file_size;
	file fopen(file_name, "r+");
	if (file != NULL) {
		printf("%s contains the following:\n", file_name);
		fseek(file, 0, SEEK_END);
		
	}
	
	
	return 0;
}