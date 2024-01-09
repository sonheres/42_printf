/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohernan <sohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/09 13:36:22 by sohernan         ###   ########.fr       */
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
res = ft_convert(str[++i], args) porque primero hay que avanzar antes de llamar
al ft_convert. Es decir: Evalúa si es '%' y  después avanza antes de llamar a 
la función.
// write(1, &str[i], 1); // va escribiendo detrás de lo que hay. Añade.
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

/* int	main(void)
{
	char	*s;
	int		count1;
	int		count2;
	int		count3;

	s = "Probando probando";
	count1 = '6';
	count2 = -356467;
	count3 = 54673;
	int cc = printf("\n%c\n%d\n%i\n%s\n%x\n%X\n%p\n%u\n%%\n", 
	count1, count2, count2, s, count3, count3, s, count2);
	printf("El valor de las variables es: %i\n", cc);
	int cc_ft = ft_printf("\n%c\n%d\n%i\n%s\n%x\n%X\n%p\n%u\n%%\n", 
	count1, count2, count2, s, count3, count3, s, count2);
	printf("El valor de las variables es: %i\n", cc_ft);
	return (0);
} */