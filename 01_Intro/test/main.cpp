#include "intro.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // 创建一个 Intro 类的实例  
    Intro intro1(10);  
  
    // 调用 Print 方法打印 intro1 的值  
    intro1.Print();  
  
    // 使用拷贝构造函数创建另一个 Intro 类的实例  
    Intro intro2(intro1);  
  
    // 调用 Print 方法打印 intro2 的值（它应该与 intro1 的值相同）  
    intro2.Print(); 

    return 0;
}

