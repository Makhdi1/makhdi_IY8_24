#include "BSTree.h"
#include <iostream>
#include <fstream>

namespace simplebst {

BSTree::BSTree() : root(nullptr) {}

BSTree::BSTree(const BSTree& other) : root(nullptr) {
    root = copyNodes(other.root);
}


BSTree::BSTree(BSTree&& other) noexcept : root(other.root) {
    other.root = nullptr;
}


BSTree::~BSTree() {
    clear();
}

BSTree::Node* BSTree::copyNodes(Node* node) {

    if (node ==nullptr) return nullptr;
    Node* newNode =new Node(node->data);
    newNode->left =copyNodes(node->left);
    newNode->right =copyNodes(node->right);
    return newNode;

}


void BSTree::destroyNodes(Node* node) {

    if (node ==nullptr) return;
    destroyNodes(node->left);
    destroyNodes(node->right);
    delete node;
}


void BSTree::clear() {
    destroyNodes(root);
    root =nullptr;
}

BSTree::Node* BSTree::insertNode(Node* node, int value) {

    if (node ==nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left =insertNode(node->left, value);

    } else if (value > node->data) {
        node->right =insertNode(node->right, value);
    }

    return node;
}


void BSTree::add(int value) {
    root =insertNode(root, value);
}


BSTree::Node* BSTree::findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


BSTree::Node* BSTree::deleteNode(Node* node, int value) {
    if (node ==nullptr) return nullptr;
    if (value <node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value >node->data) {
        node->right =deleteNode(node->right, value);

    } else {

        if (node->left ==nullptr && node->right ==nullptr) {
            delete node;
            return nullptr;

        } else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;


        } else if (node->right ==nullptr) {
            Node* temp =node->left;
            delete node;
            return temp;

        } else {
            Node* minRight =findMinNode(node->right);
            node->data =minRight->data;
            node->right =deleteNode(node->right, minRight->data);
        }
    }
    return node;

}


void BSTree::remove(int value) {
    root =deleteNode(root, value);
}


bool BSTree::searchNode(Node* node, int value) const {
    if (node ==nullptr) return false;
    if (value == node->data) return true;
    if (value <node->data) return searchNode(node->left, value);
    else return searchNode(node->right, value);
}


bool BSTree::contains(int value) const {
    return searchNode(root, value);
}


void BSTree::preOrderPrint(Node* node) const {
    if (node ==nullptr) return;
    std::cout << node->data << " ";
    preOrderPrint(node->left);
    preOrderPrint(node->right);
}


void BSTree::printPreOrder() const {
    preOrderPrint(root);
    std::cout << std::endl;
}


void BSTree::inOrderPrint(Node* node) const {
    if (node == nullptr) return;
    inOrderPrint(node->left);
    std::cout << node->data << " ";
    inOrderPrint(node->right);

}


void BSTree::printInOrder() const {

    inOrderPrint(root);
    std::cout << std::endl;
}


void BSTree::postOrderPrint(Node* node) const {
    if (node ==nullptr) return;
    postOrderPrint(node->left);
    postOrderPrint(node->right);
    std::cout<<node->data << " ";
}


void BSTree::printPostOrder() const {
    postOrderPrint(root);
    std::cout<<std::endl;
}


void BSTree::inOrderPrintStream(Node* node, std::ostream& os) const {
    if (node == nullptr) return;

    inOrderPrintStream(node->left, os);
    os <<node->data <<" ";
    inOrderPrintStream(node->right, os);
}


std::ostream& operator<<(std::ostream& os, const BSTree& tree) {
    tree.inOrderPrintStream(tree.root, os);

    return os;
}


void BSTree::saveNodesToFile(Node* node, std::ofstream& file) const {
    if (node ==nullptr) return;

    file << node->data << " ";
    saveNodesToFile(node->left, file);
    saveNodesToFile(node->right, file);
}


void BSTree::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file for writting" << std::endl;
        return;
    }

    saveNodesToFile(root, file);

    file.close();
}


void BSTree::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr <<"Cannot open file for reading" << std::endl;
        return;
    }
    clear();
    int value;
    while (file >>value) {
        add(value);
    }
    file.close();
}

}