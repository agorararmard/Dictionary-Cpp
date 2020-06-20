#include"dictionary.h"


inline void dictionary::exceptIndexOutOfBounds(const int index) const{
    if(index >= insertionOrder.size() || index < 0)  throw std::runtime_error("Insertion Index Out of Dictionary Range");
}

inline void dictionary::exceptKeyNotInMap(const std::string key) const{
    if (dict.count(key) == 0) throw std::runtime_error("Key Doesn't Exist in Const Dictionary");
}

inline int dictionary::findKeyIndex(const std::string key) const{
    exceptKeyNotInMap(key);    
    for (int i =0; i < insertionOrder.size();i++){
        if(key == insertionOrder[i])
            return i;
    }
    throw std::runtime_error("Inconsistency between map keys and insertion order");
}



dictionary::dictionary(const dictionary& a):insertionOrder(a.insertionOrder),dict(a.dict){}

void dictionary::insert(const std::string key,const int value){   //For setting an index to a value in a non const obj
    if(dict.count(key) == 0){
        insertionOrder.push_back(key);
        dict[key] = value;
    }else{
        dict[key] = value;
    }
}

inline int dictionary::getat(const std::string key) const{ // Getting a value at index in a const obj
    exceptKeyNotInMap(key);
    return dict.at(key);
}
inline int dictionary::getat(const std::string key){ // Getting a value at index in a non-const obj
    return this->operator[](key);
}

inline int dictionary::at(const int index) const{  // Getting a value at index in a const oj
    exceptIndexOutOfBounds(index);
    std::string key = insertionOrder[index];
    exceptKeyNotInMap(key);
    return dict.at(key);
}

inline int& dictionary::at(const int index){ // Getting a value at index in a non-const obj
    exceptIndexOutOfBounds(index);
    std::string key = insertionOrder[index];
    if (dict.count(key) == 0) throw std::runtime_error("Inconsistency between map keys and insertion order");
    return dict[key];
}

inline int dictionary::size() const{         //for getting the size of the dictionary
    return insertionOrder.size();
}

const dictionary& dictionary::operator=(const dictionary& a){   //assignment operator
    insertionOrder = a.insertionOrder;
    dict = a.dict;
}
inline int& dictionary::operator[](const std::string key){     //returning a reference to the element at index in a non const obj
    if (dict.count(key) == 0) insertionOrder.push_back(key);
    return dict[key];
}

inline int dictionary::operator[](const std::string key) const{//returning the value at index in a const obj
    return getat(key);
}


unsigned int dictionary::operator==(const dictionary& a) const{    //eq operator between const objs
    return (a.dict == dict && a.insertionOrder == insertionOrder);
}

inline std::string dictionary::keyAt(const int index) const{ //to get key at index
    exceptIndexOutOfBounds(index);
    return insertionOrder[index];
}
inline int dictionary::getIndex(const std::string key) const { //to get index of key
    return findKeyIndex(key);
}
void dictionary::remove(const std::string key){ //removing an element at index a
    exceptKeyNotInMap(key);
    int index = findKeyIndex(key);
    insertionOrder.erase(insertionOrder.begin()+index);
    dict.erase(key);
}

void dictionary::removeAt(const int index){ //removing an element at index a
    exceptIndexOutOfBounds(index);
    std::string key = insertionOrder[index];
    exceptKeyNotInMap(key);
    insertionOrder.erase(insertionOrder.begin()+index);
    dict.erase(key);
}

inline bool dictionary::exists(const std::string key){
    return dict.count(key);
}

inline bool dictionary::indexExists(const int index){
    if(index >= insertionOrder.size() || index < 0) return false;
    else {
        if (dict.count(insertionOrder[index]) == 0) throw std::runtime_error("Inconsistency between map keys and insertion order");
        return true;        
    }
   
}

inline void dictionary::clear(){
    insertionOrder.clear();
    dict.clear();
}

