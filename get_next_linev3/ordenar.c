#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*srt;
	int		i;
	int		j;

	j = ft_strlen(src);
	srt = (char *) malloc(sizeof(char) * (j + 1));
	if (srt == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		srt[i] = src[i];
		i++;
	}
	srt[i] = '\0';
	return (srt);
}

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1)
	{
	    free(s1);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	len = 0;
	while (s1 && i < ft_strlen(s1))
		dest[len++] = s1[i++];
	i = 0;
	while (s2 && i < ft_strlen(s2))
		dest[len++] = s2[i++];
	dest[len] = '\0';
	free(s1);
	if (flag)
        free(s2);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > len_s)
		return (ft_strdup(""));
	len_s -= start;
	if (len_s < len)
		len = len_s;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char *get_next_line(int fd)
{
    ssize_t bytes;
    char *buffer;
    char *linea = "";
    char *support;
    static char* statica = "";

    if (fd < 0 ||BUFFER_SIZE <= 0)
        return NULL;
    linea = ft_strdup(linea);
    linea = ft_strjoin(linea, statica, 0); //malloc de linea - free de linea
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));//free buffer
    if (!buffer)
        return (NULL);
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes <= 0)
    {
        free(buffer);
        return NULL;
    }
    while (bytes > 0) //support = 
    {
        if ((support = ft_strchr(buffer, '\n')))//support hacer malloc ?
        {
            linea = ft_strjoin(linea,ft_substr(buffer, 0, (-1*(ft_strlen(support) - ft_strlen(buffer) - 1))), 1);
            statica = ft_substr(buffer, (-1*(ft_strlen(support) - ft_strlen(buffer) - 1)), BUFFER_SIZE);
            break;
        }
        linea = ft_strjoin(linea, buffer, 0);
        bytes = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    return linea;
}

int main()
{

    int fd;

    fd = open("pepe.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *frase = get_next_line(fd);
    printf("%s\n", frase);
    frase = get_next_line(fd);
    printf("%s\n", frase);
    frase = get_next_line(fd);
    printf("%s\n", frase);
    frase = get_next_line(fd);
    printf("%s\n", frase);
    frase = get_next_line(fd);
    printf("%s\n", frase);
    frase = get_next_line(fd);
    printf("%s\n", frase);
    
    frase = get_next_line(fd);//3
    if(!frase)
    {
        printf("(null)");
    }
    else
        printf("%s\n", frase);
    //frase = get_next_line(fd);
    //if(!frase) printf("NULL");
    //else printf("%s\n", frase);
    
    close(fd);

    return 0;
}
