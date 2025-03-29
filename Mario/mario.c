#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<stdbool.h>

int get_height(void);
char *init_layer(int height);
void flush_buffer(void);

int main(void)
{
    int height = get_height();
    char *layer = init_layer(height);
    for(int i = 0; i < height; i++)
    {
        layer[height - 1 - i] = '#';
        layer[height + 1 + i] = '#';
        printf("%s\n", layer); 
    }
    free(layer);
    return 0;
}

int get_height(void)
{
    int height;
    int result;
    do {
        printf("Height: ");
        result = scanf("%i", &height);
        if (result != 1 || getchar() == '.')
        {
            flush_buffer();
        }
    }
    while(result != 1 || height < 1 || 8 < height);
    return height;
}

char *init_layer(int height)
{
    int width = 1 + (2 * height);
    char *layer = malloc(width * sizeof(char) + 1);
    for(int i = 0; i < width; i++)
    {
        layer[i] = ' ';
    }
    return layer;
}

void flush_buffer(void)
{
    while(getchar() != '\n');
    // while(true)
    // {
    //     int c = getchar();
    //     printf("Flush: %i\n", c);
    //     if (c == '\n')
    //     {
    //         break;
    //     }
    // }
}