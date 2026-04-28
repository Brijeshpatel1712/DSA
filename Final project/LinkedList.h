#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Product.h"
#include <iostream>

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void addProduct(Product p) {
        Node* newNode = new Node(p);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "Product added successfully!\n";
    }

    void displayProducts() {
        if (!head) {
            std::cout << "No products available in the inventory.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            std::cout << "ID: " << temp->data.id 
                      << " | Name: " << temp->data.name 
                      << " | Price: $" << temp->data.price << "\n";
            temp = temp->next;
        }
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Convert Linked List to Array for Sorting and Binary Search
    Product* toArray() {
        int size = getSize();
        if (size == 0) return NULL;
        Product* arr = new Product[size];
        Node* temp = head;
        int i = 0;
        while (temp) {
            arr[i++] = temp->data;
            temp = temp->next;
        }
        return arr;
    }
};

#endif
