/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohernan <sohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:17:59 by sonheres          #+#    #+#             */
/*   Updated: 2024/01/09 13:47:44 by sohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_x_count(int i, char *str)
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

/*Devuelve nº bytes + imprime nº base 16 en minúsculas.
int num; // para almacenar los caracteres 
i--; // porque termina el bucle con i apuntando al siguiente hueco */
int	ft_print_x(va_list args)
{
	int				i;
	int				num;
	char			nb[16];
	unsigned int	n;

	i = 0;
	num = 0;
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
	return (ft_print_x_count(i, nb));
}

static int	ft_print_upper_x_count(int i, char *str)
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

/* Devuelve nº bytes + imprime nº base 16 en MAYÚSCULAS.
int num; // para almacenar los caracteres
i--; // porque termina el bucle con i apuntando al siguiente hueco */
int	ft_print_upper_x(va_list args)
{
	int				i;
	int				num;
	char			nb[16];
	unsigned int	n;

	i = 0;
	num = 0;
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
	return (ft_print_upper_x_count(i, nb));
}
