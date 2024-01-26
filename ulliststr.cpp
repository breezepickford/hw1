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

//TODO: BRAINSTORM back, front, and getValAtLoc
//done:  push_back, pop_back, push_front, pop_front

//add to back of list
void ULListStr::push_back(const std::string& val) {
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

void ULListStr::pop_back() {
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
void ULListStr::push_front(const std::string& val) {
  //if list empty, create new head node
  if (!head_) {
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
  }
  //if room before the 'first' value in head node
  else if (head_->first > 0) {
    head_->first--;
    head_->val[head_->first] = val;
  }
  //if head node is full, create new head node
  else {
    Item* newHead = new Item();
    newHead->next = head_;
    head_->prev = newHead;
    head_ = newHead;
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
  }
  size_++;
}


/**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front() {
    //if list is empty
    if(!head_) {
      return;
    }
    //if first node has more than 1 value (ex: 0 < 1-1  or 0 < 0 -1 (false) vs 0 < 2-1 (true))
    if (head_->first < head_->last - 1) {
      //increment the first index to hold second vals location (get rid of that first val)
      //maybe this logic doesnt work  in every case .. come back and check this. 
      //does first need to always be 0 in any other situation???
      head_->first++;
    }
    //else if the first node only has 1 value
    else {
      //make temp item hold old head
      Item* temp = head_;
      //head is now the following node (new head is second node!)
      head_ = head_->next;
      //delete old head
      delete temp;
    }
    //decrement the size of the LL bc we removed a value
    size_--; 
  }

/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
  //if list is empty (head DNE)  OR if the first index of head is the same as last (head doesnt hold anything)
  if (head_ == nullptr || head_->first >= head_ ->last) {
    return NULL;
  }
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const {
    //if empty
    if (head_ == nullptr) {
        return NULL;
    }
    //return last element in the last node
    //tails value at last index - 1
    return tail_->val[tail_->last - 1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // heck if loc is a valid index
  if (loc >= size_) {
    return nullptr; // invalid location, return nullptr
  }

  //start from the head andgo thry the list to find the item at loc
  Item* current = head_;
  size_t currentSize = current->last - current->first;

  while (loc >= currentSize) {
    //move to the next item in the list
    //make loc smaller by current size
    loc -= currentSize;
    //move to next item
    current = current->next;
    //update size of curr item
    currentSize = current->last - current->first;
  }

  // atp current points to item that contains the desired value
  // calculate the index within the 'val' array of this item
  size_t indexWithinItem = current->first + loc;

  // return a pointer to the desired value within the val array
  return &(current->val[indexWithinItem]);
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
