/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:34:12 by juhur             #+#    #+#             */
/*   Updated: 2022/07/11 15:20:42 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "minishell.h"

static char	**for_pipe(const char s, int *status)
{
	char	**ret;
	char	*arr;

	ret = _calloc(2, sizeof(char *));
	arr = _calloc(2, sizeof(char));
	arr[0] = s;
	arr[1] = '\0';
	ret[0] = arr;
	if (status)
		*status = STATUS_SYNTAX_ERROR;
	return (ret);
}

static int	count_word(const char *s, const char c)
{
	int		count;
	int		i;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c) && !quote && !dquote)
			count++;
		if (s[i] == '\'' && !dquote)
			quote ^= true;
		else if (s[i] == '\"' && !quote)
			dquote ^= true;
	}
	if (quote || dquote)
		return (-1);
	return (count);
}

static void	make_word(int len, char **ret, char *s)
{
	char	*arr;

	arr = _calloc(len + 1, sizeof(char));
	*ret = arr;
	while (len)
		*(arr++) = *(s - len--);
	*arr = '\0';
}

static void	make_array(char **ret, char *s, char c, int word_cnt)
{
	int		len;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	while (word_cnt--)
	{
		while (*s != '\0' && *s == c)
			++s;
		len = 0;
		while (*s && (c != *s || quote || dquote))
		{
			if (*s == '\'' && !dquote)
				quote ^= true;
			else if (*s == '\"' && !quote)
				dquote ^= true;
			++s;
			++len;
		}
		make_word(len, ret, s);
		++ret;
	}
}

char	**_split(const char *s, const char c, int *status)
{
	char	**ret;
	int		word_cnt;

	if (s == NULL)
		return (NULL);
	if (s[0] == '|' && s[1] == 0)
		return (for_pipe(s[0], status));
	word_cnt = count_word((char *)s, c);
	if (word_cnt <= 0)
		return (NULL);
	ret = _calloc(word_cnt + 1, sizeof(char *));
	make_array(ret, (char *)s, c, word_cnt);
	return (ret);
}
