#include <stdio.h>
#include <assert.h>

int count_unique_elements_divisible_by_k(int arr[], int size, int k) {
    int unique_elements[1000] = {0}; 
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % k == 0) {
            int isUnique = 1;
            for (int j = 0; j < count; j++) {
                if (unique_elements[j] == arr[i]) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                unique_elements[count] = arr[i];
                count++;
            }
        }
    }

    return count;
}

void test_allElements(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 10;

    int result = count_unique_elements_divisible_by_k(arr, size, k);
    assert(result == 10);
}

void test_noNeedElements(){
    int arr[] = {7, 9, 11, 13, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int result = count_unique_elements_divisible_by_k(arr, size, k);
    assert(result == 0);
}

void test_severalElements(){
    int arr[] = {3, 7, 9, 11, 13, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = count_unique_elements_divisible_by_k(arr, size, k);
    assert(result == 2);
}

int main() {
    test_allElements();
    test_noNeedElements();
    test_severalElements();

    return 0;
}
