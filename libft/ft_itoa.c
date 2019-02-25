/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:39:45 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/12 14:27:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(int n)
{
	int	b;

	b = 1;
	if (n < 0)
	{
		b = b + 1;
		if (n == -2147483648)
		{
			n = 147483648;
			b = b + 1;
		}
		n = n * -1;
	}
	while ((n = n / 10))
		b++;
	return (b);
}

static	char	*make(char *b, int n, int i)
{
	if (n)
	{
		b = make(b, n / 10, i - 1);
		b[i] = n % 10 + '0';
	}
	return (b);
}

char			*ft_itoa(int n)
{
	char	*b;
	int		i;

	i = len(n);
	if ((b = malloc(sizeof(*b) * (i + 1))))
	{
		if (n < 0)
		{
			b[0] = '-';
			if (n == -2147483648)
			{
				b[1] = '2';
				n = -147483648;
			}
			n = n * -1;
		}
		if (n)
			b = make(b, n, i - 1);
		else
			b[0] = '0';
		b[i] = '\0';
		return (b);
	}
	return ((void *)0);
}
