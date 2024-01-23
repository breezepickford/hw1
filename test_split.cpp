/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"
using namespace std;

//print list
void printL(const Node* in) { //const bc when we are printing we do NOT want to change our arguments
    const Node* current = in;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

}

//delete list func to prevent memory problems
void deleteList(Node*& in) {
    while (in != nullptr) {
        Node* temp = in;
        in = in->next;
        delete temp;
    }
}

int main(int argc, char* argv[])
{
    //how are we getting this 'in' list. 
    //odd and evens list are just empty and null when called dw

    //init SE Linked list here
    Node* in = new Node{5, new Node{7, new Node{4, new Node{2, nullptr}}}};

    Node* odds = nullptr;
    Node* evens = nullptr;

    cout << "og list pre sorting" << endl;
    printL(in);
    //call recursive funct
    split (in, odds, evens);

    //make pushback function for node struct in global

    //print lists to make sure sorted
    cout << "og list after sorting" << endl;
    printL(in);
    
    cout << "evens list" << endl;
    printL(evens);

    cout << "odds list" << endl;
    printL(odds);
    
    //once sorted...
    //delete odd list
    //delete even list

    deleteList(odds);
    deleteList(evens);

    return 0;
}
