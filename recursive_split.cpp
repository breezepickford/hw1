//edstem said to remove the #include iostream bit bc it causes a loop in the grading 
//but it wont build properly without it?
#include <iostream>
#include "split.cpp"

void split(Node*& in, Node*& odds, Node*& evens) {
   
    //if empty (list DNE or finished reccursion)
   if (in == nullptr) {
    //set odds and evens to null
    odds = nullptr;
    evens = nullptr;
    return;
   }

    //is the in value even or not?
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
        
        in = nullptr;
}

//clear memory
void deleteList(Node*& head) {
    //do this function if problems with valgrinf
}

int main() {


    //how are we getting this 'in' list. 
    //odd and evens list are just empty and null when called dw

    //init SE Linked list here
    Node* in = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};

    Node* odds = nullptr;
    Node* evens = nullptr;

    //call recursive funct
    split (in, odds, evens);

    //make pushback function for node struct in global

    //print lists to make sure sorted

    //once sorted...
    //delete odd list
    //delete even list

    return 0;
}