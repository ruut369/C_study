#include <stdio.h>
int main()
{
    int sum = 0;
    printf("请输入密码：");

    // 字符串密码
    char password[20] = {0};
    scanf("%s", password);      // 读取字符串，回车会在缓冲区中添加一个\n
    while ((getchar()) != '\n') // 清空缓冲区
    {
        ;
    }
    printf("请确认密码Y/N:");
    sum = getchar();
    if (sum == 'Y')
    {
        printf("确认密码成功\n");
    }
    else
    {
        printf("确认密码失败\n");
    }
    return 0;
}