//
// Created by xale3k on 18.04.2022.
//

#ifndef SIAOD7_LISTSTACK_H
#define SIAOD7_LISTSTACK_H

#include <string>
using namespace std;

//Стек с использованием списка
template<typename T>
class ListStack {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head;
    string name;
    int size=0;
public:
    ListStack() {
        head = nullptr;
    }
    ~ListStack() {
        while (head != nullptr) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    bool AddEl(T data){
        Node *tmp = new Node;
        tmp->data = data;
        tmp->next = head;
        head = tmp;
        size++;
        return true;
    }
    //take element from end of stack
    bool TakeEl(T& m){
        if (head == nullptr) {
            return false;
        }
        Node *tmp = head;
        m = tmp->data;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }

    bool isEmpty() {
        return head == nullptr;
    }
    string StackName(){
        return name;
    }
    int CurrentLength(){
        return size;
    }
};

#endif //SIAOD7_LISTSTACK_H
