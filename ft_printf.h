/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:26:45 by sohernan          #+#    #+#             */
/*   Updated: 2024/01/07 21:14:46 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

unsigned int	ft_printf(char const *str, ...);
int				ft_print_s(va_list	args);
int				ft_print_c(va_list	args);
int				ft_print_p(va_list	args);
int				ft_print_di(va_list args);
int				ft_print_u(va_list	args);
int				ft_print_x(va_list	args);
int				ft_print_upper_x(va_list args);

#endif
