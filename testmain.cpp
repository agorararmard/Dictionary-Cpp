#include <iostream>
#include <string>
#include <stdexcept>
#include"dictionary.h"
using namespace std;


int main(){

    dictionary d;
    d.insert("amr", 0);
    d.insert("ahmed", 6);
    d.insert("habiba", 5);
    d.insert("salah", 10);
    for (int i =0; i < d.size();i++){
        cout << d.at(i)<< endl;
    }
    cout <<"#####\n";
    try{
        cout << d.at(4);
    }catch(std::runtime_error& e){
        cout << e.what() << endl;
    }
    cout <<"#####\n";
    try{
        d.removeAt(4);
    }catch(std::runtime_error& e){
        cout << e.what() << endl;
    }
    cout <<"#####\n";
    try{
        d.remove("Cabo");
    }catch(std::runtime_error& e){
        cout << e.what() << endl;
    }
    cout <<"#####\n";
    d.at(0)++;
    d["amr"]++;
    cout << d["amr"] << endl;
    d.removeAt(2);
    cout <<"#####\n";
    for (int i =0; i < d.size();i++){
        cout << d.at(i)<< endl;
    }
    cout <<"#####\n";
    d["karim"]= 100;
    for (int i =0; i < d.size();i++){
        cout << d.at(i)<< endl;
    }
    cout << "####\n";
    d.remove("salah");
    for (int i =0; i < d.size();i++){
        cout << d.at(i)<< endl;
    }
    cout << "####\n";
    cout <<d.exists("salah")<<endl;
    cout <<d.exists("amr")<<endl;
    cout <<d.indexExists(2)<<endl;
    cout <<d.indexExists(3)<<endl;
    cout << "####\n";
    for (int i =0; i < d.size();i++){
        cout << d.keyAt(i)<< endl;
    }
    cout << "####\n";
    cout << d.getIndex("amr") << endl;
    cout << d.getIndex("ahmed") << endl;
    cout << d.getIndex("karim") << endl;

    cout << "####\n";
    const dictionary b(d);
    if(d == b)
        cout << "sucess\n";
    else
        cout << "fail\n";
    cout << "####\n";
    dictionary c;
    c = b;

    d.clear();
    
    if(c == b)
        cout << "sucess\n";
    else
        cout << "fail\n";

    if(d == b)
        cout << "fail\n";
    else
        cout << "success\n";
    
    c.insert("new me", 15000);
    
    if(d == c)
        cout << "fail\n";
    else
        cout << "success\n";
    cout << "####\n";
    for (int i =0; i < b.size();i++){
        cout << b[b.keyAt(b.getIndex(b.keyAt(i)))]<< endl;
        cout << b.at(i)<< endl;

    }
    cout << "####\n";
    return 0;
}