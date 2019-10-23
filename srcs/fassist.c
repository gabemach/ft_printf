/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fassist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:44:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:24:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long double	round_check(long double fcpy)
{
	int				i;
	char			*round;

	i = 0;
	fcpy *= 10;
	round = ft_itoa((int)fcpy);
	while (round[i] != '\0')
		i++;
	i = 0;
	if (round[i + 1] == '9' && round[i] < '9')
	{
		round[i] += 1;
		round[++i] = '0';
	}
	else if (round[i + 1] == '9' && round[i] == '9')
	{
		round[i] = 0;
		round[++i] = '0';
	}
	fcpy = ft_atoi(round);
	fcpy /= 10;
	return (fcpy);
}

char	*fstring(t_ftpf *ftpf, long double fpart, char *fstr)
{
	int				i;
	long double		fcpy;

	i = 0;
	fstr = ft_memset(fstr, '0', ftpf->prcisn);
	fpart = fpart < 0 ? -fpart : fpart;
	while (i < ftpf->prcisn)
	{
		fpart *= 10;
		fcpy = fpart;
		fcpy = round_check(fcpy);
		fstr[i++] = (int)fcpy + '0';
		fpart -= (int)fcpy;
	}
	return (fstr);
}

char		*ftoa(long double num, t_ftpf *ftpf)
{
	int				i;
	char			*str;
	char			*fstr;
	intptr_t		ipart;
	long double		fpart;

	i = 0;
	ipart = (intptr_t)num;
	ftpf->sinum = ipart;
	fpart = num - (long double)ipart;
	str = simaxtoa_base(10, ipart);
	if ((num < 0 && ipart == 0) || num < 0)
		str = strfree("-", str, 2);
	if (ftpf->prcisn)
	{
		fstr = ft_strnew(ftpf->prcisn);
		fstr = fstring(ftpf, fpart, fstr);
		str = strfree(str, ".", 1);
		str = strfree(str, fstr, 3);
	}
	return (str);
}
