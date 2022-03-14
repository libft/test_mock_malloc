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

static bool	(*g_before)(size_t size);
static void	(*g_after)(size_t size, bool ok, void *address);

void	ft_test_mock_malloc_simple__set_before(
			bool (*handler)(size_t size))
{
	g_before = handler;
}

void	ft_test_mock_malloc_simple__set_after(
			void (*handler)(size_t size, bool ok, void *address))
{
	g_after = handler;
}

void	*malloc(size_t size)
{
	static void	*(*real_malloc)(size_t size) = NULL;
	bool		ok;
	void		*result;

	if (real_malloc == NULL)
	{
		real_malloc = (void *(*)(size_t size))
			dlsym((void *)((intptr_t)(-1)), "malloc");
	}
	ok = (!g_before || g_before(size));
	if (ok)
		result = NULL;
	else
		result = NULL;
	if (g_after)
		g_after(size, ok, result);
	return (result);
}
