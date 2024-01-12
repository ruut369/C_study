#include <stdio.h>
#include <assert.h>
// memmove()函数作用：从src拷贝num个字节到dst，如果dst<src，从前往后拷贝，如果dst>src，从后往前拷贝
// void* memmove(void*dst,const void*src,unsigned int num); 解决memcpy()内存重叠问题,可以自我拷贝
void *my_memmove(void *dst, const void *src, size_t num) // memmove函数复现
{
    assert(dst && src);
    char *ret = dst;
    if (dst <= src) // 从 前 》 后 拷贝
    {
        do
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        } while (--num); // 前置-- 先减减再判断
    }
    else // 从 后 》 前 拷贝
    {
        while (num--)
        {
            *((char *)dst + num) = *((char *)src + num);
        }
    }

    return ret;
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    my_memmove(arr + 2, arr + 4, 20);
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}