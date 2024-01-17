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

    bool isEven = false;
    if (in->value % 2 == 0) {
        isEven = true;
    }
        if (isEven) {
            //even list ptr holds the in ptr
            evens = in;
            //recursive call to get next in
            split(in->next, odds, evens->next);
        }
        else {
            //odd list ptr now holds the in ptr
            odds = in;
            //recursive call to get next in
            split(in->next, odds->next, evens);
        }
        

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