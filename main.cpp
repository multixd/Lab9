 #include <iostream>
 #include <algorithm>
 #include <time.h>
 
 using namespace std;
 
 const int NUMBERS_SIZE = 50000;
 const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
 
 int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void swap(int *numbers, int i, int j) {
	int temp = numbers[j];
	numbers[j] = numbers[i];
	numbers[i] = temp;
}

void InsertionSort(int numbers[], int numberSize) {
	for(int i = 0; i < numberSize; ++i) {
		int j = i;
		while(j>0 && numbers[j]<numbers[j-1]){
			swap(numbers,j,j-1);
			--j;
		}
	}
}

int Partition_two(int numbers[], int i, int k) {
	int pivot = numbers[(i+k)/2];
	bool done = false;
	
	int l = i;
	int h = k;
	
	while(!done) {
		while(numbers[l] < pivot) {
			++l;
		}
		while(numbers[h] > pivot) {
			--h;
		}
		if(l >= h) {
			done = true;
		}
		else{
			swap(numbers,l,h);
			--h;
			++l;
		}
	}
	
	return h;
}

int Partition_three(int numbers[], int i, int k) {
	int pivot;
	int a = numbers[i];
	int b = numbers [i+k]/2;
	int c = numbers[k];
	

	if ((a <= b && b <= c) || (c <= b && b <= a)) {
       pivot= b; 
   }
  
    else if ((b <= a && a <= c) || (c <= a && a <= b)) {
       pivot=  a; 
   }
  
    else {
       pivot= c; 
 }
	
	int l = i;
	int h = k;
	bool done = false;
	

	
	while(!done) {
		while(numbers[l] < pivot) {
			++l;
		}
		while(numbers[h] > pivot) {
			--h;
		}
		if(l >= h) {
			done = true;
		}
		else{
			swap(numbers,l,h);
			--h;
			++l;
		}
	}
	
	return h;
}
	

void Quicksort_midpoint(int numbers[], int i, int k) {
	if(i >= k){
		return;
	}
	
	int j = Partition_two(numbers,i,k);
	
	Quicksort_midpoint(numbers,i,j);
	Quicksort_midpoint(numbers,j+1,k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
	if(i >= k){
		return;
	}

	int j = Partition_two(numbers,i,k);
	
	Quicksort_medianOfThree(numbers,i,j);
	Quicksort_medianOfThree(numbers,j+1,k);
}
				
 int main() {
	 int arr1[NUMBERS_SIZE];
	 int arr2[NUMBERS_SIZE];
	 int arr3[NUMBERS_SIZE];
	
	fillArrays(arr1,arr2,arr3);
	
	
	clock_t Start = clock();
	Quicksort_medianOfThree(arr1,0,NUMBERS_SIZE);
	clock_t End = clock();
	int elapsedTime = (End - Start)/CLOCKS_PER_MS;
	std::cout << "Elapsed Time for QuickSort Median: " << elapsedTime << std::endl;
	
	
	
	clock_t Start2 = clock();
	Quicksort_midpoint(arr2,0,NUMBERS_SIZE);
	clock_t End2 = clock();
	 elapsedTime = (End2 - Start2)/CLOCKS_PER_MS;
	std::cout << "Elapsed Time for QuickSort Midpoint: " << elapsedTime << std::endl;
	
	clock_t Start3 = clock();
	InsertionSort(arr3,NUMBERS_SIZE);
	clock_t End3 = clock();
	elapsedTime = (End3 - Start3)/CLOCKS_PER_MS;
	std::cout << "Elapsed Time for Insertion Sort: " << elapsedTime << std::endl;
	

	 
	 return 0;
 }
