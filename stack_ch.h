//
// Created by aleks on 25.04.2023.
//

#ifndef NEW_POLISHNOTATION_STACK_CH_H
#define NEW_POLISHNOTATION_STACK_CH_H
struct stack_ch{
    char data;
    stack_ch *tail;
};
class Stack_ch{
private:
    stack_ch * curr = nullptr;
public:
    void itemPush(char value);
    void itemOut(std::string &str);
    void stackOut();
    stack_ch * GetCurr();
    bool empty();
};
#endif //NEW_POLISHNOTATION_STACK_CH_H
