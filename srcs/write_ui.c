/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:39:01 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/12 17:24:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf		*print_x(t_ftpf *ftpf, uintptr_t num)
{
	char		*print;

	print = uimaxtoa_base(16, num, ftpf);
	if (ftpf->argflag[4] == '#' && num != 0 && ftpf->argflag[3] != '0' &&
			ftpf->argflag[0] != '-')
	{
		if (ftpf->specflag == 'x')
			print = strfree("0x", print, 2);
		else if (ftpf->specflag == 'X')
			print = strfree("0X", print, 2);
	}
	ftpf->printlen = ft_strlen(print);
	if (ftpf->prcisn == 0 && num == 0)
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	if (ftpf->prcisn <= ftpf->printlen)
		ftpf->fmtlen += ftpf->printlen;
	else
		print = check_prcisn(ftpf, print);
	check_arg(ftpf, print);
	return (ftpf);
}

t_ftpf		*print_o(t_ftpf *ftpf, uintptr_t num)
{
	char		*print;

	print = uimaxtoa_base(8, num, ftpf);
	if (ftpf->argflag[4] == '#')
	{
		if (num == 0 && ftpf->prcisn == 0)
			print = "0";
		else
			print = strfree("0", print, 2);
	}
	ftpf->printlen = ft_strlen(print);
	if (ftpf->prcisn == 0 && num == 0 && ftpf->argflag[4] != '#')
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	if (ftpf->prcisn <= ftpf->printlen)
		ftpf->fmtlen += ftpf->printlen;
	else
		print = check_prcisn(ftpf, print);
	check_arg(ftpf, print);
	return (ftpf);
}

uintptr_t	check_uiconv(t_ftpf *ftpf)
{
	uintptr_t	num;

	if (ft_strcmp(ftpf->cnvrsn, "hh") == 0)
		num = (unsigned char)va_arg(ftpf->ap, unsigned int);
	else if (ft_strcmp(ftpf->cnvrsn, "h") == 0)
		num = (unsigned short)va_arg(ftpf->ap, unsigned int);
	else if (ft_strcmp(ftpf->cnvrsn, "l") == 0)
		num = (unsigned long)va_arg(ftpf->ap, unsigned long);
	else if (ft_strcmp(ftpf->cnvrsn, "ll") == 0)
		num = (unsigned long long)va_arg(ftpf->ap, unsigned long long);
	else
		num = va_arg(ftpf->ap, unsigned int);
	num = (uintptr_t)num;
	return (num);
}

t_ftpf		*print_ui(t_ftpf *ftpf)
{
	uintptr_t	num;
	char		*print;

	num = check_uiconv(ftpf);
	print = 0;
	if (ftpf->specflag == 'u')
	{
		print = uimaxtoa_base(10, num, ftpf);
		ftpf->printlen = ft_strlen(print);
		if (ftpf->prcisn <= ftpf->printlen)
			ftpf->fmtlen += ftpf->printlen;
		else
			print = check_prcisn(ftpf, print);
		check_arg(ftpf, print);
	}
	else if (ftpf->specflag == 'o')
		print_o(ftpf, num);
	else if (ftpf->specflag == 'x' || ftpf->specflag == 'X')
		print_x(ftpf, num);
	return (ftpf);
}
