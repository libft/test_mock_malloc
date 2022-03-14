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

#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>

#include "test_mock_malloc_simple.h"

static void	*handler(size_t size, void *(*real_malloc)(size_t size))
{
	static bool	skip = false;

	if (skip)
		return (real_malloc(size));
	skip = true;
	printf("malloc(%zu) called\n", size);
	skip = false;
	return (real_malloc(size));
}

int	main(void)
{
	ft_test_mock_malloc_simple_set_handler(handler);
	malloc(1024);
	return (0);
}
