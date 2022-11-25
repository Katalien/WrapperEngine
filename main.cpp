#include<iostream>
#include"Subject.hpp"
#include"Engine.hpp"


int main() {
	Engine engine;
	Subject* sub = new Subject;
	Wrapper wrapper1(sub, &Subject::foo, { {"first", 1},{"second", 2} });
	Subject2* sub2 = new Subject2;
	Wrapper wrapper2(sub2, &Subject2::foo2, { {"firstStr", 5},{"secondStr", 6}, {"thirdStr", 7} });

	return 0;
}
