#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int  ft_size_buffer()
{
    #ifdef BUFFER_SIZE
        return 1;
    #else
        return 1;
    #endif
}
char *ft_guarda_frase(char *c, int cont)
{
    char    *str;
    int     i;
    
    str = malloc(sizeof(char) * (cont + 1));
    if (!str)
        return NULL;
    i = 0; 
    while (i < cont)
    {
        str[i] = c[i];
        i++;
    }
    return str;
    
}

char *get_next_line(int file_descriptor)
{
    int k = ft_size_buffer();
    char buffer[k];
    ssize_t bytes_leidos;
    ssize_t i = 0;
    int newline_encontrado = 0;
    int cont = 0;
    char *c;
    
    while ((bytes_leidos = read(file_descriptor, buffer, sizeof(buffer))) > 0)
    {
        while (i < bytes_leidos)
        {
            if (buffer[i] == '\n')
            {
                newline_encontrado = 1;
                break;
            }
            //write(STDOUT_FILENO, &buffer[i], 1);// Muestra un carácter a la vez
            c[i] = buffer[i];
            cont++;
            i++;
        }
        if (newline_encontrado)
            break;
        i = 0;
    }

    if (bytes_leidos == -1 || bytes_leidos == 0)
        return NULL;

    return ft_guarda_frase(c, cont);
}

int main() {
    int file_descriptor;

    // Abre el archivo en modo lectura
    file_descriptor = open("pepe.txt", O_RDONLY);

    if (file_descriptor == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *c = get_next_line(file_descriptor);// Lee la primera línea
    
    for(int i =0; i<5; i++)
        printf("%c", c[i]); 
    
   
    // Cierra el archivo
    close(file_descriptor);

    return 0;
}
