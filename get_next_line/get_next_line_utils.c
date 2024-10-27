/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utild.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpillco- <kpillco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:55 by kpillco-          #+#    #+#             */
/*   Updated: 2024/10/24 15:13:10 by kpillco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    if (!dest || !src)
        return NULL;

    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n--)
        *d++ = *s++;

    return dest;
}

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL)
        return malloc(new_size);

    void *new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;

    size_t size_to_copy = (old_size < new_size) ? old_size : new_size;

    ft_memcpy(new_ptr, ptr, size_to_copy);

    free(ptr);

    return new_ptr;
}