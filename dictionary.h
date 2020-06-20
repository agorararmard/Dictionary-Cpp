
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

template<typename keyType, typename dataType>
class dictionary{
    private:
        std::vector<keyType> insertionOrder;  //the dynamic array should be modified to pointers later;
        std::map<keyType,dataType> dict;
        inline void exceptIndexOutOfBounds(const int index) const;
        inline void exceptKeyNotInMap(const keyType key) const;
        inline int findKeyIndex(const keyType key) const;

    public:
   
        explicit dictionary(){}   //empty constructor
        dictionary(const dictionary<keyType,dataType>& a);  //deep copy constructor
        dictionary(dictionary<keyType,dataType>&& a);       //move constructor

        void insert(const keyType key,const dataType value);   //For setting an index to a value in a non const obj
        
        inline dataType getat(const keyType key) const; // Getting a value at index in a const obj
        inline dataType getat(const keyType key);  // Getting a value at index in a non-const obj

        inline dataType at(const int index) const; // Getting a value at index in a const oj
        inline dataType& at(const int index); // Getting a value at index in a non-const obj

        inline int size() const;         //for getting the size of the dictionary
        
        const dictionary<keyType,dataType>& operator=(const dictionary& a);   //assignment operator
       
        //Difference between following funcs is for sorting purposes
        inline dataType& operator[](const keyType key);     //returning a reference to the element at key in a non const obj
        inline dataType operator[](const keyType key) const;//returning the value at key in a const obj

        bool operator==(const dictionary& a) const;    //eq operator between const and non-const objs
        
        inline keyType keyAt(const int index) const; //to get key at index

        inline int getIndex(const keyType key) const; //to get index of key

        void remove(const keyType key); //removing an element of key
        void removeAt(const int index); //removing an element at index 
        
        inline bool exists(const keyType key); //checks if key exists
        inline bool indexExists(const int index); //checks if insertion index is valid;
        
        inline void clear();   //clears the contents of the dictionary
        ~dictionary(){}   //Obj Destructor
};
#include "dictionary.cpp"
#endif