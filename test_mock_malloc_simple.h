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

void	ft_test_mock_malloc_simple_set_handler(
			void *(*handler)(size_t size, void *(*real_malloc)(size_t size)));

#endif
