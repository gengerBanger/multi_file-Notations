//
// Created by aleks on 25.04.2023.
//

#ifndef NEW_POLISHNOTATION_NOTATIONS_H
#define NEW_POLISHNOTATION_NOTATIONS_H
#include "stack_ch.h"
#include "stack_str.h"
void reversingString(std :: string &str);
class ReverseOrStraight_Notation{
private:
    bool flagCreation{};
    int ReverseOrStraight_flag;
    int checkPriority(char num);
    void outResult(std :: string &new_str, Stack_ch &sta);
    bool checkString(std :: string str);
    void processing(std :: string str,std :: string &new_str, Stack_ch &sta);
    void removingSpaces(std :: string &str);
    bool LetterCheck(char ch);
    void initialization(std :: string &str);
    void checkChar(char ch, Stack_str &sta);
public :
    std :: string result;
    ReverseOrStraight_Notation(std :: string str, Stack_ch sta,short int key);
    ReverseOrStraight_Notation(std :: string str, short int key);
    void calculation(Stack_str sta);
    void output();
};
#endif //NEW_POLISHNOTATION_NOTATIONS_H
