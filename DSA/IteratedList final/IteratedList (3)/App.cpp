#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

void testlastIndex();

int main() {
    testlastIndex();
	testAll();
	testAllExtended();
	std::cout << "Finished LP Tests!" << std::endl;
	system("pause");
}
