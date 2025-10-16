#include "Sequence.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Sequence.h"

//----------------------------------------------------------------
// Sequence: Creates an empty sequence or a
//              sequence of specified size
//    Parameters:
//      sz , which is initial size of sequence
//----------------------------------------------------------------
Sequence::Sequence(size_t sz) {
    head = nullptr;
    tail = nullptr;
    this->sz = 0;
}

//----------------------------------------------------------------
// Sequence: Creates a  copy of another
//             sequence
//    Parameters:
//       s , the sequence to copy from
//----------------------------------------------------------------
Sequence::Sequence(const Sequence& s) {
    // local variables
    Node* curr;  // pointer for traversing source sequence

    // initialize new sequence as empty
    head = nullptr;
    tail = nullptr;
    sz = 0;

    // traverse the sequence and copy each element
    curr = s.head;
    while (curr != nullptr) {
        push_back(curr->data);
        curr = curr->next;
    }
}

//----------------------------------------------------------------
// ~Sequence : cleans up all nodes and releases
//             memory
//----------------------------------------------------------------
Sequence::~Sequence() {
    clear();
}

//----------------------------------------------------------------
// operator=: assigns one sequence to another with deep copy
//    returns:  the ref to this sequence
//    parameters:
//       s , the sequence to copy from
//----------------------------------------------------------------
Sequence& Sequence::operator=(const Sequence& s) {
    Node* curr;

    // check for self assignment
    if (this != &s) {
        // delete
        clear();

        // copy all elements from the other sequence
        curr = s.head;
        while (curr != nullptr) {
            push_back(curr->data);
            curr = curr->next;
        }
    }

    return *this;
}

//----------------------------------------------------------------
// operator[]: accesses element at given position
//    returns:  reference to string at that position
//    parameters:
//       position, index of element to access
//    throws:  exception if position is out of bounds
//----------------------------------------------------------------
std::string& Sequence::operator[](size_t position) {
    Node* curr;

    // check if position is valid
    if (position >= sz) {
        throw exception();
    }

    // traverse to tnode at given position
    curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->data;
}

//----------------------------------------------------------------
// push_back: Adds an element to the end of the sequence
//    Returns:  void
//    Parameters:
//       item , the string to add
//----------------------------------------------------------------
void Sequence::push_back(std::string item) {
    Node* newNode;

    // create new node with  item
    newNode = new Node(item);

    // if list is empty, new node is head and tail
    if (tail == nullptr) {
        head = tail = newNode;
    }
    // else add to end
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    sz++;
}

//----------------------------------------------------------------
// pop_back: removes the last element from the sequence
//    returns:  void
//    parameters:  None
//    throws:  exception if sequence is empty
//----------------------------------------------------------------
void Sequence::pop_back() {
    Node* temp;

    // check if list is empty
    if (head == nullptr) {
        throw exception();
    }

    // save pointer to node being deleted
    temp = tail;

    // if one element list becomes empty
    if (head == tail) {
        head = tail = nullptr;
    }
    // else move tail back
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    sz--;
}

//----------------------------------------------------------------
// insert: inserts an element at a specific position
//    returns:  void
//    parameters:
//       position
//       where to insert (0-based index)
//       item   the string to insert
//    throws: exception if position is invalid
//----------------------------------------------------------------
void Sequence::insert(size_t position, std::string item) {
    // Local variables
    Node* newNode;  //  new node to insert
    Node* curr;     // pointer for traversing to position

    // cant insert beyond current size
    if (position > sz) {
        throw exception();
    }

    // insert at beginning
    if (position == 0) {
        newNode = new Node(item);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        sz++;
        return;
    }

    // insert at end w push_back
    if (position == sz) {
        push_back(item);
        return;
    }

    // insert in the middle ,navigate to position
    curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    // create new node and insert it before curr
    newNode = new Node(item);
    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;
    sz++;
}

//----------------------------------------------------------------
// front: returns the first element in the sequence
//    returns:  The string at the front
//    throws:  exception if sequence is empty
//----------------------------------------------------------------
std::string Sequence::front() const {
    if (head == nullptr) {
        throw exception();
    }

    return head->data;
}

//----------------------------------------------------------------
// back: returns the last element in the sequence
//    returns:  the string at the back
//    throws:  exception if sequence is empty
//----------------------------------------------------------------
std::string Sequence::back() const {
    if (tail == nullptr) {
        throw exception();
    }

    return tail->data;
}

//----------------------------------------------------------------
// empty: checks if the sequence has no elements
//    returns:  1 if empty, 0 otherwise
//----------------------------------------------------------------
bool Sequence::empty() const {
    return sz == 0;
}

//----------------------------------------------------------------
// size: returns the number of elements in the sequence
//    returns:  the current size
//----------------------------------------------------------------
size_t Sequence::size() const {
    return sz;
}

//----------------------------------------------------------------
// clear: removes all elements from the sequence and frees memory
//    Returns:  void
//----------------------------------------------------------------
void Sequence::clear() {
    Node* temp;

    // delete all nodes one by one
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    // reset tail and size
    tail = nullptr;
    sz = 0;
}

//----------------------------------------------------------------
// erase: removes the element at a specific position
//    returns:  void
//    parameters:
//       position - index of element to remove
//    throws:  exception if position is out of bounds
//----------------------------------------------------------------
void Sequence::erase(size_t position) {
    Node* temp;
    Node* curr;

    // check if position is valid
    if (position >= sz) {
        throw exception();
    }

    // erase the head
    if (position == 0) {
        temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        sz--;
        return;
    }

    // erase from middle or end  navigate to position
    curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    // ppdate pointers to skip this node
    curr->prev->next = curr->next;

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    // free memory and decrease size
    delete curr;
    sz--;
}

//----------------------------------------------------------------
// erase: removes multiple consecutive elements
//    return:  void
//    param:
//       position  - starting index
//       count  - number of elements to remove
//    throws:  exception if position or count are invalid
//----------------------------------------------------------------
void Sequence::erase(size_t position, size_t count) {
    if (position >= sz || position + count > sz) {
        throw exception();
    }

    // erase count elements starting at position
    for (size_t i = 0; i < count && position < sz; i++) {
        erase(position);
    }
}

//----------------------------------------------------------------
// operator<<: prints all elements in the sequence
//    returns:  Reference to output stream
//    param:
//       os  - output stream to write to
//       s  - the sequence to print
//----------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    Node* curr;

    curr = s.head;

    //  print each element
    while (curr != nullptr) {
        os << curr->data << " ";
        curr = curr->next;
    }

    return os;
}