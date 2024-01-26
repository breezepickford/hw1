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

//TODO: BRAINSTORM pop_front, back, front and getValAtLoc
//done:  push_back, pop_back, push_front

//add to back of list
void push_back(const std::string& val) {
  //BRAINSTORM PLAN
  //if the list is empty (no head)
  if(!head_) { 
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
  else if (tail_->last == ARRSIZE) { 
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
  //increase the size of the ULL by 1 bc we just added a value to it
  size_++;
}

void pop_back() {
  //BRAINSTORM PLAN
    //if list empty, do nothing or maybe tell the user smth. and return
    if (!head_) {
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

/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void push_front(const std::string& val) {
  //if list empty
    if (!head_) {
      //make a new item to put as head
      head_= new Item();
      //since theres only 1 thing in the list, this is also the tail
      tail_ = head_;
      //put the value in new nodes first index
      head_->val[0] = val;
      //make this node have 1 value filled in
      head_->first = 0;
      head_->last = 1;
    }
    //if list not empty, but room exists in first node
    else if (head_->last < ARRSIZE) {
      //increase heads last value by 1
      head_->last++;
      //fill last space in with new value
      head_->val[tail->last] = val;
    }
    //if list not empty and NO room in first node
    else {
      //make new node to put in front
      Item* newHead = new Item();
      //point new heads next to old head
      newHead->next = head_;
      //point old heads prev to new head
      head_->prev = newHead;
      //make head the new head
      head_ = newHead;
      //put value in heads first index
      head_->val[0] = val;
      //make this node have 1 value filled in
      head_->first = 0;
      head_->last = 1;
    }
    //increase size of LL by 1 bc we just added a value (remeber size represents values not number of nodes)
    size_++;
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
