#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void print_fila(int bloques, int altura);

int main(void)

{

    int altura = get_positive_int();

    for (int i = 0; i < altura; i++)
    {
        print_fila(i + 1, altura);
    }
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("¿Cual es la altura de la piramide?: ");
    }
    while (n < 1 || n > 8);
    return n;

}

void print_fila(int bloques, int altura)

{
    for (int i = 0; i < altura - bloques; i++)

    {
        printf(" ");
    }
    for (int i = 0; i < bloques; i++)
    {
        printf("#");
    }
    {
        printf("  ");
    }
    for (int i = 0; i < bloques; i++)
    {
        printf("#");
    }
    printf("\n");
}
