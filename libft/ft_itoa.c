/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:18:11 by mleineku          #+#    #+#             */
/*   Updated: 2025/04/30 17:21:46 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	len_int(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	len_n;
	long	m;

	m = n;
	len_n = len_int(m);
	result = malloc(sizeof(char) * len_n + 1);
	if (!result)
		return (NULL);
	result[len_n] = '\0';
	len_n--;
	if (m == 0)
		result[0] = '0';
	if (m < 0)
	{
		result[0] = '-';
		m = -m;
	}
	while (m > 0)
	{
		result[len_n] = (m % 10) + 48;
		m = m / 10;
		len_n--;
	}
	return (result);
}
/*
int	main()
{
	char	*c = ft_itoa(0);
	printf("%s\n", c);
	printf("%ld",len_int(4));
}*/