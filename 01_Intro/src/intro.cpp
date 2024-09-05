#include "intro.h"

Intro::Intro(){ }

Intro::~Intro(){ }

Intro::Intro(int n) {  
    value = n;
    std::cout<<"value for intro first function:"<<value<<std::endl;
}  

Intro::Intro(const Intro& other) {  
    value = other.value;  
    std::cout<<"value for intro structure function:"<<value<<std::endl;
}  

void Intro::Print() {  
    // 实现打印逻辑  
    std::cout << "Value: " << value << std::endl;  
}



