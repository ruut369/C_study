#include <stdio.h>
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *e1, const void *e2));
// base:要排序的数据起始位置，nmemb：待排序元素个数，size：每个元素大小，compar：函数指针，比较函数，e1,e2为待比较两个元素的地址
int cmp(const void *e1, const void *e2)
{
    return -(*(int *)e1 - *(int *)e2);
}
struct student
{
    char name[20];
    int age;
};
int my_cmp_struct(const void *e1, const void *e2)
{
    // 强制转换为struct student *结构体指针，->解引用
    //  return strcmp(((struct student *)e1)->name, ((struct student *)e2)->name);
    return ((struct student *)e1)->age - ((struct student *)e2)->age;
}
int main()
{
    int arr[10] = {2, 5, 3, 1, 7, 6, 5, 8, 9, 10};
    struct student stu[] = {{"zhangsan", 20}, {"lisi", 15}, {"wangwu", 25}};
    int sz2 = sizeof(stu) / sizeof(stu[0]);
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp);
    qsort(stu, sz2, sizeof(stu[0]), my_cmp_struct);
    return 0;
}