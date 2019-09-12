/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:14:23 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/11 19:26:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf   *print_pct(t_ftpf *ftpf)
{
    ftpf->width -= 1;
    check_arg(ftpf, "%");
    ftpf->fmtlen++;
    return (ftpf);
}

t_ftpf	*print_p(t_ftpf *ftpf)
{
	char		*print;
	int			len;
	uintptr_t 	p;

	p = (uintptr_t)(va_arg(ftpf->ap, void *));
	print = uimaxtoa_base(16, p, ftpf);
	print = strfree("0x", print, 2);
	len = ft_strlen(print);
	if (ftpf->width && ftpf->argflag[0] != '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
    return(ftpf);
}
