#include <stdio.h>
#include <string.h>
struct book // 结构体类型的声明
{
    char name[20]; // 书名,字符串类型
    float price;
    int page;
};
int main()
{
    struct book p1 = // 结构体变量的定义
        {
            "c语言",
            45.00,
            660};
    printf("%s\n", p1.name);
    printf("%f\n", p1.price);
    printf("%d\n", p1.page);
    printf("%d\n", &p1); // 结构体变量的地址
    printf("%p\n", p1);  // 结构体变量的第一个成员的地址
    struct book *p2 = &p1;
    p2->price = 55.00; // 修改结构体变量的值，使用->符号
    printf("%d\n", p2);
    printf("%p\n", *p2); // 结构体变量的地址就是结构体变量的第一个成员的地址
    printf("%f\n", p1.price);
    strcpy(p1.name, "c++"); // 修改字符串类型的值,需要使用strcpy函数，是string copy的缩写，使用string.h头文件
    printf("%s\n", p1.name);
}