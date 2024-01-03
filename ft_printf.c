/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/03 17:40:50 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


//Devuelve nº bytes + imprime str.
static int ft_print_s(va_list args)
{
    char    *str;
    int     i;

    str = va_arg(args, char *);
    i = 0;
    if (!str)
        return (write(1, "NULL", 6));
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

//Devuelve nº bytes + imprime char.
static int ft_print_c(va_list args)
{
    char    c;
    
    c = va_arg(args, int);
    if (!c)
        return (write(1, "NULL", 6));
    write(1, &c, 1);
    return (1); //siempre voy a devolver 1 caracter.
}

/* Devuelve nº bytes + imprime puntero(hexadec). = 'itoa' / Dividir entre 16.
el parámetro va a ser una dirección d de memoria. El resto siempre va a ser entre 0 y 15.
0 - 9 -> será un nº; 10 - 15 -> LETRA (A -F);
numstr = va_arg(args, char *) saco de la lista de argumentos la variable que voy a usar. 
*/
static	int	ft_print_p_dump(long long int n, char *str)
{
	int	i;
    int num;//para almacenar los caracteres
    int count;
   
	i = 0;
    while (n != 0)
	{
		num = n % 16;
        if (num < 10)
        {
            str[i++] = num + '0';
        }
        else
        {
            str[i++] = num + 'a' - 10;
        }
        n = n / 16;
    }
    i--; //porque termina el bucle con i apuntando al siguiente hueco
	count = write(1, "0x", 2);
    while (i >= 0)
    {
        count = count + write(1, &str[i], 1);
        i--;
    }
    return (count);
}

static int ft_print_p(va_list args)
{
    char    buffer[16];// almacenamiento temporal
    char    *pointer;//lo cojo de la lista de argumentos
    long long int n;
    int count;
     
    pointer = va_arg(args, char *);
  	if (!pointer)
		return (write(1, "0x0", 3));
	else
	{
        n = (unsigned long long int)pointer;
        count = ft_print_p_dump(n, buffer);//nueva cadena
        return (count);
    }
}

static	int	ft_print_di_dump(long long int n, char *str)
{
	int	i;
    int count;
    int sign;
   
	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[i++] = '-';
	i--; //porque termina el bucle con i apuntando al siguiente hueco
    count = 0;
    while (i >= 0)
    {
        count = count + write(1, &str[i], 1);
        i--;
    }
    return (count);
}

//Devuelve nº bytes + imprime nº base 10.
static int ft_print_di(va_list args)
{
    char    buffer[10];// almacenamiento temporal
    int n;//lo cojo de la lista de argumentos
    int count;
     
    n = va_arg(args, int);
  	if (n == 0)
		return (write(1, "0", 1));
	else
	{
        count = ft_print_di_dump(n, buffer);//nueva cadena
        return (count);
    }
}

static	int	ft_print_u_dump(long long int n, char *str)
{
	int	i;
    int count;
       
	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--; //porque termina el bucle con i apuntando al siguiente hueco
    count = 0;
    while (i >= 0)
    {
        count = count + write(1, &str[i], 1);
        i--;
    }
    return (count);
}

//Devuelve nº bytes + imprime nº base 10 SIN SIGNO.
static int ft_print_u(va_list args)
{
    char    buffer[10];// almacenamiento temporal
    unsigned int n;//lo cojo de la lista de argumentos
    int count;
     
    n = va_arg(args, int);
  	if (n == 0)
		return (write(1, "0", 1));
	else
	{
        count = ft_print_u_dump(n, buffer);//nueva cadena
        return (count);
    }
}

static int	ft_print_x(va_list args)
{
	int	i;
    int num;//para almacenar los caracteres
    int count;
    char    nb[16];
    unsigned int    n;
   
	i = 0;
    num = 0;
    n = va_arg(args, unsigned int);
    if (n == 0)
		return (write(1, "0", 1));
    while (n)
	{
		num = n % 16;
        if (num < 10)
        {
            nb[i++] = num + '0';
        }
        else
        {
            nb[i++] = num + 'a' - 10;
        }
        n = n / 16;
    }
    i--; //porque termina el bucle con i apuntando al siguiente hueco
	//count = write(1, "0x", 2);
    while (i >= 0)
    {
        count = count + write(1, &nb[i], 1);
        i--;
    }
    return (count);
}
int	ft_printf(char const *str, ...) // "Hola %s me llamo %s", Antonia, Sonia.
{
    int i;
    int count;
    va_list args;
    va_start(args, str);
    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '%')
        {
            i++;
            if(str[i] == 's')
            {
                count = count + ft_print_s(args);
            }
            else if(str[i] == 'c')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_c(args);
            }
            else if(str[i] == 'p')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_p(args);
            }
            else if(str[i] == 'd')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_di(args);
            }
            else if(str[i] == 'i')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_di(args);
            }
            else if(str[i] == 'u')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_u(args);
            }
            else if(str[i] == 'x')
            {
                //funcion que devuelva tb nº bytes
                count = count + ft_print_x(args);
            }
            else if(str[i] == 'X')
            {
                //funcion que devuelva tb nº bytes
                //count = count + ft_print_X();
            }
            else if(str[i] == '%')
            {
                //funcion que devuelva tb nº bytes
                //count = count + ft_print_%();
            }
        }
        else 
        {
            write(1, &str[i], 1);//va escribiendo detrás de lo que hay
            count++;
        }
        i++;
    }
    va_end(args);
    return (count); //devuelve número caracteres enteros
}

int main(void)
{
    //char *str = "la lory mayers";
    //char c = 'm';
    int i = 78517;
    //int kk = printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
    //printf ("%i", kk);
    //char c = 'k';
    int cc = printf ("%x\n", i);
    printf ("El valor de la variable es: %i\n", cc);
    int cc2 = ft_printf ("%x\n", i);
    printf ("%i\n", cc2);
   //ft_printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
    //printf("devuelve: %p\n", str);
    return (0);
}