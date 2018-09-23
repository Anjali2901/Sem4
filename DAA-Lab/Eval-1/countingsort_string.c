#include <stdio.h>
#include <string.h>
void countingsort(char *str);
void countingsort(char *str)
{
	int count[256];
	int i;
	char output[20];
	memset(count, '\0', sizeof(count));
	for (i = 0; str[i]; i++)
		++count[(unsigned char)str[i]];
	for (i = 1; i < 256; i++)
		count[i] += count[i-1];
	for (i = 0; str[i]; i++)
		output[--count[(unsigned char)str[i]]] = str[i];
	for (i = 0; str[i]; i++)
		str[i] = output[i];
}

int main(void)
{
	char str[] = "123ab78bj45ui";
	printf("Before: <<%s>>\n", str);
	countingsort(str);
	printf("%s\n", str);
	return 0;
}
