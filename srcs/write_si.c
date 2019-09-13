/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_si.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:30:49 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/12 17:23:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*check_sign(char *print, t_ftpf *ftpf)
{
	if (ftpf->sinum < 0 && ftpf->argflag[0] == '-')
	{
		print = strfree("-", print, 2);
		ftpf->printlen += 1;
		ftpf->fmtlen += 1;
	}
	else if (ftpf->sinum >= 0 && ftpf->argflag[1] == '+' &&
			ftpf->argflag[0] == '-')
	{
		print = strfree("+", print, 2);
		ftpf->printlen += 1;
		ftpf->fmtlen += 1;
	}
	return (print);
}

intptr_t	check_siconv(t_ftpf *ftpf)
{
	intptr_t	num;

	if (ft_strcmp(ftpf->cnvrsn, "hh") == 0)
		num = (signed char)va_arg(ftpf->ap, int);
	else if (ft_strcmp(ftpf->cnvrsn, "h") == 0)
		num = (short)va_arg(ftpf->ap, int);
	else if (ft_strcmp(ftpf->cnvrsn, "l") == 0)
		num = (long)va_arg(ftpf->ap, long);
	else if (ft_strcmp(ftpf->cnvrsn, "ll") == 0)
		num = (long long)va_arg(ftpf->ap, long long);
	else
		num = va_arg(ftpf->ap, int);
	ftpf->sinum = (intptr_t)num;
	return (num);
}

t_ftpf		*print_si(t_ftpf *ftpf)
{
	char		*print;

	ftpf->sinum = check_siconv(ftpf);
	print = simaxtoa_base(10, ftpf->sinum);
	ftpf->printlen = ft_strlen(print);
	if (ftpf->sinum == 0 && ftpf->prcisn == 0 &&
			ft_strcmp(ftpf->cnvrsn, "\0") == 0 && ftpf->argflag[1] != '+')
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	if (ftpf->prcisn <= ftpf->printlen)
		ftpf->fmtlen += ftpf->printlen;
	else
		print = check_prcisn(ftpf, print);
	print = check_sign(print, ftpf);
	check_arg(ftpf, print);
	return (ftpf);
}
