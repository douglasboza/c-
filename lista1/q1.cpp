#include <iostream>

int main(void) {
	int expo(0);
	int tot(0);

	for (int i = 0; i < 5; ++i){
		std::cout << "Entre com um valor:"<< std::endl;
    	std::cin >> expo;
    	if(expo < 0) tot++;

	}

    std::cout << "total de negativos:" << tot << std::endl;



	
	return 0;
}