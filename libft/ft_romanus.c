/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:14:19 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/15 19:48:14 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count(int nbr)
{
	int i;
	int c;

	if (nbr)
	{
		c = 0;
		i = nbr % 10;
		if (i < 4)
			while (c < i)
				c++;
		if (i == 4 || i == 9)
			c = 2;
		if (i > 4 && i < 9)
		{
			i = i - 5;
			while (c < i)
				c++;
			c++;
		}
		return (c + count(nbr / 10));
	}
	return (0);
}

static	void	put(char *b, char str)
{
	while (*b)
		b++;
	*b = str;
	b++;
	*b = '\0';
}

static	void	addme(int nbr, char *b, char *str, int deci)
{
	if (nbr == 4)
	{
		put(b, str[(deci * 2)]);
		put(b, str[(deci * 2) + 1]);
	}
	if (nbr == 9)
	{
		put(b, str[(deci * 2)]);
		put(b, str[((deci) * 2) + 2]);
	}
}

static	void	add(int nbr, int deci, char *str, char *b)
{
	if (deci < 0)
		deci = 0;
	if (nbr > 4 && nbr < 9)
	{
		put(b, str[(deci * 2) + 1]);
		nbr = nbr - 5;
		while (nbr)
		{
			put(b, str[(deci * 2)]);
			nbr--;
		}
	}
	if (nbr == 4)
		addme(nbr, b, str, deci);
	if (nbr < 4)
		while (nbr)
		{
			put(b, str[(deci * 2)]);
			nbr--;
		}
}

char			*ft_romanus(int nbr)
{
	char	*b;
	int		deci;

	deci = ft_puiss(ft_countdeci(nbr));
	if (nbr == 0 || nbr > 3999)
		return (NULL);
	if (!(b = malloc(sizeof(char *) * (count(nbr) + 1))))
		return (NULL);
	*b = '\0';
	while (deci)
	{
		if ((nbr / deci) > 0)
			add(nbr / deci, ft_countdeci(nbr) - 1, "IVXLCDM", b);
		nbr = nbr % deci;
		deci = deci / 10;
	}
	return (b);
}
