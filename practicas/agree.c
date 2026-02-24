#include <cs50.h>
#include <stdio.h>

int main(void)

{
    char c = get_char("Confirmas?(y/n) ");

    if (c=='y')
    {
        printf("Has aceptado los terminos y condiciones\n");
    }
    else
    {
        printf("Has rechazado los terminos y condiciones\n");
    }

}
