#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

//total swaps should be half of the cumulative swaps of every individual value due to each swap involving the
//movement of two value in the array.

int main(){
    int array1_1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72}, array2_1[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1_2[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72}, array2_2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int counts[SIZE], total;

    printf("Bubble sort array 1\n");
    total = bubble(array1_1, counts, SIZE);
    print_array(array1_1, counts, SIZE);
    printf("total: %d\n", total);
    
    printf("Bubble sort array 2\n");
    total = bubble(array2_1, counts, SIZE);
    print_array(array2_1, counts, SIZE);
    printf("total: %d\n\n", total);

    printf("Selection sort array 1\n");
    total = selection(array1_2, counts, SIZE);
    print_array(array1_2, counts, SIZE);
    printf("total: %d\n\n", total);

    printf("Selection sort array 2\n");
    total = selection(array2_2, counts, SIZE);
    print_array(array2_2, counts, SIZE);
    printf("total: %d\n\n", total);
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubble(int array[], int swaps[], int n){
    int i, j, count = 0;
    for(i = 0; i < n; i++){
        swaps[i] = 0;
    }
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(array[j] > array[j + 1]){
                swaps[j]++;
                swaps[j+1]++;
                swap(&array[j], &array[j + 1]);
                swap(&swaps[j], &swaps[j + 1]);
                count++;
            }
        }
    }
    return count;
}

int selection(int array[], int swaps[], int n){
    int i, j, min, temp, count = 0, temp2;
    for(i = 0; i < n; i++){
        swaps[i] = 0;
    }
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        swaps[i]++;
        swaps[min]++;
        temp = array[i];
        temp2 = swaps[i];
        array[i] = array[min];
        swaps[i] = swaps[min];
        array[min] = temp;
        swaps[min] = temp2;
        count++;
    }
    return count;
}

void print_array(int array[], int swaps[], int n){
    int i, total;
    for(i = 0; i < n; i++){
        printf("%d: %d\n", array[i], swaps[i]);
        total += swaps[i];
    }
}