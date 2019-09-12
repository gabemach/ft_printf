/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:42:55 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/11 21:58:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void          print_sign(t_ftpf *ftpf)
{
    if (ftpf->sinum < 0 || ftpf->argflag[1] == '+')
    {
            ftpf->width -= 1;
            ftpf->fmtlen += 1;
    }
    if (ftpf->sinum < 0)
        ft_putchar('-');
    else if (ftpf->sinum >= 0 && ftpf->argflag[1] == '+')
        ft_putchar('+');
}

void            check_arg(t_ftpf *ftpf, char *print)
{
    if (ftpf->prcisn <= 0 && ftpf->argflag[0] != '-' && 
                ftpf->argflag[3] == '0')
    {
        print_sign(ftpf);
        print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
    }
    else if (ftpf->prcisn > 0 && ftpf->argflag[0] != '-' && 
                ftpf->argflag[3] == '0' && 
                (ftpf->specflag == 'i' || ftpf->specflag == 'd'))
    {
        if (ftpf->sinum < 0 || ftpf->argflag[1] == '+')
            ftpf->width -= 1;
        print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
        print_sign(ftpf);
    }
    check_arg2(ftpf);
    check_arg3(ftpf);
    ft_putstr(print);
    if (print != NULL && ftpf->specflag != 'o')
        free(print);
    if (ftpf->argflag[0] == '-')
        print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
}

void          check_arg2(t_ftpf *ftpf)
{
    if (ftpf->argflag[0] != '-' && ftpf->argflag[3] != '0')
    {
        if (ftpf->sinum < 0 || ftpf->argflag[1] == '+')
        {
            ftpf->width -= 1;
        }
        if (ftpf->width <= 0 && ftpf->argflag[2] == ' ' && 
                    ftpf->argflag[1] == '\0' && ftpf->sinum >= 0 && 
                    ftpf->specflag != 'u' && ftpf->specflag != '%')
            print_arg(ftpf, ' ', 1, 1);
        else
            print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
        print_sign(ftpf);
    }
}

void          check_arg3(t_ftpf *ftpf)
{
    if (ftpf->argflag[0] != '-' && ftpf->argflag[3] == '0' && 
            (ftpf->specflag == 'u' || ftpf->specflag == 'x' || 
            ftpf->specflag == 'X' || ftpf->specflag == 'o'))
    {
        if (ftpf->argflag[4] == '#' && (ftpf->specflag == 'x' || 
                ftpf->specflag == 'X'))
        {
            ftpf->specflag == 'x' ? ft_putstr("0x") : ft_putstr("0X");
            ftpf->width -= 2;
            ftpf->fmtlen += 2;
        }
        print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
    }
    if (ftpf->argflag[0] == '-' && ftpf->argflag[4] == '#' &&
            (ftpf->specflag == 'x' || ftpf->specflag == 'X'))
    {
        ftpf->specflag == 'x' ? ft_putstr("0x") : ft_putstr("0X");
        ftpf->width -= 2;
        ftpf->fmtlen += 2;
    }
}

void            print_arg(t_ftpf *ftpf, char c, int len, int new_len)
{
    char    *str;

    if (len > 0)
    {
        if (new_len)
            ftpf->fmtlen += len;
        if (!(str = ft_strnew(len)))
            exit(-1);
        ft_memset(str, c, len);
        write(1, str, len);
        free(str);
    }
}

