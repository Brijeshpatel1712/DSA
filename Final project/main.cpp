#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Sorting.h"
#include "Searching.h"

using namespace std;

// Helper function to display an array of products
void displayArray(Product arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "ID: " << arr[i].id 
             << " | Name: " << arr[i].name 
             << " | Price: $" << arr[i].price << "\n";
    }
}

int main() {
    LinkedList inventory;
    int choice;

    do {
        cout << "\n============================================\n";
        cout << "       E-Commerce Inventory Management      \n";
        cout << "============================================\n";
        cout << "1. Add a New Product (Linked List Insert)\n";
        cout << "2. Display All Products (Linked List Traversal)\n";
        cout << "3. Sort Products by Price (Merge Sort)\n";
        cout << "4. Sort Products by ID (Quick Sort)\n";
        cout << "5. Search Product by ID (Binary Search)\n";
        cout << "6. Exit\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                double price;
                cout << "\n--- Adding New Product ---\n";
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin >> ws; // clear whitespace before getline
                getline(cin, name);
                cout << "Enter Product Price: ";
                cin >> price;
                inventory.addProduct(Product(id, name, price));
                break;
            }
            case 2:
                cout << "\n--- All Products in Inventory ---\n";
                inventory.displayProducts();
                break;
            case 3: {
                int size = inventory.getSize();
                if (size == 0) {
                    cout << "\nNo products to sort!\n";
                    break;
                }
                Product* arr = inventory.toArray();
                mergeSort(arr, 0, size - 1);
                cout << "\n--- Products Sorted by Price (Ascending) ---\n";
                displayArray(arr, size);
                delete[] arr; // free allocated memory
                break;
            }
            case 4: {
                int size = inventory.getSize();
                if (size == 0) {
                    cout << "\nNo products to sort!\n";
                    break;
                }
                Product* arr = inventory.toArray();
                quickSort(arr, 0, size - 1);
                cout << "\n--- Products Sorted by ID (Ascending) ---\n";
                displayArray(arr, size);
                delete[] arr;
                break;
            }
            case 5: {
                int size = inventory.getSize();
                if (size == 0) {
                    cout << "\nNo products to search!\n";
                    break;
                }
                int targetId;
                cout << "\nEnter Product ID to search: ";
                cin >> targetId;

                Product* arr = inventory.toArray();
                // Binary Search only works on sorted arrays. 
                // So, we sort by ID using Quick Sort before searching.
                quickSort(arr, 0, size - 1); 
                
                int index = binarySearch(arr, 0, size - 1, targetId);
                
                if (index != -1) {
                    cout << "\n[Success] Product Found:\n";
                    cout << "ID: " << arr[index].id 
                         << " | Name: " << arr[index].name 
                         << " | Price: $" << arr[index].price << "\n";
                } else {
                    cout << "\n[Error] Product with ID " << targetId << " not found.\n";
                }
                delete[] arr;
                break;
            }
            case 6:
                cout << "\nExiting the program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
