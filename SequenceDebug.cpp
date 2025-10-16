/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <vector>

#include "Sequence.h"
using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;


    Sequence sequence;
    Sequence seq1;
    sequence.push_back("big");
    sequence.push_back("tall");
    sequence.push_back("big");
    cout << sequence << endl;
    cout << sequence.size() << endl;

    sequence.pop_back();
    sequence.pop_back();

    sequence.insert(4,"Dodgers");
    sequence.insert(3,"Reds");
    sequence.insert(1,"Raiders");
    cout << sequence.size() << endl;
    cout << sequence << endl;
    cout << sequence.back() << endl;
    cout << sequence.front() << endl;

    cout <<sequence<<endl;
    sequence.erase(1);
    cout << sequence << endl;
    sequence.erase(1,3);
    cout << sequence << endl;
    return 0;
}