#ifndef _UNIFORM_H_
#define _UINFORM_H_

#include <vector>

template<typename T>

class Uniform
{
private:
	Uniform();
	Uniform(const Uniform&);
	Uniform& operator=(const Uniform&);
	~Uniform();

public:
	static void Set(unsigned int slot, const T& value);
	static void Set(unsigned int slot, T* arr, unsigned int len);
	static void Set(unsigned int slot, std::vector<T>& arr);
};

#endif //!_UNIFORM_H_