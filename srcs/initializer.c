/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:42:18 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/12 17:19:14 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinitialize(t_ftpf *ftpf)
{
	ftpf->specflag = '\0';
	ftpf->argflag[0] = '\0';
	ftpf->argflag[1] = '\0';
	ftpf->argflag[2] = '\0';
	ftpf->argflag[3] = '\0';
	ftpf->argflag[4] = '\0';
	ftpf->cnvrsn[0] = '\0';
	ftpf->cnvrsn[1] = '\0';
	ftpf->prcisn = -1;
	ftpf->width = 0;
}

void	initialize(t_ftpf *ftpf)
{
	ftpf->fmtlen = 0;
	ftpf->i = 0;
	ftpf->spec = "scdiuoxXpf%";
	ftpf->conv = "lhL";
	ftpf->arg = "-+ 0#";
	ftpf->fmtcpy = (char *)ftpf->fmt;
	ftpf->fmttreat = (char *)ftpf->fmt;
}
