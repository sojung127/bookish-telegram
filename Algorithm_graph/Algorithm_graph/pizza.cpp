#include <cstdio>
#include <vector>

using namespace std;

int k, n, m, A[1000], B[1000], Acnt[2000001], Bcnt[2000001], ret;
// 1000*1000 최대 1000크기의 피자 최대 1000조각 피자 2종류 --> 2000001 
void func(int p, int arr[], int arrCnt[]) {
    for (int i = 1; i <= p; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) //j는 구간의 시작 인덱스 i는 구간의 크기 
            sum += arr[j];
        arrCnt[sum]++;  // a에서 피자조각 i번째를 선택했을때 그 누적합이 나오는 개수를 세아리는거..
        if (sum == k) ret++; // 한종류 피자에서 다 선택가능할때
        //위의 sum은 0부터 i까지의 누적합에 대한 개수를 계산
        if (i == p) break;  
        // 원형으로 돌기 위해서..? 
        // 각 개수에대한 누적합을 저장하고 
        // 원형으로 만들어지는 연속 구간들에서 나오는 구간합들의 개수를 계산하는 과정. 
        for (int j = 1; j < p; j++) { 
            sum -= arr[j - 1];
            sum += arr[(j + i - 1) % p];
            arrCnt[sum]++;
            if (sum == k) ret++;
        }
    }
}

int main() {
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    func(n, A, Acnt);
    func(m, B, Bcnt);
    //위의 두 함수를 실행하고나면 원형의 모든 연속구간에서 나오는 합에 대한 개수가 각 피자별로 카운트 되어있다.
    for (int i = 1; i < k; i++) {
        int j = k - i;
        ret += Acnt[i] * Bcnt[j]; // 합이 k가 되는 경우의수를 곱한거..
    }
    printf("%d", ret);
}