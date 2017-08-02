#include <set>
#include <chrono>
#include <string>
#include <iostream>

// Functions taking universal references are the greediest functions in C++.

// They instantiate to create exact matches for almost any type of argument,
// even though they are not what you intended.

// This is why combining overloading and universal references is
// almost always a bad idea: the universal reference overload vacuums up far
// more argument types than the developer doing the overloading generally expects.

// bind rvalue reference to rvalue only
// bind lvalue reference to lvalue
// bind const lvalue reference to rvalue

std::multiset<std::string> names;

void logAndAdd(const std::string& name) {
    auto now = std::chrono::system_clock::now();

    //Inserts a new element into the container constructed in-place with the given args .
    // name is lvalue
    names.emplace(name);
}


int main() {
    std::string petName("Dar");

    logAndAdd(petName); // pass lvalue string
    logAndAdd(std::string("Peer")); // pass rvalue string
    logAndAdd("Patty"); // pass literal
}

