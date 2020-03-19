// 2798.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int N, M;
    scanf_s("%d %d", &N, &M);
    int card[100];

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &card[i]);
    }

    int sum = 0;
    int summax = 0;
    for (int i = 0; i < N - 2 ; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = card[i] + card[j] + card[k];
                if ((sum<=M)&&(summax < sum)) summax = sum;
            }
        }
    }

    printf("%d\n",summax);

    return 0;
}

