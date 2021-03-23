#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

int main()
{
	char *str1 = "";
	char *str2 = "hello";
	char *str3 = "123456789012345678901234567890123456789012";
	char buf1[128];
	char buf2[128];
	char buf3[128];

	printf("==========> ft_strlen <==========\n");

	printf("%lu\n", ft_strlen(str1));
	printf("%lu\n", ft_strlen(str2));
	printf("%lu\n", ft_strlen(str3));
	printf("%lu\n", strlen(str1));
	printf("%lu\n", strlen(str2));
	printf("%lu\n", strlen(str3));

	printf("==========> ft_strcpy <==========\n");

	printf("%s: ", ft_strcpy(buf1, str1));
	printf("%s, %s\n", buf1, str1);
	printf("%s: ", ft_strcpy(buf2, str2));
	printf("%s, %s\n", buf2, str2);
	printf("%s: ", ft_strcpy(buf3, str3));
	printf("%s, %s\n", buf3, str3);

	printf("%s: ", strcpy(buf1, str1));
	printf("%s, %s\n", buf1, str1);
	printf("%s: ", strcpy(buf2, str2));
	printf("%s, %s\n", buf2, str2);
	printf("%s: ", strcpy(buf3, str3));
	printf("%s, %s\n", buf3, str3);

	printf("==========> ft_strcmp <==========\n");

	printf("%d\n", ft_strcmp(str1, str1));
	printf("%d\n", ft_strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str3));
	printf("%d\n", ft_strcmp(str2, str1));
	printf("%d\n", ft_strcmp(str2, str2));
	printf("%d\n", ft_strcmp(str2, str3));
	printf("%d\n", ft_strcmp(str3, str1));
	printf("%d\n", ft_strcmp(str3, str2));
	printf("%d\n", ft_strcmp(str3, str3));

	printf("%d\n", strcmp(str1, str1));
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strcmp(str1, str3));
	printf("%d\n", strcmp(str2, str1));
	printf("%d\n", strcmp(str2, str2));
	printf("%d\n", strcmp(str2, str3));
	printf("%d\n", strcmp(str3, str1));
	printf("%d\n", strcmp(str3, str2));
	printf("%d\n", strcmp(str3, str3));

	printf("==========> write <==========\n");

	printf(": %zd", ft_write(1, str1, ft_strlen(str1)));
	printf(" %d\n", errno);
	printf(": %zd", ft_write(1, str2, ft_strlen(str2)));
	printf(" %d\n", errno);
	printf(": %zd", ft_write(1, str3, ft_strlen(str3)));
	printf(" %d\n", errno);
	printf(": %zd", write(1, str1, strlen(str1)));
	printf(" %d\n", errno);
	printf(": %zd", write(1, str2, strlen(str2)));
	printf(" %d\n", errno);
	printf(": %zd", write(1, str3, strlen(str3)));
	printf(" %d\n", errno);

	printf(": %zd", ft_write(-1, str1, ft_strlen(str1)));
	printf(" %d\n", errno);
	printf(": %zd", ft_write(1, str1, -1));
	printf(" %d\n", errno);
	printf(": %zd", ft_write(1, (const void *)42, 1));
	printf(" %d\n", errno);
	printf(": %zd", write(-1, str1, ft_strlen(str1)));
	printf(" %d\n", errno);
	printf(": %zd", write(1, str1, -1));
	printf(" %d\n", errno);
	printf(": %zd", write(1, (const void *)42, 1));
	printf(" %d\n", errno);
}
