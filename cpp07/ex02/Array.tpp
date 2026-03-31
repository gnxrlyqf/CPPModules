template <typename T>
Array<T>::Array() {
	arr = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &other) {
	_size = other._size;
	arr = new T[_size];
	for (unsigned int i = 0; i < _size; ++i) {
		arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		T* new_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i) {
			new_arr[i] = other.arr[i];
		}
		delete[] arr;
		arr = new_arr;
		_size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index > _size - 1)
		throw (std::out_of_range("Index out of range."));
	return (arr[index]);
}
