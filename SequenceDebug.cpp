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
    sequence.push_back("big");
    sequence.push_back("tall");
    sequence.push_back("big");
    cout << sequence << endl;


    return 0;
}