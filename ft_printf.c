/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/08 10:33:42 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/* Convierte el parámetro en función del %'letra'.
Después se lo pasa a ft_printf para que lo imprima. */
static int	ft_convert(char c, va_list	args)
{
	if (c == 's')
		return (ft_print_s(args));
	else if (c == 'c')
		return (ft_print_c(args));
	else if (c == 'p')
		return (ft_print_p(args));
	else if (c == 'd')
		return (ft_print_di(args));
	else if (c == 'i')
		return (ft_print_di(args));
	else if (c == 'u')
		return (ft_print_u(args));
	else if (c == 'x')
		return (ft_print_x(args));
	else if (c == 'X')
		return (ft_print_upper_x(args));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

/*"Hola %s me llamo %s", Antonia, Sonia.
// funcion que devuelva tb nº bytes : 
count = count + ft_convert(str[++i], args);
// write(1, &str[i], 1); // va escribiendo detrás de lo que hay
// return (count); // devuelve número caracteres enteros */
unsigned int	ft_printf(char const *str, ...)
{
	int					i;
	unsigned int		count;
	va_list				args;
	int					res;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res = ft_convert(str[++i], args);
		}
		else
		{
			res = write(1, &str[i], 1);
		}
		if (res < 0)
			return (-1);
		count += res;
		i++;
	}
	va_end(args);
	return (count);
}

/*
int main(void)
 {
 	// char *str = "la lory mayers";
 	// char c = 'm';
 	//int i = 10;
 	// int kk = printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
 	// printf ("%i", kk);
 	// char c = 'k';
 	int cc = printf("\001\002\007\v\010\f\r\n");
	printf("\n");
 	printf("El valor de la variable es: %i\n", cc);
 	int cc2 = ft_printf("\001\002\007\v\010\f\r\n");
	printf("\n");
 	printf("%i\n", cc2);
 	// ft_printf("Hola %s me llamo %s\n", "Antonia", "Sonia");
	// printf("devuelve: %p\n", str);
 	return (0);
 }
 */
/*
int	main(void)
{
	char	*s;
	int		count1;
	int		count2;
	int		count3;

	s = "Probando probando y por el camino me voy cagando";
	count1 = '6';
	count2 = -356467;
	count3 = 54673;
	printf("Funcion printf original:
	\n%c\n%d\n%i\n%s\n%x\n%X\n%p\n%u\n%%\n", 
	//count1, count2, count2, s, count3, count3, s, count2);
	ft_printf("Función ft_printf:\n%c\n%d\n%i\n%s\n%x\n%X\n%p\n%u\n%%\n", 
	//count1, count2, count2, s, count3, count3, s, count2);
	return (0);
} */