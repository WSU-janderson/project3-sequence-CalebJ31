#include "Sequence.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Sequence.h"

Sequence::Sequence(size_t sz) {
    head = nullptr;
    tail = nullptr;
    this->sz = 0;
}

Sequence::Sequence(const Sequence& s) {
    // Empty for now
}

Sequence::~Sequence() {
    // Empty for now
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
    if (head == nullptr) return;

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
    return head->data;  // Must return something
}

std::string Sequence::back() const {
    return tail->data;  // Must return something
}

bool Sequence::empty() const {
    return sz == 0;
}

size_t Sequence::size() const {
    return sz;
}

void Sequence::clear() {}

void Sequence::erase(size_t position) {}

void Sequence::erase(size_t position, size_t count) {}

std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    Node* curr = s.head;
    while (curr != nullptr) {
        os << curr->data << " ";
        curr = curr->next;
    }
    return os;
}