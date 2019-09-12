/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fassist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:44:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/11 19:57:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char        *strfree(char *s1, char *s2, int flag)
{
    char    *str;

    str = ft_strjoin(s1, s2);
    if (flag == 1)
    {
        free(s1);
        return (str);
    }
    else if (flag == 2)
    {
        free(s2);
        return (str);
    }
    else if (flag == 3)
    {
        free(s1);
        free(s2);
        return (str);
    }
    return (str);
}

char        *ftoa(long double num, t_ftpf *ftpf)
{
    int             i;
    char            *str;
    char            *fstr;
    intptr_t        ipart;
    long double     fpart;

    i = 0;
    ipart = (intptr_t)num;
    fpart = num - (long double)ipart;
    str = simaxtoa_base(10, ipart);    
    if (ftpf->prcisn)
        fstr = ft_strnew(ftpf->prcisn);
    if (ftpf->prcisn)
    {
        while(i < ftpf->prcisn)
        {
            fpart *= 10;
            fstr[i++] = (int)fpart % 10 + 48;
        }
        str = strfree(str, ".", 1);
        str = strfree(str, fstr, 3);
    }
    return (str);
}