#include <iostream>

int main(void) {
	int n[20];
	int menor(0);
	int posicao(0);

	std::cout << "n: ";
	

	for (int i = 0; i < 10; ++i){
		std::cin >> n[i];
	}

	for (int i = 0; i < 10; ++i){
		std::cout << "\n" << n[i];
	}
	menor = n[0];

	for (int i = 0; i < 10; ++i){
		if(n[i] < menor){
			menor = n[i];
			posicao = i;
		}
	}

	std::cout << "\n\nposicao: " << posicao;
	std::cout << "\nmenor: " << menor;

	return 0;
}