/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:13:07 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/27 19:18:12 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)

{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
/* 
int main(void)
{
	int	c;
	c = 'b';
	printf("%d \n",ft_isprint(c));
	printf("%d \n",isprint(c));
	return(0);
} */