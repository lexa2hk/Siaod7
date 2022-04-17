//
// Created by xale3k on 17.04.2022.
//

#ifndef SIAOD7_SIMPLECHARSTACK_H
#define SIAOD7_SIMPLECHARSTACK_H
#include <string>
using namespace std;


template<typename T>
class Stack {
private:
    string name;
    int size;
    int curlen;
public:
    T* a;
    Stack(string _name = "stack", int _size=100){
        name = _name;
        size = _size;
        curlen = 0;
        a = new T[size];
    }
    bool AddEl(T _el){
        if(curlen < size){
            a[curlen] = _el;
            curlen++;
            return true;
        }
        else{
            return false;
        }
    }
    bool TakeEl(T& m){
        if(curlen > 0){
            m = a[curlen-1];
            curlen--;
            return true;
        }
        else{
            return false;
        }
    }

    string StackName(){
        return name;
    }
    int StackSize(){
        return size;
    }
    int CurrentLength(){
        return curlen;
    }
    ~Stack(){
        delete[] a;
    }
};


#endif //SIAOD7_SIMPLECHARSTACK_H
