//
// Created by aleks on 25.04.2023.
//
#include <iostream>
#include "notations.h"
#include "stack_str.h"
#include "stack_ch.h"
#include <map>
#include <Windows.h>
HANDLE h_strConsole;
void reversingString(std :: string &str){
    std :: string reverse_str;
    for(int i = str.length() - 1; i >= 0;i--){
        reverse_str.push_back(str[i]);
    }
    str = reverse_str;
}
int ReverseOrStraight_Notation ::checkPriority(char num) {
    switch(num){
        case '(':{
            return ReverseOrStraight_flag;
        }
        case'+':case'-':{
            return 2;
        }
        case'*':case'/':{
            return 3;
        }
        case')':{
            return -ReverseOrStraight_flag;
        }
        default : {
            return 0;
        }
    }
}
void ReverseOrStraight_Notation ::outResult(std::string &new_str, Stack_ch &sta) {
    sta.stackOut();
    std :: cout << "~~String :"<< new_str<<" \n\n";
}
bool ReverseOrStraight_Notation ::checkString(std::string str) {
    for(int i = 0; i < str.length(); i++) {
        if(LetterCheck(str[i]) and (LetterCheck(str[i + 1]))) return false;
        if ((checkPriority(str[i]) == checkPriority(str[i + 2])) and str[i + 1] == ' ')return false;
        if(((checkPriority(str[i]) == 2) or (checkPriority(str[i]) == 3)) and ((checkPriority(str[i + 1]) == 2) or (checkPriority(str[i + 1]) == 3))) return false;
        if (((checkPriority(str[i]) == 2) or (checkPriority(str[i]) == 3) or (checkPriority(str[i]) == -1)) and i == 0)return false;
        if (((checkPriority(str[i]) == 2) or (checkPriority(str[i]) == 3) or (checkPriority(str[i]) == 1)) and
            i == str.length() - 1) return false;
        if(checkPriority(str[i]) == 1 and checkPriority(str[i + 1]) == -1 )return false;
    }
    return true;
}
void ReverseOrStraight_Notation ::processing(std::string str, std::string &new_str, Stack_ch &sta) {
    std :: string buffStr;
    for(int i = 0; i < str.length();i++) {
        buffStr.clear();
        switch (checkPriority(str[i])) {
            case 0:{
                do{
                    buffStr+=str[i++];
                }while(checkPriority(str[i]) == 0 && i < str.length());
                i--;
                new_str += buffStr + ' ';
                break;
            }
            case 1:{
                sta.itemPush(str[i]);
                break;
            }
            case 2: case 3: {
                if(sta.empty()) {
                    sta.itemPush(str[i]);
                }
                else{
                    if (checkPriority(str[i]) > checkPriority(sta.GetCurr()->data)){
                        sta.itemPush(str[i]);
                    }
                    else{
                        while(!sta.empty() && checkPriority(sta.GetCurr()->data) >= checkPriority(str[i])){
                            sta.itemOut(new_str);
                        }
                        sta.itemPush(str[i]);
                    }
                }
                break;
            }
            case -1:
            {
                while(checkPriority(sta.GetCurr()->data) != 1){
                    sta.itemOut(new_str);
                }
                sta.itemOut(new_str);
                break;
            }
        }
        outResult(new_str,sta);
    }
    while(!sta.empty()){
        sta.itemOut(new_str);
    }
}
void ReverseOrStraight_Notation ::removingSpaces(std::string &str) {
    for(int i = 0; i < str.length(); i++){
        if ((str[i] == ' ') && (str[i + 1] == ' ')) {
            while (!((str[i] == ' ') && (str[i + 1] != ' '))) {
                str.erase(str.begin() + i);
            }
        }
    }
}
bool ReverseOrStraight_Notation ::LetterCheck(char ch) {
    return (ch >= 'A'&& ch <= 'Z') || (ch >= 'a'&& ch <= 'z');
}
void ReverseOrStraight_Notation :: initialization(std :: string &str){
    std :: map <char,std :: string> storage;
    for(int i = 0; i < str.length(); i++){
        if(LetterCheck(str[i])){
            storage[str[i]] = '0';
        }
    }
    if(!storage.empty()){
        for( auto it = storage.begin();it != storage.end();it++){
            std :: cout <<"~~enter "<< it->first << " value~~\n";
            std :: cin >>it->second;
        }
        for(int i = 0; i < str.length(); i++){
            if(LetterCheck(str[i])){
                char *g = new char (str[i]);
                str.erase(i, 1);
                str.insert(i,storage[*g]);
                delete g;
            }
        }
    }
}
void ReverseOrStraight_Notation :: checkChar(char ch, Stack_str &sta){
    switch (ch) {
        case'+':
        {
            double i1(std:: stod(sta.itemOut())), i2(std :: stod(sta.itemOut()));
            sta.itemPush(std ::to_string(i1 + i2));
            break;
        }
        case'-':
        {
            double i1(std:: stod(sta.itemOut())), i2(std :: stod(sta.itemOut()));
            if (ReverseOrStraight_flag == 1)sta.itemPush(std ::to_string(i2 - i1));
            else sta.itemPush(std ::to_string(i1 - i2));
            break;
        }
        case'*':
        {
            double i1(std:: stod(sta.itemOut())), i2(std :: stod(sta.itemOut()));
            sta.itemPush(std ::to_string(i1 * i2));
            break;
        }
        case'/':
        {
            double i1(std:: stod(sta.itemOut())), i2(std :: stod(sta.itemOut()));
            if (ReverseOrStraight_flag == 1) sta.itemPush(std ::to_string(i2 / i1));
            else  sta.itemPush(std ::to_string(i1 / i2));
            break;
        }
    }
}
ReverseOrStraight_Notation :: ReverseOrStraight_Notation(std::string str, Stack_ch sta, short int key) {
    ReverseOrStraight_flag = key;
    if(checkString(str)){
        initialization(str);
        if(ReverseOrStraight_flag == 1) {
            SetConsoleTextAttribute(h_strConsole, 13);
            std :: cout << "----------String : " << str << '\n';
            SetConsoleTextAttribute(h_strConsole, 10);
        }
        else{
            SetConsoleTextAttribute(h_strConsole, 13);
            std :: cout << "-----String : " << str << '\n';
            SetConsoleTextAttribute(h_strConsole, 10);
            reversingString(str);
        }
        processing(str, result,sta);
        removingSpaces(result);
        flagCreation = true;
    }
    else{
        flagCreation = false;
    }
}
ReverseOrStraight_Notation ::ReverseOrStraight_Notation(std::string str, short int key) {
    ReverseOrStraight_flag = key;
    result = str;
}
void ReverseOrStraight_Notation ::calculation(Stack_str sta) {
    if(!result.empty()){
        bool InvalidInput = true;
        if(ReverseOrStraight_flag == -1) reversingString(result);
        std :: string buffStr;
        for(int i = 0; i < result.length() && InvalidInput; i++){
            buffStr.clear();
            switch (checkPriority(result[i])) {
                case 0:{
                    do{
                        if(result[i] != ' ')buffStr += result[i++];
                        else {
                            i++;
                            break;
                        }
                    }while(checkPriority(result[i]) == 0 && i < result.length());
                    i--;
                    if(ReverseOrStraight_flag == -1) reversingString(buffStr);
                    if(!buffStr.empty())sta.itemPush(buffStr);
                    break;
                }
                case 2: case 3:{
                    if(sta.pairCheck())checkChar(result[i], sta);
                    else{
                        SetConsoleTextAttribute(h_strConsole, 12);
                        std :: cout <<"Invalid input\n";
                        SetConsoleTextAttribute(h_strConsole, 10);
                        InvalidInput = false;
                        sta.stackDelete();
                    }
                    break;
                }
            }
            sta.stackOut();
        }
        if(!sta.pairCheck() && !sta.empty()){
            SetConsoleTextAttribute(h_strConsole, 13);
            std :: cout << "----------Result : " << std :: stod(sta.itemOut())<< " ~~\n";
            SetConsoleTextAttribute(h_strConsole, 10);
        }
    }
}
void ReverseOrStraight_Notation :: output(){
    if(flagCreation && ReverseOrStraight_flag == 1) std :: cout <<"Reverse Notation :"<< result <<'\n';
    else{
        if(flagCreation && ReverseOrStraight_flag == -1) std :: cout <<"Straight Notation :"<< result <<'\n';
        else{
            SetConsoleTextAttribute(h_strConsole, 12);
            std :: cout <<"Invalid input\n";
            SetConsoleTextAttribute(h_strConsole, 10);
        }
    }
}
