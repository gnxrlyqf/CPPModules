#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>

template <typename T>
void iter(T *arr, size_t size, void (*f)(T e)) {
	if (!arr || !f)
		return;
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

#endif