#ifndef SEARCHING_H
#define SEARCHING_H

#include "Product.h"

// --- Binary Search implementation (Searching by ID) ---
// Note: Binary Search requires a sorted array by the key being searched.
int binarySearch(Product arr[], int low, int high, int targetId) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].id == targetId)
            return mid;

        if (arr[mid].id < targetId)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

#endif
