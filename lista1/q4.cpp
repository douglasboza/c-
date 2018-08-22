#include <iostream>

int main(void) {
	int tot(0);
	int a1(1);
	int a2(1);
	int n(0);

	std::cout << "n: ";
	std::cin >> n;
	std::cout << "\n" << a1;
	std::cout << "\n" << a2;

	while((tot+a1) < n){
		tot = a1 + a2;
		std::cout << "\n" << tot << std::endl;
		a1 = a2;
		a2 = tot;
	}

	return 0;
}