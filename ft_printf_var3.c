/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohernan <sohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/09 13:23:31 by sohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_print_di_count(int i, char *str)
{
	int	count;

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

static int	ft_print_di_dump(long long int n, char *str)
{
	int	i;
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
	return (ft_print_di_count(i, str));
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

// Devuelve nº bytes + imprime str.
int	ft_print_s(va_list args)
{
	char	*str;
	int		i;
	int		res;

	str = va_arg(args, char *);
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		res = write(1, &str[i], 1);
		if (res <= 0)
			return (-1);
		i++;
	}
	return (i);
}

// Devuelve nº bytes + imprime char. return (1)->siempre voy a devolver 1 char
int	ft_print_c(va_list args)
{
	char	c;
	int		res;

	c = va_arg(args, int);
	res = write(1, &c, 1);
	if (res <= 0)
		return (-1);
	return (1);
}
