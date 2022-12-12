#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// swap 2 random elements of arr
void swap_random(int* arr, int n) {

	int r1, r2, temp;
	srand(time(0));
	r1 = rand() % n;
	r2 = rand() % n;
	temp = arr[r1];
	arr[r1] = arr[r2];
	arr[r2] = temp;

}

// returns 1 if arr is sorted in ascending order
// otherwise returns 0
int is_sorted(int* arr, int n) {

	int i;
	for (i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

// bogosort function
void bogosort(int* arr, int n) {

	while (!is_sorted(arr, n)) {
		swap_random(arr, n);
	}

}

int main() {

	int n;
	clock_t t;
	char arr[100];

	printf("Enter size of array: ");
	scanf("%d", &n);

	printf("Enter Array Elements: ");
	for (int i = 0; i < n; ++i) {
		scanf("%c", &arr[i]);
	}

	t = clock();
	bogosort(arr, n);
	t = clock() - t;

	printf("Array After Sort: ");
	for (int i = 0; i < n; ++i) {
		printf("%c ", arr[i]);
	}
	printf("\nTime Taken to sort: %llf", ((double)t) / CLOCKS_PER_SEC);

}