/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:27:33 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/31 21:48:45 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    char		*buffer[BUFFER_SIZE];
	ssize_t		bytes_leidos;
	char		*frase;
	int			i;
	int			j;

    bytes_leidos = read(fd, buffer, sizeof(buffer));
	i = 0;
	j = 0;
	while (buffer[i++] != '\n')
	{
		frase[j++] = buffer[i];
	}
	
    if (bytes_leidos == -1) {
        write(1, "AAA", 3); 
    }
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int file_descriptor) {
    char buffer[10];
    ssize_t bytes_leidos;
    ssize_t i = 0;
    int newline_encontrado = 0;

    while ((bytes_leidos = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        while (i < bytes_leidos) {
            if (buffer[i] == '\n') {
                newline_encontrado = 1;
            }
            write(STDOUT_FILENO, &buffer[i], 1); // Muestra un carácter a la vez
            i++;
        }

        if (newline_encontrado) {
            break;
        }
        i = 0;
    }

    if (bytes_leidos == -1) {
        return NULL;
    }

    return 0;
}

/*int main() {
    int file_descriptor;

    // Abre el archivo en modo lectura
    file_descriptor = open("pepe.txt", O_RDONLY);

    if (file_descriptor == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    get_next_line(file_descriptor); // Lee la primera línea
    get_next_line(file_descriptor); // Lee la segunda línea
    get_next_line(file_descriptor); // Lee la tercera línea
    get_next_line(file_descriptor);
     get_next_line(file_descriptor);
     get_next_line(file_descriptor);

    // Cierra el archivo
    close(file_descriptor);

    return 0;
}*/
