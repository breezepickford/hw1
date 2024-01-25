#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

//write FUNCTIONS HERE

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

//TODO: BRAINSTORM push_front, pop_front, back, front and getValAtLoc
//Brainstorm done:  push_back, pop_back

//add to back of list
void push_back(const std::string& val) {
  //BRAINSTORM PLAN
  
  //if list is completely empty
      //create a new node and make this both the head and the tail bc theres nothing else in the list
      //make it hold the value u passed in
      //update the last index
  //else if the list has nodes, but the last node is full (10/10 values filled)
      //create a new node, give it the value passed in
      //make this new nodes next pointer point to null bc its at the back
      //make this new nodes prev point to the previous tail
      //make this new node the tail node
      //update the last index
  //else if the list has nodes but the last node isnt full
      //add the value to the last node
      //update the last index

}

void pop_back() {
  //BRAINSTORM PLAN

  //if list empty, do nothing or maybe tell the user smth. and return
  //if last node not empty
    //decrement the last index
  //else if last node empty
    //decrement and save as temp val
    //delete old tail
    //make temp val new tail
    //if the list still has items after deleting the tail,
        //update tail's next to point to nullptr
    //if the list is now empty after deleting tail
        //update head to be nullptr

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
