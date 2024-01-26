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
//FIXME: WHEN TESTING/BUILDING make sure ot be in the correct docker folder!!!!!

//TODO: BRAINSTORM push_front, pop_front, back, front and getValAtLoc
//Brainstorm done:  push_back, pop_back

//add to back of list
void push_back(const std::string& val) {
  //BRAINSTORM PLAN
  //if the list is empty (no head)
  if(!head) { 
    //create a new node and make this both the head and the tail bc 
    //there's nothing else in the list
    head_ = new Item(); 
    tail_ = head_;
    //make it hold the value u passed in
    head_->val[0] = val;
    //update the last filled index
    head_->last = 1;
  }
  //else if the list has nodes, but the last node is full (10/10 values filled)
  else if (tail->last == ARRSIZE) { 
    //create a new node, & give it the value passed in
    Item* newN = new Item(); 
    newN->val[0] = val;
    //update the last filled index
    newN->last = 1;
    //make this new nodes prev point to the previous tail 
    newN->prev = tail_;
    //make prev tail point to new node
    tail_->next = newN;
    //make this new node the tail node
    tail_= newN;
  }
  //else if the list has nodes but the last node isnt full
  else if (tail_->last < ARRSIZE){
    //add the value to the last node
    tail_->val[tail_->last] = val;
    //update the last index
    tail_->last++;
  }
  //increase the size of the ULL by 1 bc we just added to it
  size_++;
}

void pop_back() {
  //BRAINSTORM PLAN
    //if list empty, do nothing or maybe tell the user smth. and return
    if (!head) {
      return;
    }
    //if last node NOT empty
    if (tail_ ->last > 0) {
      //decrement the last index
      tail_->last--;
      //do i need to delete the memory of the old tail?? COME BACK TO THIS
    }
    //else if last node empty
    else {
      if (tail_->prev != nullptr) {
        //make temp old tail
        Item* temp = tail_;
        //make tail previous node
        tail_ = tail_->prev;
        //delete old tail
        delete temp;
        //point new tails next to null
        tail_->next = nullptr;
      }
      //else if only one node left
      else {
        //delete tail (empties list)
        delete tail_;
        //set head and tail to null bc list now empty
        head_ = nullptr;
        tail_=nullptr;
      }
    }
    //reduce list size
    size_--;
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
