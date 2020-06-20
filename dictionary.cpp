#include"dictionary.h"

template<typename keyType, typename dataType>
inline void dictionary<keyType,dataType>::exceptIndexOutOfBounds(const int index) const{
    if(index >= insertionOrder.size() || index < 0)  throw std::runtime_error("Insertion Index Out of Dictionary Range");
}

template<typename keyType, typename dataType>
inline void dictionary<keyType,dataType>::exceptKeyNotInMap(const keyType key) const{
    if (!dict.count(key)) throw std::runtime_error("Key Doesn't Exist in Const Dictionary");
}

template<typename keyType, typename dataType>
inline int dictionary<keyType,dataType>::findKeyIndex(const keyType key) const{
    exceptKeyNotInMap(key);    
    for (int i =0; i < insertionOrder.size();i++){
        if(key == insertionOrder[i])
            return i;
    }
    throw std::runtime_error("Inconsistency between map keys and insertion order");
}


template<typename keyType, typename dataType>
dictionary<keyType,dataType>::dictionary(const dictionary<keyType,dataType>& a):insertionOrder(a.insertionOrder),dict(a.dict){}

template<typename keyType, typename dataType>
void dictionary<keyType,dataType>::insert(const keyType key,const dataType value){   //For setting an index to a value in a non const obj
    if(!dict.count(key)){
        insertionOrder.push_back(key);
        dict[key] = value;
    }else{
        dict[key] = value;
    }
}

template<typename keyType, typename dataType>
inline dataType dictionary<keyType,dataType>::getat(const keyType key) const{ // Getting a value at index in a const obj
    exceptKeyNotInMap(key);
    return dict.at(key);
}

template<typename keyType, typename dataType>
inline dataType dictionary<keyType,dataType>::getat(const keyType key){ // Getting a value at index in a non-const obj
    return this->operator[](key);
}

template<typename keyType, typename dataType>
inline dataType dictionary<keyType,dataType>::at(const int index) const{  // Getting a value at index in a const oj
    exceptIndexOutOfBounds(index);
    keyType key = insertionOrder[index];
    exceptKeyNotInMap(key);
    return dict.at(key);
}

template<typename keyType, typename dataType>
inline dataType& dictionary<keyType,dataType>::at(const int index){ // Getting a value at index in a non-const obj
    exceptIndexOutOfBounds(index);
    keyType key = insertionOrder[index];
    if (!dict.count(key)) throw std::runtime_error("Inconsistency between map keys and insertion order");
    return dict[key];
}

template<typename keyType, typename dataType>
inline int dictionary<keyType,dataType>::size() const{         //for getting the size of the dictionary
    return insertionOrder.size();
}

template<typename keyType, typename dataType>
const dictionary<keyType,dataType>& dictionary<keyType,dataType>::operator=(const dictionary<keyType,dataType>& a){   //assignment operator
    insertionOrder = a.insertionOrder;
    dict = a.dict;
}

template<typename keyType, typename dataType>
inline dataType& dictionary<keyType,dataType>::operator[](const keyType key){     //returning a reference to the element at index in a non const obj
    if (!dict.count(key)) insertionOrder.push_back(key);
    return dict[key];
}

template<typename keyType, typename dataType>
inline dataType dictionary<keyType,dataType>::operator[](const keyType key) const{//returning the value at index in a const obj
    return getat(key);
}

template<typename keyType, typename dataType>
bool dictionary<keyType,dataType>::operator==(const dictionary& a) const{    //eq operator between const objs
    return (a.dict == dict && a.insertionOrder == insertionOrder);
}

template<typename keyType, typename dataType>
inline keyType dictionary<keyType,dataType>::keyAt(const int index) const{ //to get key at index
    exceptIndexOutOfBounds(index);
    return insertionOrder[index];
}

template<typename keyType, typename dataType>
inline int dictionary<keyType,dataType>::getIndex(const keyType key) const { //to get index of key
    return findKeyIndex(key);
}

template<typename keyType, typename dataType>
void dictionary<keyType,dataType>::remove(const keyType key){ //removing an element at index a
    exceptKeyNotInMap(key);
    int index = findKeyIndex(key);
    insertionOrder.erase(insertionOrder.begin()+index);
    dict.erase(key);
}

template<typename keyType, typename dataType>
void dictionary<keyType,dataType>::removeAt(const int index){ //removing an element at index a
    exceptIndexOutOfBounds(index);
    keyType key = insertionOrder[index];
    exceptKeyNotInMap(key);
    insertionOrder.erase(insertionOrder.begin()+index);
    dict.erase(key);
}

template<typename keyType, typename dataType>
inline bool dictionary<keyType,dataType>::exists(const keyType key){
    return dict.count(key);
}

template<typename keyType, typename dataType>
inline bool dictionary<keyType,dataType>::indexExists(const int index){
    if(index >= insertionOrder.size() || index < 0) return false;
    else {
        if(!exists(insertionOrder[index])) throw std::runtime_error("Inconsistency between map keys and insertion order");
        return true;        
    }
   
}

template<typename keyType, typename dataType>
inline void dictionary<keyType,dataType>::clear(){
    insertionOrder.clear();
    dict.clear();
}

