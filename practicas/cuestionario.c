#include <cs50.h>
#include <stdio.h>

int main(void)
{

string cuestionario(string prompt)

{
string Nombre = get_string("¿Cual es tu nombre?  ");

int edad = get_int("Cual es tu edad?  ");

string casa = get_string("¿Donde vives?  ");

string cumpleaños = get_string("Cual es tu fecha de cumpleaños?  ");

}

if (edad < 18)
    {
    printf("Hola %s, lamentablemente no tienes la edad suficiente para participar, devuelve a tu casa en %s y desea con no haber nacido el dia %s, besos!!\n", Nombre, casa, cumpleaños);
    }
else
    {
printf("Has sido seleccionado para participar! mucha suerte!\n");
    }
}






