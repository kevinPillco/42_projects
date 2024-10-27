/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpillco- <kpillco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:49 by kpillco-          #+#    #+#             */
/*   Updated: 2024/10/24 15:28:55 by kpillco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

char *get_next_line(int fd);
void ft_print_string(const char *text, size_t buffer_size);
static int	count_words(char const *s, char c);

static char	*get_next_word(char const **s, char c);
char	**ft_split(char const *s, char c);
char *get_text(int fd);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);


#endif