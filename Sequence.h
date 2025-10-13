#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>

class SequenceNode {
public:
    SequenceNode* prev;
    SequenceNode* next;

    std::string item;

    SequenceNode() : next(nullptr), prev(nullptr)
    {}
    SequenceNode(std::string item) : prev(nullptr), next(nullptr), item(item)
    {}
};

struct Node {
public:
    std::string data;
    Node* prev;
    Node* next;
};

class Sequence {
private:
    Node* head;
    Node* tail;
    size_t sz;
public:
    Sequence (size_t sz =0);
    Sequence (const Sequence& s);
    ~Sequence();
    Sequence& operator= (const Sequence& s);
    std:: string& operator[](size_t position);
    void push_back(std::string item);
    void pop_back();
    void insert(size_t position, std::string item);
    std::string front() const;
    std::string back() const;
    bool empty() const;
    size_t size() const;
    void clear ();
    void erase(size_t position);
    void erase(size_t position, size_t count);

    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);
};
#endif