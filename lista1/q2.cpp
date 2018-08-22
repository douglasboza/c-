#include <iostream>

int main(void) {
	int n(0);
	int tot1(0);
	int tot2(0);
	// int tot3(0);
	// int tot4(0);

	std::cout << "total de negativos:" << std::endl;

	// [0, 25), [25, 50), [50, 75) e [75, 100].

	while(std::cin >> n){
		std::cout << "n:" << n << std::endl;

		if((n >= 0) && (n < 25)){
			tot1++;
		}else{
			if((n >= 25) && (n < 50)){	
				tot2++;
			}
		}
	

	}

	std::cout << "teste t1: " << tot1 << std::endl;



	
	return 0;
}