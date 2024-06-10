#include <stdio.h>

int count_unique_elements_divisible_by_k(int arr[], int size, int k) {
    int unique_elements[1000] = {0}; // Предполагаем, что максимальное значение элемента в массиве не превышает 1000
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

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 10;

    int result = count_unique_elements_divisible_by_k(arr, size, k);
    printf("Количество уникальных элементов, делящихся на %d: %d\n", k, result);

    return 0;
}
