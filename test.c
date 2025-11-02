#include <stdio.h>
int main()
{
    int budget, remaining = 0, saved = 0;
    int month = 0;

    for (int i = 0; i < 12; i++)
    {
        remaining += 300;
        scanf("%d", &budget);
        if (remaining < budget)
        {
            month = i + 1;
            break;
        }
        remaining -= budget;
        if (remaining >= 100)
        {
            int save_amount = (remaining / 100) * 100;
            saved += save_amount;
            remaining -= save_amount;
        }
    }

    if (month != 0)
    {
        printf("-%d\n", month);
    }
    else
    {
        int total = saved * 1.2 + remaining;
        printf("%d\n", total);
    }

    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int s = 0, b = 0, r = 0;
//     int t = 0;
//     // b是预算，r是剩余的钱，s是存的钱
//     for (int i = 0; i < 12; i++)
//     {
//         r = r + 300;
//         scanf("%d", &b);
//         if (r >= b)
//         {
//             r = (r - b) % 100;
//         }
//         else
//         {
//             r = 0;
//             if (t != 0)
//             {
//                 t = i + 1;
//             }
//         }
//     }
//     if (t != 0)
//     {
//         printf("-%d", t);
//     }
//     else
//     {
//         printf("%d", r * 1.2);
//     }
// }