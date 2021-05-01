﻿// AlgorithmStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

void mystery(int x[], int k, int n) {
    if (k == n) {
		for (int i = 1; i <= n; i++)
			printf("%d ", x[i]);

        printf("\n");
    }
    else {
        printf("k=%d\n", k);
        for (int i = k; i <= n; i++) {
            printf("%d %d \n", i, k);
            swap(&x[i], &x[k]);
            
            mystery(x, k + 1, n);
                printf("%d %d \n", i, k);
            swap(&x[i], &x[k]);
            
        }
    }
}
int main()
{
    int x[9] = { 0,1,2,3,4,5,6,7,0 };
    int k = 3;
    mystery(x, 3, 5);

    for (int i = 1; i <= 3; i++)
        printf("%d ", x[i]);

    printf("\n");

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
