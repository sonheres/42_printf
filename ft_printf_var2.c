/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/08 10:35:51 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
/* Devuelve nº bytes + imprime puntero(hexadec). = 'itoa' / Dividir entre 16
el parámetro va a ser una dirección d de memoria.
El resto siempre va a ser entre 0 y 15.
0 - 9 -> será un nº; 10 - 15 -> LETRA (A -F);
numstr = va_arg(args, char *) saco de la lista de argumentos
la variable que voy a usar.
int	num; // para almacenar los caracteres.
i--; // porque termina el bucle con i apuntando al siguiente hueco*/
static int	ft_print_p_dump(unsigned long long int n, char *str)
{
	int	i;
	int	num;
	int	count;

	i = 0;
	while (n != 0)
	{
		num = n % 16;
		if (num < 10)
			str[i++] = num + '0';
		else
			str[i++] = num + 'a' - 10;
		n = n / 16;
	}
	i--;
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	while (i >= 0)
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		count++;
		i--;
	}
	return (count);
}

/* Devuelve nº bytes + imprime puntero(hexadec).
char buffer[16]; // almacenamiento temporal
char *pointer;	 // lo cojo de la lista de argumentos
count = ft_print_p_dump(n, buffer); // nueva cadena
i--; // porque termina el bucle con i apuntando al siguiente hueco */
int	ft_print_p(va_list args)
{
	char			buffer[16];
	char			*pointer;
	long long int	n;

	pointer = va_arg(args, char *);
	if (!pointer)
		return (write(1, "0x0", 3));
	else
	{
		n = (unsigned long long int)pointer;
		return (ft_print_p_dump(n, buffer));
	}
}

/* Devuelve nº bytes. Transforma a char nº base 10 SIN SIGNO.
i--; // porque termina el bucle con i apuntando al siguiente hueco */
static int	ft_print_u_dump(long long int n, char *str)
{
	int	i;
	int	count;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--;
	count = 0;
	while (i >= 0)
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		count++;
		i--;
	}
	return (count);
}

/*Devuelve nº bytes + imprime nº base 10 SIN SIGNO. 
char buffer[10]; // almacenamiento temporal
unsigned int n;	 // lo cojo de la lista de argumentos
count = ft_print_u_dump(n, buffer); // nueva cadena */
int	ft_print_u(va_list args)
{
	char			buffer[10];
	unsigned int	n;

	n = va_arg(args, int);
	if (n == 0)
		return (write(1, "0", 1));
	else
		return (ft_print_u_dump(n, buffer));
}

/* int main(void)
{
	// char *str = "la lory mayers";
	// char c = 'm';
	int i = 10;
	// int kk = printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
	// printf ("%i", kk);
	// char c = 'k';
	int cc = printf("%i%%\n", i);
	printf("El valor de la variable es: %i\n", cc);
	int cc2 = ft_printf("%i%%\n", i);
	printf("%i\n", cc2);
	// ft_printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
	// printf("devuelve: %p\n", str);
	return (0);
} */