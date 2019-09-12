/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:26:31 by gmachado          #+#    #+#             */
/*   Updated: 2019/08/26 19:34:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_intlen(int n)
{
    int i;

    i = (n <= 0) ? 1 : 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}