/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:55:16 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/02 12:19:01 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  count_words(char *s, char c)
{
    int     count;
    bool    inside_word;

    count = 0;
    while (*s)
    {
        inside_word = false;
        while (*s == c)
            s++;
        while (*s != c && *s)
        {
            if (!inside_word)
            {
                ++count;
                inside_word = true;    
            }
            ++s;
        }
    }
    return (count);
}

static char *get_next_word(char *s, char c)
{
    char    *word;
    int     i;

    i = 0;
    while (s[i] != c && s[i])
        ++i;
    word = malloc(sizeof(char) * (size_t)(i + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (*s != c && *s)
        word[i++] = *s++;
    word[i] = '\0';
    return (word);
}

char    **split(char *s, char c)
{
    int     words_count;
    char    **result_array;
    int     i;

    i = 0;
    words_count = count_words(s, c);
    if (!words_count)
        exit(1);
    result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
    //I need to better understand why '+ 2' is used here
    if (!result_array)
        return (NULL);
    while (words_count-- >= 0)
    {
        if (i == 0)
        {
            result_array[i] = malloc(sizeof(char));
            if (!result_array[i])
                return (NULL);
            result_array[i++][0] = '\0';
            continue;    
        }
        result_array[i++] = get_next_word(s, c);
    }
    result_array[i] = NULL;
    return (result_array);
}