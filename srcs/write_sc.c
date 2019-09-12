/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:21:58 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/07 10:55:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_c(t_ftpf *ftpf)
{
    int     c;

    c = (int)va_arg(ftpf->ap, int);
    ftpf->fmtlen += 1;
    if (ftpf->argflag[3] == '0' && ftpf->argflag[0] != '-')
        print_arg(ftpf, '0', ftpf->width - 1, 1);
    else if (ftpf->argflag[0] != '-')
        print_arg(ftpf, ' ', ftpf->width - 1, 1);
    ft_putchar(c);
    if (ftpf->argflag[0] == '-')
        print_arg(ftpf, ' ', ftpf->width - 1, 1);
}

t_ftpf  *print_s(t_ftpf *ftpf)
{
    char    *s;
    int     len;

    s = va_arg(ftpf->ap, char *);
    if (ftpf->prcisn > -1 && s)
        s = ft_strndup(s, ftpf->prcisn);
    else if (ftpf->prcisn == -1 && !s)
        s = ft_strndup("(null)", ftpf->prcisn);
    else if (ftpf->prcisn > -1 && !s)
        s = ft_strndup("(null)", ftpf->prcisn);
    else if (ftpf->prcisn == -1 && !s)
        s = ft_strdup("(null)");
    len = ft_strlen(s);
    ftpf->fmtlen += len;
    if (ftpf->argflag[3] == '0' && ftpf->argflag[0] != '-')
        print_arg(ftpf, '0', ftpf->width - len, 1);
    else if (ftpf->argflag[0] != '-')
        print_arg(ftpf, ' ', ftpf->width - len, 1);
    ft_putstr(s);
    if (ftpf->argflag[0] == '-')
        print_arg(ftpf, ' ', ftpf->width - len, 1);
    return (ftpf);
}