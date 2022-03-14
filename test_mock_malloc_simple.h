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

#ifndef TEST_MOCK_MALLOC_SIMPLE_H
# define TEST_MOCK_MALLOC_SIMPLE_H

# include <stddef.h>
# include <stdbool.h>

void	ft_test_mock_malloc_simple__set_before(
			bool (*handler)(size_t size));

void	ft_test_mock_malloc_simple__set_after(
			void (*handler)(size_t size, bool ok, void *address));

#endif
