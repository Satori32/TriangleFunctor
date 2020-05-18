#pragma once

#include <functional>
#include <vector>

//triangle but not the count three.

template<class R,class... Arg>
class TriangleFunctor {
protected:
	typedef std::function<R(Arg...)> Fun;
	typedef std::vector<Fun> Functions;
public:
	TriangleFunctor() {}
	TriangleFunctor(const std::initializer_list<Fun>& In):F(In.begin(),In.end()){}
	bool Push(const Fun& Fu) {
		F.push_back(Fu);
		return true;
	}
	bool Calculation(const Arg&... A) {
		for (auto& o : F) {
			if (!o(A...)) { return false; }
		}

		return true;
	}

	Fun& operator[](std::size_t I) {
		return F[I];
	}
	std::size_t Size() {
		return F.size();
	}

	typename Functions::iterator begin() {
		return F.begin();
	}
	typename Functions::iterator End() {
		return F.end();
	}

protected:
	Functions F;
};