
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

class dictionary{
    private:
        std::vector<std::string> insertionOrder;  //the dynamic array should be modified to pointers later;
        std::map<std::string,int> dict;
        inline void exceptIndexOutOfBounds(const int index) const;
        inline void exceptKeyNotInMap(const std::string key) const;
        inline int findKeyIndex(const std::string key) const;

    public:
   
        explicit dictionary(){}   //empty constructor
        dictionary(const dictionary& a);  //deep copy constructor
        dictionary(dictionary&& a);       //move constructor

        void insert(const std::string key,const int value);   //For setting an index to a value in a non const obj
        
        inline int getat(const std::string key) const; // Getting a value at index in a const obj
        inline int getat(const std::string key);  // Getting a value at index in a non-const obj

        inline int at(const int index) const; // Getting a value at index in a const oj
        inline int& at(const int index); // Getting a value at index in a non-const obj

        inline int size() const;         //for getting the size of the dictionary
        
        const dictionary& operator=(const dictionary& a);   //assignment operator
       
        //Difference between following funcs is for sorting purposes
        inline int& operator[](const std::string key);     //returning a reference to the element at key in a non const obj
        inline int operator[](const std::string key) const;//returning the value at key in a const obj

        inline int& operator[](const int index);     //returning a reference to the element at index in a non const obj
        inline int operator[](const int index) const;//returning the value at index in a const obj

        unsigned int operator==(const dictionary& a) const;    //eq operator between const and non-const objs
        
        inline std::string keyAt(const int index) const; //to get key at index

        inline int getIndex(const std::string key) const; //to get index of key

        void remove(const std::string key); //removing an element of key
        void removeAt(const int index); //removing an element at index 
        
        inline bool exists(const std::string key); //checks if key exists
        inline bool indexExists(const int index); //checks if insertion index is valid;
        
        inline void clear();   //clears the contents of the dictionary
        ~dictionary(){}   //Obj Destructor
};
#include "dictionary.cpp"
#endif