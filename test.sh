make re && cc test.c -L. -lft_test_mock_malloc && LD_LIBRARY_PATH=. LD_PRELOAD=libft_test_mock_malloc.so ./a.out
