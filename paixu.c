/*#P1271 【深基9.例1】选举学生会

##题目描述
    学校正在选举学生会成员，有n（$1<=n<=999）名候选人，每名候选人编号分别从1到n，现在收集到了m（1<=m<=2000000）张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。设第i（1<=i<=m）张选票上的数字为a_i，则保证有1<=a_i<=n。
    ##输入格式
        输入n和m以及m个选票上的数字。
    ##输出格式
        求出排序后的选票编号。
    ##输入输出样例 #1
    ## #输入 #1
``` 5 10
    2 5 2 2 5 2 2 2 1 2
    ## #输出 #1
``` 1 2 2 2 2 2 2 2 5 5
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    // x-y>0说明x>y，输出正数，小的靠前
    return x - y;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int mingdan[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &mingdan[i]);
    }
    qsort(mingdan, m, sizeof(int), cmp);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", mingdan[i]);
    }
}