#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool is_valid_checksum(long numero);
int get_starting_digits(long numero, int digits);
int get_length(long numero);
void check_card_type(int length, int start_digits);

int main(void)
{
    long numero = get_long("Inserte el número de la tarjeta: ");
    if (is_valid_checksum(numero))
    {
        int length = get_length(numero);
        int start_digits = get_starting_digits(numero, 2);
        check_card_type(length, start_digits);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_starting_digits(long numero, int digits)
{
    while (numero >= pow(10, digits))
    {
        numero /= 10;
    }
    return numero;
}

int get_length(long numero)
{
    int length = 0;
    while (numero > 0)
    {
        numero /= 10;
        length++;
    }
    return length;
}

void check_card_type(int length, int start_digits)
{
    if ((length == 13 || length == 16) && (start_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else if (length == 16 && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (length == 15 && (start_digits == 34 || start_digits == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_valid_checksum(long numero)
{
    int sum_even = 0;
    int sum_odd = 0;
    int posicion = 0;

    while (numero > 0)
    {
        int digit = numero % 10;
        if (posicion % 2 == 0)
        {
            sum_odd += digit;
        }
        else
        {
            int product = digit * 2;
            sum_even += (product / 10) + (product % 10);
        }
        numero = numero / 10;
        posicion++;
    }

    int total_sum = sum_even + sum_odd;
    return (total_sum % 10 == 0);
}

