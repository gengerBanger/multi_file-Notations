//
// Created by aleks on 25.04.2023.
//

#ifndef NEW_POLISHNOTATION_STACK_STR_H
#define NEW_POLISHNOTATION_STACK_STR_H
struct List_str;
class Stack_str{
private:
    List_str * curr = nullptr;
public:
    void itemPush(std :: string value);
    std :: string itemOut();
    void stackOut();
    bool pairCheck();
    void stackDelete();
    List_str * GetCurr();
    bool empty();
};
#endif //NEW_POLISHNOTATION_STACK_STR_H
