#include<iostream>

class Subject {
public:
	Subject() = default;

	void print(int a) {
		std::cout << a << std::endl;
	}

	int foo(int a, int b) {
		std::cout << "first " <<  a << " second " << b << std::endl;
		return 0;
	}
};

class Subject2 {
public:
	Subject2() = default;

	void print(int a) {
		std::cout << a << std::endl;
	}

	int foo2(int a, int b, int c) {
		std::cout << "first " << a << " second " << b <<  " third " << c << std::endl;
		return 0;
	}
};