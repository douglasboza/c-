#include <iostream>

int main(void) {
	int n(0);
	int n2(0);
	int total(0);

	std::cout << "formato n n:" << std::endl;
	std::cin >> n;

	// [0, 25), [25, 50), [50, 75) e [75, 100].

	while(std::cin >> n >> n2) {	
		for (int i = 0; i < n2; ++i) {
			total += (n+i); 
		}
		std::cout << "teste t1: " << total << std::endl;
		n = 0;
		n2 = 0;
		total = 0;
	}
	
	return 0;
}