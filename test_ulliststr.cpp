#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//write MAIN stuff here (call function)
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    //initi
    ULListStr Breeze_list;

    //fill with piper (my sisters name)
   
    Breeze_list.push_back("i");
    Breeze_list.push_back("p");
    Breeze_list.push_back("e");
    Breeze_list.push_back("r");
    Breeze_list.push_front("P");

    //test size, should print 5
    std::cout << "Size: " << Breeze_list.size() << std::endl;

    //front should print p
    std::cout << "Front: " << Breeze_list.front() << std::endl;
    //back should print r
    std::cout << "Back: " << Breeze_list.back() << std::endl;

    //remove p from front
    Breeze_list.pop_front();
    //remove r
    Breeze_list.pop_back(); 

    //test size 
    std::cout << "Size: " << Breeze_list.size() << std::endl;

    //test get
    //should print i
    std::cout << "Val at ind 0" << Breeze_list.get(0) << std::endl;
    //should print p
    std::cout << "Val at ind 1" << Breeze_list.get(1) << std::endl;

    //test set
    Breeze_list.set(1,"Q");
    std::cout << "Value at index 1: " << Breeze_list.get(1) << std::endl;
    //should print Q
    //test clear
    Breeze_list.clear();
    std::cout << "Size after clear: " << Breeze_list.size() << std::endl;
    //should print 0

    return 0;
}
