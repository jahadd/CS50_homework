#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    FILE *input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("No se pudo abrir card.raw\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *img = NULL;
    int count = 0;
    char filename[8];

    while (fread(buffer, 1, 512, input) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }
    fclose(input);

    return 0;
}
