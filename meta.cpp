#include <iostream>

#define M 17

template<unsigned int d>
struct divisible {
	static const bool isPrime = (M % d) && divisible<d-1>::isPrime;
	long long v[isPrime];
};

template<>
struct divisible<2> {
	static const bool isPrime = M % 2;
	long long v[isPrime];	
};

template<>
struct divisible<1> {
	static const bool isPrime = true;
	long long v[isPrime];
};

template<>
struct divisible<0> {
	static const bool isPrime = false;
	long long v[0];
};

template<>
struct divisible<-1> {
	static const bool isPrime = false;
	long long v[0];
};


struct divisible<M-1> foo;

int main() {
	std::cout << (foo.isPrime ? "Prime " : "Not prime ") << sizeof(foo) << std::endl;
}