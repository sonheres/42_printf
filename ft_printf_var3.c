/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/08 10:31:57 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_print_di_dump(long long int n, char *str)
{
	int	i;
	int	count;
	int	sign;

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

/*Devuelve nº bytes + imprime nº base 10. 
char buffer[10]; // almacenamiento temporal
int n;	// lo cojo de la lista de argumentos
count = ft_print_di_dump(n, buffer); // nueva cadena */
int	ft_print_di(va_list args)
{
	char	buffer[11];
	int		n;

	n = va_arg(args, int);
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		return (ft_print_di_dump(n, buffer));
	}
}

/* int main(void)
{
	// char *str = "la lory mayers";
	// char c = 'm';
	//int i = 10;
	// int kk = printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
	// printf ("%i", kk);
	// char c = 'k';
	int cc = printf("%d", INT_MIN);
	printf("El valor de la variable es: %i\n", cc);
	int cc2 = ft_printf("%d", INT_MIN);
	printf("%i\n", cc2);
	// ft_printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
	// printf("devuelve: %p\n", str);
	return (0);
} */