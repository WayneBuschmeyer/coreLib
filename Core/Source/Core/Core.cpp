#include "Core.h"

#include "io.h"

namespace core {

	void PrintHelloWorld()
	{
		ns::cout << "Hello World from coreLib\n";
    	ns::cout << "Example value: " << 42 << '\n';
		std::cin.get();
	}

}
