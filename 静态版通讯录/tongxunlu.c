// 静态版通讯录
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
enum menu // 枚举
{
    EXIT, // 定义初始值，未定义默认0
    ADD,  // 初始值加1
    DEL,  // 2
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};
void menu()
{
    printf("****************************************\n");
    printf("******** 1.add       2.del      ********\n");
    printf("******** 3.search    4.modify   ********\n");
    printf("******** 5.show      6.sort     ********\n");
    printf("******** 0.exit                 ********\n");
    printf("****************************************\n");
}
typedef struct PeoInfo
{
    char name[20];
    int age;
    char sex[10];
    char tele[20];
    char addr[50];
} PeoInfo;
typedef struct contact
{
    struct PeoInfo data[MAX];
    int count; // 统计联系人数量
} contact;
void InitContact(struct contact *ps)
{
    ps->count = 0;
    memset(ps->data, 0, sizeof(ps->data));
}
int FindName(struct contact *ps, char name[])
{
    for (int i = 0; i < ps->count; i++)
    {
        if (0 == strcmp(name, ps->data[i].name))
        {
            return i;
        }
    }
    return -1;
}
void Contact_Add(struct contact *ps)
{
    if (ps->count == MAX)
    {
        printf("通讯录已满，无法添加\n");
        return;
    }
    printf("请输入姓名>");
    scanf("%s", ps->data[ps->count].name); // scanf里面的%s后不要加空格
    printf("请输入年龄>");
    scanf("%d", &(ps->data[ps->count].age));
    printf("请输入性别>");
    scanf("%s", ps->data[ps->count].sex);
    printf("请输入电话>");
    scanf("%s", ps->data[ps->count].tele);
    printf("请输入地址>");
    scanf("%s", ps->data[ps->count].addr);
    ps->count++;
    printf("添加成功\n");
}
void Contact_Del(struct contact *ps)
{
    char input[20] = "";
    printf("请输入姓名>");
    scanf("%s", input);
    int count = FindName(ps, input);
    if (count == -1)
    {
        printf("输入错误，未找到");
    }
    else
    {
        for (int i = count; i < ps->count - 1; i++)
        {
            ps->data[i] = ps->data[i + 1];
        }
        ps->count--;
        printf("删除成功");
    }
}
void Contact_Search(struct contact *ps)
{
    char input[20] = "";
    printf("请输入姓名>");
    scanf("%s", input);
    for (int i = 0; i < ps->count; i++)
    {
        if (strcmp(input, ps->data[i].name) == 0)
        {
            printf("%-20s %-10s %-10s %-20s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
            printf("%-20s %-5d %-10s %-20s %-30s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
            return;
        }
    }
    printf("未找到该用户\n");
    return;
}
void Contact_Modify(struct contact *ps)
{
    char input[20] = "";
    printf("请输入姓名>");
    scanf("%s", input);
    int count = FindName(ps, input);
    if (count == -1)
    {
        printf("输入错误，未找到");
    }
    else
    {
        printf("%-20s %-10s %-10s %-20s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-20s %-5d %-10s %-20s %-30s\n",
               ps->data[count].name,
               ps->data[count].age,
               ps->data[count].sex,
               ps->data[count].tele,
               ps->data[count].addr);
        printf("请输入修改后的姓名>");
        scanf("%s", ps->data[count].name);
        printf("请输入修改后的年龄>");
        scanf("%d", &(ps->data[count].age));
        printf("请输入修改后的性别>");
        scanf("%s", ps->data[count].sex);
        printf("请输入修改后的电话>");
        scanf("%s", ps->data[count].tele);
        printf("请输入修改后的地址>");
        scanf("%s", ps->data[count].addr);
        printf("修改成功\n");
    }
}
void Contact_Show(struct contact *ps)
{
    int count = ps->count;
    printf("%-20s %-10s %-10s %-20s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (int i = 0; i < count; i++)
    {
        printf("%-20s %-5d %-10s %-20s %-30s\n",
               ps->data[i].name,
               ps->data[i].age,
               ps->data[i].sex,
               ps->data[i].tele,
               ps->data[i].addr);
    }
}
int qsort_by_name(const void *e1, const void *e2)
{
    return strcmp(((struct PeoInfo *)e1)->name, ((struct PeoInfo *)e2)->name);
}
void Contact_Sort(struct contact *ps)
{
    qsort(ps->data, ps->count, sizeof(ps->data[0]), qsort_by_name);
    printf("排序成功\n");
}
int main()
{
    int input = 0;
    contact tongxunlu;       // 创建一个通讯录结构体
    InitContact(&tongxunlu); // 初始化通讯录
    do
    {
        menu();
        printf("请选择>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Contact_Add(&tongxunlu);
            break;
        case DEL:
            Contact_Del(&tongxunlu);
            break;
        case SEARCH:
            Contact_Search(&tongxunlu);
            break;
        case MODIFY:
            Contact_Modify(&tongxunlu);
            break;
        case SHOW:
            Contact_Show(&tongxunlu);
            break;
        case SORT:
            Contact_Sort(&tongxunlu);
            break;
        case EXIT:
            printf("退出通讯录\n");
            break;
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
    } while (input);

    return 0;
}