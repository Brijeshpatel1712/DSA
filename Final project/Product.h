#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// Structure to represent a Product
struct Product {
    int id;
    std::string name;
    double price;

    Product() : id(0), name(""), price(0.0) {}
    Product(int pid, std::string pname, double pprice) : id(pid), name(pname), price(pprice) {}
};

// Node structure for Linked List
struct Node {
    Product data;
    Node* next;

    Node(Product p) : data(p), next(NULL) {}
};

#endif
