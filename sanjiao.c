//如何用三角形三边长快速求算三角形面积
//p=1/2周长
//海伦公式：根号下p乘p减各边的长
#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    float p = (a+b+c)/2;
    float S = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1f",S);
//已知三个点的坐标
//S = 1/2（AB x AC）矢量积
//或使用推荐公式
int main() {
    double x1, y1, x2, y2, x3, y3;
    // 输入三个点的坐标
    printf("请输入三个点的坐标：\n");
    printf("点 A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("点 B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("点 C (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    // 计算面积：S = 1/2 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
    double area = 0.5 * fabs(
        x1 * (y2 - y3) +
        x2 * (y3 - y1) +
        x3 * (y1 - y2)
    );
    // 输出结果，保留两位小数
    printf("三角形面积为: %.2f\n", area);
    return 0;
}
}

