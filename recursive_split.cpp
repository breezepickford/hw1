#include <iostream>
#include split.h

struct Node {
    int value;
    Node *next;
}

void split (Node*& in, Node*& odds, Node*& evens) {
   
    //if empty (list DNE or finished reccursion)
   if (in == nullptr) {
    //set odds and evens to null
    odds = nullptr;
    evens = nullptr;
    return;
   }
        if (head odd) {

        }
        if (head even) {

        }
        //recursive call to get next in
        split(in->next, odds->next, evens);
        
    return 0;
}

//clear memory
void deleteList(Node*& head) {

}

int main() {
    //call recursive funct
    split(headptr, odd, even);

    return 0;
}