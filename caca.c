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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
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
	return (dest);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char *)s);
	if (c == 0)
		return ((char *)s);
	if (ptr)
		return (ptr);
	else
		return (NULL);
}

char *get_next_line(int fd)
{
    char *buffer;
    char *frase = NULL;
    ssize_t bytes;
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
    {
        return (NULL);
    }
    frase[0] = '\0';
    bytes = read(fd, buffer, BUFFER_SIZE);
    while (bytes > 0 && ft_strrchr(buffer, '\n'))
    {
        frase = ft_strjoin(frase, buffer);
        bytes = read(fd, buffer, BUFFER_SIZE); 
    }
    return frase;
}
/*
char *get_next_line(int fd)
{
    char *buffer;
    char *frase = NULL; // Inicializa frase a NULL
    ssize_t bytes;
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
    {
        return (NULL);
    }
    
    frase = malloc(1); // Inicializa frase con una cadena vacía
    if (!frase)
    {
        free(buffer); // Libera buffer si la asignación de frase falla
        return (NULL);
    }

    frase[0] = '\0'; // Inicializa frase como una cadena vacía

    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0'; // Asegura que el búfer tenga una terminación nula
        frase = ft_strjoin(frase, buffer);
    }

    free(buffer); // Libera el búfer después de usarlo

    return frase;
}
*/

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
    printf("%s", frase);
    close(fd);

    return 0;
}

