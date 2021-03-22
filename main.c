#include <stdio.h>
#include <string.h>

size_t ft_strlen(char *str);

int main()
{
	char *str1 = "";
	char *str2 = "hello";
	char *str3 = "123456789012345678901234567890123456789012";

	printf("%lu\n", ft_strlen(str1));
	printf("%lu\n", ft_strlen(str2));
	printf("%lu\n", ft_strlen(str3));
	printf("%lu\n", strlen(str1));
	printf("%lu\n", strlen(str2));
	printf("%lu\n", strlen(str3));
}
