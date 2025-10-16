#include "Sequence.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Sequence.h"

Sequence::Sequence(size_t sz) {
    head = nullptr;
    tail = nullptr;
    this->sz = 0;
}

Sequence::Sequence(const Sequence& s) {
    head = nullptr;
    tail = nullptr;
    sz = 0;

    Node* curr = s.head;
    while (curr != nullptr) {
        push_back(curr->data);
        curr = curr->next;
    }
}

Sequence::~Sequence() {
    clear();
}

Sequence& Sequence::operator=(const Sequence& s) {
    return *this;  // Must return something
}

std::string& Sequence::operator[](size_t position) {
    return head->data;  // Must return something (placeholder)
}

void Sequence::push_back(std::string item) {
    Node* newNode = new Node(item);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    sz++;
}

void Sequence::pop_back() {
    if (head == nullptr) {
        throw exception();
    }

    Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }else {
            tail = tail->prev;
            tail -> next = nullptr;
        }
    delete temp;
    sz --;
}

void Sequence::insert(size_t position, std::string item) {
    if (position == 0) {
        Node* newNode = new Node(item);
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

    while (sz < position) {
        push_back("???");
    }

    if (position >= sz) {
        push_back(item);
        return;
    }

    Node* curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    Node* newNode = new Node(item);
    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;
    sz++;
}
std::string Sequence::front() const {
    if (head==nullptr) {
        throw exception();
    }
    return head->data;  // Must return something
}

std::string Sequence::back() const {
    if (tail == nullptr) {
        throw exception();
    }
    return tail->data;  // Must return something
}

bool Sequence::empty() const {
    return sz == 0;
}

size_t Sequence::size() const {
    return sz;
}

void Sequence::clear() {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    sz = 0;
}

void Sequence::erase(size_t position) {
    if (position >= sz) {
        throw exception();
    }

    if (position == 0) {
        Node* temp = head;
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

    Node* curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    delete curr;
    sz--;
}

void Sequence::erase(size_t position, size_t count) {

    if (position >= sz || position + count >sz ) {
        throw exception();
    }

    for (size_t i = 0; i < count && position < sz; i++) {
        erase(position);
    }
}

std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    Node* curr = s.head;
    while (curr != nullptr) {
        os << curr->data << " ";
        curr = curr->next;
    }
    return os;
}