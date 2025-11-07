#include <stdio.h>
int *search(int searchList[], int size, int target) {
    if (searchList == NULL || size == 0) {
        return NULL;  
    }
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Examining value: %d\n", searchList[mid]);

        if (searchList[mid] == target) {
            printf("Value found at index: %d\n", mid);
            return &searchList[mid]; 
        } 
        else if (target > searchList[mid]) {
            printf("Target is greater than midpoint value. Adjusting start to index: %d\n", mid + 1);
            start = mid + 1;
        } 
        else {
            printf("Target is less than midpoint value. Adjusting end to index: %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found in list.\n");
    return NULL; 
}
int main() {
    int searchList[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(searchList) / sizeof(searchList[0]);
    int target = 23;

    int *result = search(searchList, size, target);

    if (result != NULL) {
        printf("Search successful! Value: %d\n", *result);
    } else {
        printf("Search unsuccessful or invalid input.\n");
    }

    return 0;
}
