/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:41:08 by pdursley          #+#    #+#             */
/*   Updated: 2021/11/14 14:41:10 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	char			*string;
	unsigned char	c;

	c = (char)ch;
	string = (char *)str;
	while (*string != c)
	{
		if (*string == '\0')
		{
			return ((char *) NULL);
		}
		string++;
	}
	return (string);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// char	*ft_strdup(const char *str)
// {
// 	char	*string;
// 	int		len;
// 	int		i;

// 	len = ft_strlen(str);
// 	string = malloc(sizeof(char) * len + 1);
// 	if (string == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (len != 0)
// 	{
// 		string[i++] = *(str++);
// 		len--;
// 	}
// 	string[i] = '\0';
// 	return (string);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*result;
// 	int		i;

// 	i = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (result == NULL)
// 		return (NULL);
// 	while (*s1 != '\0')
// 		result[i++] = *(s1++);
// 	while (*s2 != '\0')
// 		result[i++] = *(s2++);
// 	result[i] = '\0';
// 	return (result);
// }
