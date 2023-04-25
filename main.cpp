#include <iostream>
#include "stack_ch.h"
#include "stack_str.h"
#include "notations.h"
#include <Windows.h>
HANDLE h_1Console;
int main() {
    h_1Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h_1Console, 10);
    Stack_ch new_stack;
    Stack_str str_stack;
    short int key_str(-1), key_rev(1);
    std :: string str;
    bool flagRepeat = true;
    std :: cout << std :: fixed;
    std :: cout.precision(2);
    char key;
    while(flagRepeat){
        SetConsoleTextAttribute(h_1Console, 14);
        std :: cout << "\t~~What form will the expression take~~\n1) Common expression\n2) Straight notation\n3) Reverse notation\n0) Exit\n";
        SetConsoleTextAttribute(h_1Console, 10);
        std :: cin >> key;
        std :: cin.clear();
        while(std :: cin.get() != '\n');
        std :: cout << "\t~~Enter a mathematical expression~~\n";
        getline(std :: cin, str);
        switch (key) {
            case '1':{
                std :: cout << "\t~~Which notation do you want to build~~\n1) Straight\n2) Reverse\n";
                std :: cin.clear();
                while(std :: cin.get() != '\n');
                std :: cin >> key;
                switch (key) {
                    case'1':{
                        ReverseOrStraight_Notation str_notation(str,new_stack,key_str);
                        reversingString(str_notation.result);
                        str_notation.output();
                        std :: cin.clear();
                        while(std :: cin.get() != '\n');
                        str_notation.calculation(str_stack);
                        break;
                    }
                    case'2':{
                        ReverseOrStraight_Notation rev_notation(str,new_stack,key_rev);
                        rev_notation.output();
                        std :: cin.clear();
                        while(std :: cin.get() != '\n');
                        rev_notation.calculation(str_stack);
                        break;
                    }
                    default :{
                        SetConsoleTextAttribute(h_1Console, 12);
                        std :: cout <<"error";
                        SetConsoleTextAttribute(h_1Console, 10);
                    }
                }
                break;
            }
            case '2':{
                ReverseOrStraight_Notation str_notation(str,key_str);
                str_notation.calculation(str_stack);
                break;
            }
            case '3':{
                ReverseOrStraight_Notation rev_notation(str,key_rev);
                rev_notation.calculation(str_stack);
                break;
            }
            case'0':{
                flagRepeat = false;
                break;
            }
            default:{
                SetConsoleTextAttribute(h_1Console, 12);
                std :: cout << "error\n";
                SetConsoleTextAttribute(h_1Console, 10);
            }
        }
    }
    system("pause");
    return 0;
}
