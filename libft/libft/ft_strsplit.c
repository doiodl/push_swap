/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:31:43 by btheia            #+#    #+#             */
/*   Updated: 2019/09/13 16:13:19 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (s[0] == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char		**deltab(char **tab, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	word_number;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	word_number = word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word_number + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i] = ft_strsub(s, j, word_len(s + j, c));
		if (tab[i] == NULL)
			return (deltab(tab, i));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
