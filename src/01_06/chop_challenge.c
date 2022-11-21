#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left(char *s, int len)
{
	char *str;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		printf("memory allocation failed\n");
		exit(1);
	}
	*str = '\0';
	int i;
	for (i = 0; i < len; i++, s++)
	{
		if (*s == '\0')
		{
			printf("no enough charaters");
			break;
		}
		strncat(str, s, 1);
	}
	// printf("\nhere is : %s\n", str);
	return (str);
}

char *right(char *s, int len)
{
	char *str;
	char *ptr = s + len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		printf("memory allocation failed\n");
		exit(1);
	}
	*str = '\0';

	if (len > strlen(s))
	{
		printf("out of bound\n");
		exit(1);
	}
	while (*ptr)
	{
		strncat(str, ptr, 1);
		ptr++;
	}
	// printf("\nhere is right: %s\n", str);
	return (str);
}

char *mid(char *s, int offset, int len)
{
	char *str;
	char *ptr;
	ptr = (s + offset);

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		printf("memory allocation failed\n");
		exit(1);
	}
	*str = '\0';

	if (len > strlen(s))
	{
		printf("out of bound\n");
		exit(1);
	}

	while (len > 0)
	{
		strncat(str, ptr, 1);
		len = len - 1;
		ptr = ptr + 1;
	}
	// printf("\nhere is middle: %s\n", str);
	return (str);
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, left(string, 16));
	printf("Right %d characters: %s\n", 18, right(string, 18));

	printf("Middle %d characters: %s\n", 11, mid(string, 13, 11));

	return (0);
}