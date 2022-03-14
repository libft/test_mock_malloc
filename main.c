/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <dlfcn.h>

#include "test_mock_malloc_simple.h"

static void	*(*g_handler)(size_t size, void *(*real_malloc)(size_t size));

void	ft_test_mock_malloc_simple_set_handler(
			void *(*handler)(size_t size, void *(*real_malloc)(size_t size)))
{
	g_handler = handler;
}

void	*malloc(size_t size)
{
	static void	*(*real_malloc)(size_t size) = NULL;

	if (real_malloc == NULL)
	{
		real_malloc = (void *(*)(size_t size))
			dlsym((void *)((intptr_t)(-1)), "malloc");
	}
	if (g_handler)
		return (g_handler(size, real_malloc));
	else
		return (real_malloc(size));
}
