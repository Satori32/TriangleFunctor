#include <iostream>

#include "TriangleFuncter.h"

int main() {

	TriangleFuncter<bool, int> TF;

	TF.Push([](int A)->bool {return A % 16; });
	TF.Push([](int A)->bool {return A % 3; });
	TF.Push([](int A)->bool {return A % 7; });

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