#include <iostream> // cout, endl
#include <iterator> // begin, end



void swap_2(void* fist, void *last, size_t size){

		// int aux;

		byte aux(size);

		byte * fisrt = static_cast<(byte *> (f); 
		// aux = *(first + 1);
		// *(fist + 1) = *(first + 3);
		// *(first + 3) = aux;
		memcpy(aux, first + (1 * size), size);  
		memcpy(fist + (1 * size), fist + (3 * size), size)
		memcpy(fist + (3 * size), aux, size);


		// aux = *(first + 1 * size);
		// *(fist + 1 * size) = *(first + 3 * size);
		// *(first + 3 * size) = aux;


		// aux = *(first + 1 * size);
		// *(fist + 1 * size) = *(first + 3 * size);
		// *(first + 3 * size) = aux;


}



int main(void){
	int a[]{1,2,3,4,5,6,7,8};
	int a[]{"um", "dois", "tres", "quatro"};


	swap_2(std::begin(A), std::end(A), sizeof(A[0]));

	swap_2(std::begin(B), std::end(B), sizeof(B[0]));



	return 0;
}