make re && cc test.c -L. -lft_test_mock_malloc && LD_LIBRARY_PATH=. ./a.out && echo "OK!" || echo "FAILED"
