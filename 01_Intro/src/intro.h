#ifndef _INTRO_H_
#define _INTRO_H_
#include <iostream>

class Intro
{
public:
    Intro();
    virtual ~Intro();
    Intro(int n);  
    Intro(const Intro& other);  
    void Print();  
private:  
    int value; 
};
#endif //intro
