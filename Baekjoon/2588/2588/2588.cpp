// 2588.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ret1, ret2, ret3, ret;
    ret1 = a * (b % 10);
    printf("%d\n", ret1);
    ret2 = a * ((b % 100)/10);
    printf("%d\n", ret2);
    ret3 = a * ((b % 1000)/100);
    printf("%d\n", ret3);

    ret = ret1 + ret2 * 10 + ret3 * 10 * 10;
    printf("%d\n", ret);

    return 0;
}
