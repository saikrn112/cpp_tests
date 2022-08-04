#include <iostream>
struct X {
    //implicit conversion
    operator int() const { return 7; }

    // explicit conversion
    explicit operator X*() const { X a1;return &a1; }

//  Error: array operator not allowed in conversion-type-id
//  operator int(*)[3]() const { return nullptr; }
    using arr_t = int[3];
    operator arr_t*() const { return nullptr; } // OK if done through typedef
//  operator arr_t () const; // Error: conversion to array not allowed in any case
};

int main()
{
    X x; 
    X* a = static_cast<X*>(x);
}
