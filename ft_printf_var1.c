/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/08 10:35:10 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

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
			exit(-1);
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
		exit(-1);
	return (1);
}

/*Devuelve nº bytes + imprime nº base 16 en minúsculas.
int num; // para almacenar los caracteres 
i--; // porque termina el bucle con i apuntando al siguiente hueco */
int	ft_print_x(va_list args)
{
	int				i;
	int				num;
	int				count;
	char			nb[16];
	unsigned int	n;

	i = 0;
	num = 0;
	count = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		num = n % 16;
		if (num < 10)
			nb[i++] = num + '0';
		else
			nb[i++] = num + 'a' - 10;
		n = n / 16;
	}
	i--;
	while (i >= 0)
	{
		if (write(1, &nb[i--], 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}

/* Devuelve nº bytes + imprime nº base 16 en MAYÚSCULAS.
int num; // para almacenar los caracteres
i--; // porque termina el bucle con i apuntando al siguiente hueco */
int	ft_print_upper_x(va_list args)
{
	int				i;
	int				num;
	int				count;
	char			nb[16];
	unsigned int	n;

	i = 0;
	num = 0;
	count = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		num = n % 16;
		if (num < 10)
			nb[i++] = num + '0';
		else
			nb[i++] = num + 'A' - 10;
		n = n / 16;
	}
	i--;
	while (i >= 0)
	{
		if (write(1, &nb[i--], 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}
