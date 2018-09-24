#include <iostream> // cout, endl
#include <iterator> // begin, end




// using Compare = int(const void*, const void*);

// void sort_bubble_2(const void* first, const void* last, size_t size, Compare *cmp){

// }


// int compare_int(const void *a, const void *b){
// 	const int *aa = static_cast < para onde eu vou??? > (a);
// 	const int *bb = (const int *) b;

// 	if(*aa > *bb){
// 		return -1
// 	}


// }





using Compare = bool (*)(const void *, const void *);

bool cmp(const void*, const void*){
	return true;
}

const void *min(const void *first, const void *last, size_t size, Compare cmp){
	first[1] = 10; 

	 std::cout << "-- ok --" << std::endl;
}


int main(int argc, char const *argv[]){

	int Vetor[5]={ 1, 2, -3, 4, 0 };

	const int * result_A = (const int *) min(std::begin(Vetor), std::end(Vetor), sizeof(int), cmp);

	
	return 0;
}