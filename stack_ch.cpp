//
// Created by aleks on 25.04.2023.
//
#include <iostream>
#include "stack_ch.h"
#include <Windows.h>
HANDLE h2Console;
void Stack_ch :: itemPush(char value) {
    stack_ch * item = new stack_ch;
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
void Stack_ch :: itemOut(std :: string &str){
    if(!empty()){
        stack_ch ** buff = new stack_ch * (curr);
        if( curr->data != '(' and curr->data != ')') {
            str.push_back(curr->data);
            str.push_back(' ');
        }
        curr = curr->tail;
        delete *buff;
        delete buff;
    }
    else {
        SetConsoleTextAttribute(h2Console, 12);
        std :: cout <<"Stack is empty"<<'\n';
        SetConsoleTextAttribute(h2Console, 10);
    }
}
void Stack_ch :: stackOut(){
    if(!empty()){
        stack_ch * buff = curr;
        std :: cout << "~~Stack : ";
        while(buff){
            std :: cout << buff->data << " ";
            buff = buff->tail;
        }
        std :: cout << "\n      head^\n\n";
    }
    else {
        SetConsoleTextAttribute(h2Console, 12);
        std :: cout <<"~~Stack is empty~~"<<'\n';
        SetConsoleTextAttribute(h2Console, 10);
    }
}
stack_ch * Stack_ch :: GetCurr(){
    return curr;
}
bool Stack_ch :: empty(){
    if(curr == nullptr) return true;
    else return false;
}