//
// Created by aleks on 25.04.2023.
//
#include <iostream>
#include "stack_str.h"
#include <Windows.h>
HANDLE hConsole;
struct List_str{
    std :: string data;
    List_str *tail;
};
void Stack_str ::itemPush(std::string value) {
    List_str * item = new List_str;
    if(curr == nullptr){
        curr = item;
        item->tail = nullptr;
    }
    else{
        item->tail = curr;
        curr = item;
    }
    item->data = value;
}
std :: string Stack_str ::itemOut() {
    if(!empty()){
        List_str ** buff = new List_str*(curr);
        std :: string buff_str;
        buff_str = curr->data;
        curr = curr->tail;
        delete *buff;
        delete buff;
        return buff_str;
    }
    else {
        SetConsoleTextAttribute(hConsole, 12);
        std :: cout <<"Stack is empty"<<'\n';
        SetConsoleTextAttribute(hConsole, 10);
    }
}
void Stack_str :: stackOut(){
    if(!empty()){
        List_str * buff = curr;
        std :: cout << "~~Stack : ";
        while(buff){
            std :: cout << buff->data << " ";
            buff = buff->tail;
        }
        std :: cout << "\n      head^\n\n";
    }
    else{
        SetConsoleTextAttribute(hConsole, 12);
        std :: cout <<"~~Stack is empty~~"<<'\n';
        SetConsoleTextAttribute(hConsole, 10);

    }
}
bool Stack_str ::pairCheck() {
    if(!empty()){
        if(curr->tail != nullptr){
            return true;
        }
        else return false;
    }
    else return false;
}
void Stack_str :: stackDelete(){
    while (curr){
        List_str * buff = curr;
        curr = curr->tail;
        delete buff;
    }
}
List_str * Stack_str :: GetCurr(){
    return curr;
}
bool Stack_str :: empty(){
    if(curr == nullptr) return true;
    else return false;
}