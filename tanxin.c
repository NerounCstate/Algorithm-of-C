/*#P2240 【深基12.例1】部分背包问题

##题目描述
    阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有N(N<=100)堆金币，第i堆金币的总重量和总价值分别是m_i,v_i(i<=m_i,v_i<=100)。阿里巴巴有一个承重量为T(T<=1000)的背包，但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？
    ##输入格式
    第一行两个整数 N, T。
    接下来 N 行，每行两个整数 m,v。
    ##输出格式
    一个实数表示答案，输出两位小数
    ##输入输出样例 #1
    ## #输入 #1
``` 4 50
    10 60
    20 100
    30 120
    15 45
```
    ## #输出 #1
``` 240.00
```*/

#include <stdio.h>
#include <stdlib.h>
// 定义结构体用于存储每一堆的属性
typedef struct
{
    int m;             // 重量
    int v;             // 总价格
    double unit_value; // 单价
} Item;

// 比较函数，降序排列价值
// 此函数仅用于比较，不应该修改数据，所以使用const防止修改，void*表示任意类型指针
int cmp(const void *a, const void *b)
{

    Item *x = (Item *)a;
    Item *y = (Item *)b;
    // 返回值为正数表示x应排在y前面，负数表示y应排在x前面，0表示相等
    // 返回负,x在前；返回正，y在前
    // 如果想从大到小排列的话可以理解成：若x>y，y-x<0......
    if (x->unit_value < y->unit_value)
    {
        return 1;
    }
    else if (x->unit_value > y->unit_value)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// 主函数
int main()
{
    int N, T; // N是一共几堆物品，T是背包容量
    printf("请输入一共几堆和背包容量\n");
    scanf("%d %d", &N, &T);
    Item items[10000];
    // 把每一堆物品的单价计算出来并存储到items数组中
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &items[i].m, &items[i].v);
        // 使用double使结果精准
        items[i].unit_value = (double)items[i].v / items[i].m;
    }

    // stdlib中用于快速排列数组中元素的函数
    // qsort(数组元素首地址,数组中元素个数,每个元素所占字节大小,自定义函数用于告诉qsort如何比较两个数)
    // 注意！！！大小应该是Item结构体的大小，而不是int的大小
    qsort(items, N, sizeof(Item), cmp);
    // 排序后的items数组中的元素就是按各自的unit_value降序排列的了

    // 设定剩余空间与总容量
    double total_value = 0.0;
    int remaining = T;

    // 开始贪心拿取
    // 如果剩余空间大于零就继续拿
    for (int i = 0; i < N && remaining > 0; i++)
    {
        if (items[i].m <= remaining)
        {
            total_value = total_value + items[i].v;
            remaining = remaining - items[i].m;
        }
        else if (items[i].m > remaining)
        {
            total_value = total_value + remaining * items[i].unit_value;
            remaining = 0;
        }
    }
    printf("%.2f", total_value);
}