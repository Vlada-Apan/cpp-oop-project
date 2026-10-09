#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
template <typename T>
class Vector {
	T* data;
	int capacity;
	int size;

	void _resize_capacity(int new_capacity) {
		T* new_data = new T[new_capacity];
		for(int i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}

public:
	Vector() : data(nullptr), capacity(0), size(0) {}

	explicit Vector(int s, T value = T()) :
		data(new T [s]), size(s), capacity(s) {
		for(int i = 1; i < size; i++) {
			data[i] = value;
		}
	}
	~Vector() {
		delete[] data;
	}

	Vector(const Vector& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	Vector& operator=(const Vector& other) {
		if(this == &other)
			return this* ;

		delete[] data;
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];
		for(int i = 0; i < size; i ++) {
			data[i] = other.data[i];
		}
		return *this;
	}

	void push_back(const T& value) {
		if(size == capacity) {
			int new_cap = (capacity == 0) ? 1 : capacity * 2;
			T* new_data = new T[new_cap];
			for(int i = 0; i < size; i++) {
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			capacity = new_cap;
		}
		data[size++] == value;
	}

	T& operator[](int index) {
		return data[index];
	}

	const T& operator[](int index) const {
		return data[index];
	}

	void pop_back() {
		if(size > 0) {
			size--;
		}
	}

	T& at(int index) {
		if(index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	const T& at(int index) const {
		if(index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}
	T& front() {
		if(size == 0) throw
			std::out_of_range("Vector is empty");
		return data[0];
	}

	const T& front() const {
		if(size == 0) throw
			std::out_of_range("Vector is empty");
		return data[0];
	}

	T& back() {
		if(size == 0) throw
			std::out_of_range("Vector is empty");
		return data[size - 1];
	}

	const T& back() const {
		if(size == 0) throw
			std::out_of_range("Vector is empty");
		return data[size - 1];
	}

	int getSize() const {
		return size;
	}

	int getCapacity() const {
		return capacity;
	}

	bool empty() const {
		return size == 0;
	}

	void reserve (int new_capacity) {
		if(new_capacity > capacity) {
			T* new_data = new T[new_capacity];
			for(int i = 0; i < size; i++) {
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			capacity = new_capacity;
		}
	}

	void clear() {
		size = 0;
	}

	T* begin() {
		return data;
	}

	const T* begin() const {
		return data;
	}

	T* end() {
		return data + size;
	}

	const T* end() const {
		return data + size;
	}
};

void test_default_constructor() {
	Vector<int> v;

	assert(v.size() == 0);
	assert(v.empty() == true);

	v.push_back(1);
	assert(v.size() == 1);

	std::cout << "passed" << std::endl;
}
void test_destructor() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);

	Vector<int> v;
}
std::cout << "passed" << std::endl;
}
void test_copy_constructor() {
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	Vector<int> v2(v1);
	assert(v2.size() == 3);
	assert(v2[0] == 1);
	assert(v2[1] == 2);
	assert(v2[2] == 3);

	v2[0] = 100;
	assert(v1[0] == 1);
	assert(v2[0] == 100);

	Vector<int> empty;
	Vector<int> copy_empty(empty);
	assert(copy_empty.size() == 0);

	std::cout << "passed" << std::endl;
}
void test_assignment_operator() {
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);

	Vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);

	v2 = v1;
	assert(v2.size() == 2);
	assert(v2[0] == 1);
	assert(v2[1] == 2);

	v1 = v1;
	assert(v1.size() == 2);
	assert(v1[0] == 1);

	std::cout << "passed" << std::endl;
}

void test_push_back() {
	Vector<int> v;

	v.push_back(5);
	assert(v.size() == 1);
	assert(v[0] == 5);

	v.push_back(10);
	v.push_back(15);
	assert(v.size() == 3);
	assert(v.back() == 15);

	Vector<int> v2;
	for (int i = 0; i < 100; i++) {
		v2.push_back(i);
	}
	assert(v2.size() == 100);
	assert(v2[99] == 99);

	std::cout << "passed" << std::endl;
}
void test_pop_back() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.pop_back();
	assert(v.size() == 2);
	assert(v.back() == 2);

	v.pop_back();
	assert(v.size() == 1);
	assert(v.back() == 1);

	Vector<int> empty;
	empty.pop_back();
	assert(empty.size() == 0);

	std::cout << "passed" << std::endl;
}
void test_operator_bracket() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	assert(v[0] == 10);
	assert(v[1] == 20);
	assert(v[2] == 30);

	v[1] = 99;
	assert(v[1] == 99);

	assert(v[0] == 10);
	assert(v[2] == 30);

	std::cout << "passed" << std::endl;
}
void test_back() {
	Vector<int> v;

	v.push_back(42);
	assert(v.back() == 42);

	v.push_back(100);
	assert(v.back() == 100);

	v.push_back(7);
	assert(v.back() == 7);

	std::cout << "passed" << std::endl;
}
void test_front() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	assert(v.front() == 1);

	v.front() = 100;
	assert(v.front() == 100);
	assert(v[0] == 100);


	Vector<int> single;
	single.push_back(5);
	assert(single.front() == 5);
	assert(single.back() == 5);

	std::cout << "passed" << std::endl;
}
void test_insert() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.insert(1, 99);
	assert(v.size() == 4);
	assert(v[0] == 1);
	assert(v[1] == 99);
	assert(v[2] == 2);
	assert(v[3] == 3);

	v.insert(0, 0);
	assert(v[0] == 0);
	assert(v.size() == 5);

	v.insert(v.size(), 100);
	assert(v.back() == 100);

	std::cout << "passed" << std::endl;
}
void test_erase() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.erase(1);
	assert(v.size() == 3);
	assert(v[0] == 1);
	assert(v[1] == 3);
	assert(v[2] == 4);

	v.erase(0);
	assert(v[0] == 3);

	v.erase(v.size() - 1);
	assert(v.size() == 1);

	std::cout << "passed" << std::endl;
}
void test_swap() {
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);

	Vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);

	v1.swap(v2);
	assert(v1.size() == 3);
	assert(v1[0] == 10);
	assert(v2.size() == 2);
	assert(v2[0] == 1);

	Vector<int> empty;
	v1.swap(empty);
	assert(v1.size() == 0);
	assert(empty.size() == 3);

	std::cout << "passed" << std::endl;
}
void test_clear() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.clear();
	assert(v.size() == 0);
	assert(v.empty() == true);

	v.clear();
	assert(v.size() == 0);

	v.push_back(42);
	assert(v.size() == 1);
	assert(v[0] == 42);

	std::cout << "passed" << std::endl;
}
void test_resize() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.resize(5);
	assert(v.size() == 5);
	assert(v[0] == 1);
	assert(v[2] == 3);

	v.resize(2);
	assert(v.size() == 2);
	assert(v[0] == 1);
	assert(v[1] == 2);

	v.resize(0);
	assert(v.size() == 0);
	assert(v.empty() == true);

	std::cout << "passed" << std::endl;
}
int main() {

	test_default_constructor();
	test_destructor();
	test_copy_constructor();
	test_assignment_operator();
	test_push_back();
	test_pop_back();
	test_operator_bracket();
	test_back();
	test_front();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_resize();

	std::cout << "All tests passed" << std::endl;
	return 0;
}
