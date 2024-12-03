#include <stdio.h>


void quickSort(int array[], int l, int r) {
    if (l >= r) {
         return;
    }
    int p = array[l];
    int i = l, j = r;
    while (i <= j) {
        while (array[i] < p) i++;
	while (array[j] > p) j--;
	if (i < j) {
            int tmp = array[i];
	    array[i] = array[j];
	    array[j] = tmp;
	}
	if (i <= j) {
            i++;
	    j--;
	}
    }
    quickSort(array, l, j);
    quickSort(array, i, r);
}


int main() {
    int size;
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    quickSort(array, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
