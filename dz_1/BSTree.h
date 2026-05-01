#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <string>

namespace simplebst {

    class BSTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;

            Node(int value) : data(value), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* copyNodes(Node* node);
        void destroyNodes(Node* node);
        Node* insertNode(Node* node, int value);
        Node* deleteNode(Node* node, int value);
        Node* findMinNode(Node* node);
        bool searchNode(Node* node, int value) const;
        void preOrderPrint(Node* node) const;
        void inOrderPrint(Node* node) const;
        void postOrderPrint(Node* node) const;
        void inOrderPrintStream(Node* node, std::ostream& os) const;
        void saveNodesToFile(Node* node, std::ofstream& file) const;


    public:

        BSTree();
        BSTree(const BSTree& other);
        BSTree(BSTree&& other) noexcept;
        ~BSTree();


        void add(int value);
        void remove(int value);
        void clear();

        bool contains(int value) const;
        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;
        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);

        friend std::ostream& operator<<(std::ostream& os, const BSTree& tree);
    };


}

#endif