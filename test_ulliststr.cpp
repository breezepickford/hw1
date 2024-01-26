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
    std::cout << "pushed back i" << std::endl;
    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    //not able to 'get' values wher eindex hasnt been filled yet, 
    // bc program aborts and throws and error.
    // not sure if supposed to do this. come back to later.

    Breeze_list.push_back("p");
    std::cout << "pushed back p" << std::endl;
    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << "index 1: " << Breeze_list.get(1) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Breeze_list.push_back("e");
    std::cout << "pushed back e" << std::endl;
    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << "index 1: " << Breeze_list.get(1) << std::endl;
    std::cout << "index 2: " << Breeze_list.get(2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Breeze_list.push_back("r");
    std::cout << "pushed back r" << std::endl;
    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << "index 1: " << Breeze_list.get(1) << std::endl;
    std::cout << "index 2: " << Breeze_list.get(2) << std::endl;
    std::cout << "index 3: " << Breeze_list.get(3) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Breeze_list.push_front("P");
    std::cout << "pushed front P" << std::endl;
    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << "index 1: " << Breeze_list.get(1) << std::endl;
    std::cout << "index 2: " << Breeze_list.get(2) << std::endl;
    std::cout << "index 3: " << Breeze_list.get(3) << std::endl;
    std::cout << "index 4: " << Breeze_list.get(4) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    //test size, should print 5
    std::cout << "Size: " << Breeze_list.size() << std::endl;

    std::cout << "index 0: " << Breeze_list.get(0) << std::endl;
    std::cout << "index 1: " << Breeze_list.get(1) << std::endl;
    std::cout << "index 2: " << Breeze_list.get(2) << std::endl;
    std::cout << "index 3: " << Breeze_list.get(3) << std::endl;
    std::cout << "index 4: " << Breeze_list.get(4) << std::endl;

    //front should print p
    std::cout << "Front: " << Breeze_list.front() << std::endl;
    //back should print r
    std::cout << "Back: " << Breeze_list.back() << std::endl;

    //remove p from front
    Breeze_list.pop_front();
    //remove r
    Breeze_list.pop_back(); 

    //front should print i
    std::cout << "Front: " << Breeze_list.front() << std::endl;
    //back should print e
    std::cout << "Back: " << Breeze_list.back() << std::endl;

    //test size should print 3
    std::cout << "Size: " << Breeze_list.size() << std::endl;

    //test get
    //should print i
    std::cout << "Val at ind 0: " << Breeze_list.get(0) << std::endl;
    //should print p
    std::cout << "Val at ind 1: " << Breeze_list.get(1) << std::endl;

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
