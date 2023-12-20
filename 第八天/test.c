// 密码判断
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    printf("请输入密码：");
    char password[20] = {0};
    for (i = 0; i < 3; i++)
    {
        scanf("%s", password);
        if (strcmp(password, "2364207841") == 0) // 字符串比较,strcmp函数是比较两个字符串的大小，如果相等返回0，如果s1>s2返回正数，如果s1<s2返回负数
        {
            printf("密码正确，登录成功\n");
            break;
        }
        else
        {
            printf("密码错误，请重新输入\n");
        }
    }
    if (i == 3)
    {
        printf("三次密码输入错误，退出程序\n");
    }
    return 0;
}