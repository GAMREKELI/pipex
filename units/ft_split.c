/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:39:00 by pdursley          #+#    #+#             */
/*   Updated: 2021/10/23 22:39:01 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// static char	*ft_writing_word(char *dst, char const *src, char ch)
// {
// 	int	j;
// 	int	i;

// 	i = 0;
// 	j = 0;
// 	while ((src[i] == ch || src[i] == '\0') == 0)
// 	{
// 		dst[j] = src[i];
// 		j++;
// 		i++;
// 	}
// 	dst[j] = '\0';
// 	return (dst);
// }

// static int	ft_wordlen(char const *w, char c)
// {
// 	int	count;

// 	count = 0;
// 	while ((*w == c || *w == '\0') == 0)
// 	{
// 		w++;
// 		count++;
// 	}
// 	return (count);
// }

// static int	kol_word(char const *str, char ch)
// {
// 	int	kol;

// 	kol = 0;
// 	while (*str != '\0')
// 	{
// 		if (*str != ch)
// 		{
// 			kol++;
// 			while ((*str == ch || *str == '\0') == 0)
// 				str++;
// 		}
// 		else
// 		{
// 			str++;
// 		}
// 	}
// 	return (kol);
// }

// static	char	**ft_result_res(char **res, char c, char const *s)
// {
// 	unsigned int	i;
// 	unsigned int	k;
// 	char			*word;

// 	i = 0;
// 	k = -1;
// 	while (s[i] != '\0')
// 	{
// 		if ((s[i] == c || s[i] == '\0') == 1)
// 			i++;
// 		else
// 		{
// 			word = (char *)malloc((ft_wordlen(&s[i], c) + 1) * sizeof(char));
// 			if (!word)
// 				return (NULL);
// 			res[++k] = ft_writing_word(word, &s[i], c);
// 			while ((s[i] == c || s[i] == '\0') == 0)
// 				i++;
// 		}
// 	}
// 	res[++k] = NULL;
// 	return (res);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int		n;

// 	if (!s)
// 		return (NULL);
// 	n = kol_word(s, c);
// 	if (!n)
// 		return (NULL);
// 	res = (char **)malloc((n + 1) * sizeof(char *));
// 	if (res == 0)
// 		return (NULL);
// 	res = ft_result_res(res, c, s);
// 	return (res);
// }

static size_t	words_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			j++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		j++;
	return (j);
}

static char	*word(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_arr(char **arr, char *s)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(s);
	return (NULL);
}

static char	**worker(char **arr, char *s1, char c, size_t j)
{
	size_t	i;
	char	*str;

	str = s1;
	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			arr[i] = word(s1, c);
			if (!arr[i])
				return (free_arr(arr, s1));
			s1 = s1 + ft_strlen(arr[i]);
			i++;
		}
		s1++;
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	char	*s1;
	size_t	j;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	j = words_count(s1, c);
	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!w_arr)
		return (NULL);
	return (worker(w_arr, s1, c, j));
}

