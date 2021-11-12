/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:57:33 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/12 23:50:58 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	int	is;

	is = 0;
	while (n-- > 0)
		((char *)s)[is++] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (s2 == NULL)
		return (NULL);
	res = malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)) * sizeof(char));
	if (! res)
		return (NULL);
	ft_bzero(res, ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	i1 = 0;
	while (s1[i1] != '\0')
		res[ires++] = s1[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		icopy;
	int		istr;

	icopy = 0;
	istr = 0;
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (! copy)
		return (NULL);
	while (s1[istr] != '\0')
		copy[icopy++] = s1[istr++];
	copy[icopy] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	isub;

	isub = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		substr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	while (isub < len && s[start] != '\0')
		substr[isub++] = s[start++];
	substr[isub] = '\0';
	return (substr);
}
