//edstem said to remove the #include iostream bit bc it causes a loop in the grading
#include split.h

struct Node {
    int value;
    Node *next;
}

//TODO: add function for list

void split (Node*& in, Node*& odds, Node*& evens) {
   
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
        

    return 0;
}

//clear memory
void deleteList(Node*& head) {

}

int main() {
    //call recursive funct

    //cin???
    //given??
    //include file??
    //how are we getting this 'in' list. 
    //odd and evens list are just empty and null when called dw

    split (Node*& in, Node*& odds, Node*& evens);

    return 0;
}