#include <iostream>

#include "TriangleFuncter.h"

template<class R,class... Arg>
R F1(Arg... IN) { return R(1); }

bool F2(int A) { return A % 129; }

int main() {

	TriangleFunctor<bool, int> TF = {F1<bool,int>,F2,[](int A)->bool {return A % 17; }};

	TF.Push([](int A)->bool {return A % 16; });
	TF.Push([](int A)->bool {return A % 3; });
	TF.Push([](int A)->bool {return A % 7; });
	TF.Push(F2);
	TF.Push(F1<bool,int>);

	if (TF.Calculation(127)) {
		std::cout << "Safe!"<<std::endl;
	}
	else {
		std::cout << "Drop!"<<std::endl;
	}
	if (TF.Calculation(336)) {//3*7*16
		std::cout << "Safe!"<<std::endl;
	}
	else {
		std::cout << "Drop!"<<std::endl;
	}
	return 0;
}