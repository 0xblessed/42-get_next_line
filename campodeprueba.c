#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int BUFFER_SIZE = 4;
    char *l = "hola pepe eres anormal";
    char *buffer;
    
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return 0;
    buffer = ft_substr(l, 0, BUFFER_SIZE);
     printf("%ss\n", buffer);
    //char *pepe = ft_strrchr(l, 'a');
    //printf("ft_strrchr: %s\n",pepe);
    char *pepe2 = ft_strchr(l, 'a');
    //printf("ft_strchr: %s\n",pepe2);
    char *jose = ft_substr(buffer, 0, (-1*(ft_strlen(pepe2) - ft_strlen(l) - 1)));
    printf("%s\n", jose);
    //int k = ft_strlen(jose);
    //printf("%d", k);
    char *jose2 = ft_substr(buffer, (-1*(ft_strlen(pepe2) - ft_strlen(l) - 1)), BUFFER_SIZE);
    printf("%s", jose2);
    return 0;
}

