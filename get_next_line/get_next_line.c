/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:50:52 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/11/07 15:52:58 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    ssize_t bytes;
    char *buffer;
    char *linea = "";
    char *support;
    static char* sequeda = "";

    linea = ft_strjoin(linea, sequeda);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes = read(fd, buffer, BUFFER_SIZE);
    while (bytes > 0)
    {

        if ((support = ft_strchr(buffer, '\n')))
        {
            linea = ft_strjoin(linea,ft_substr(buffer, 0, (-1*(ft_strlen(support) - ft_strlen(buffer) - 1))));
            sequeda = ft_substr(buffer, (-1*(ft_strlen(support) - ft_strlen(buffer) - 1)), BUFFER_SIZE);
            break;
        } // encuentra \n, copiar en la frase a devolver hasta el caracter, y copiar la otra parte en el char statico
        //printf("hola");
        linea = ft_strjoin(linea, buffer);
        bytes = read(fd, buffer, BUFFER_SIZE);
    }
    return linea;
}

/*int main()
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
    
    close(fd);

    return 0;
}*/
