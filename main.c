#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int main()
{
	char *str1 = "abc";
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

	printf("%d\n", ft_strcmp("", ""));
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

	printf("==========> read <==========\n");

	int fd;
	size_t n;

	fd = open("a.txt", O_RDONLY);
	n = ft_read(fd, buf1, 0);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = ft_read(fd, buf1, 5);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);
	fd = open("c.txt", O_RDONLY);
	n = ft_read(fd, buf1, 42);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);

	fd = open("a.txt", O_RDONLY);
	n = read(fd, buf1, 0);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = read(fd, buf1, 5);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);
	fd = open("c.txt", O_RDONLY);
	n = read(fd, buf1, 42);
	buf1[n] = 0;
	printf("%zd: %s\n", n, buf1);
	close(fd);

	fd = open("b.txt", O_RDONLY);
	n = ft_read(-1, buf1, 5);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = ft_read(fd, (char *)0, 5);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = ft_read(fd, buf1, -1);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);

	fd = open("b.txt", O_RDONLY);
	n = read(-1, buf1, 5);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = read(fd, (char *)0, 5);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);
	fd = open("b.txt", O_RDONLY);
	n = read(fd, buf1, -1);
	buf1[n] = 0;
	printf("%zd: %s %d\n", n, buf1, errno);
	close(fd);

	printf("==========> ft_strdup <==========\n");

	char *dest1, *dest2, *dest3;

	dest1 = ft_strdup(str1);
	printf("%s %s\n", dest1, str1);
	dest2 = ft_strdup(str2);
	printf("%s %s\n", dest2, str2);
	dest3 = ft_strdup(str3);
	printf("%s %s\n", dest3, str3);
	free(dest1);
	free(dest2);
	free(dest3);

	dest1 = strdup(str1);
	printf("%s %s\n", dest1, str1);
	dest2 = strdup(str2);
	printf("%s %s\n", dest2, str2);
	dest3 = strdup(str3);
	printf("%s %s\n", dest3, str3);
	free(dest1);
	free(dest2);
	free(dest3);
}
