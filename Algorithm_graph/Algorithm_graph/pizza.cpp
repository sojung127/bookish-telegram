#include <cstdio>
#include <vector>

using namespace std;

int k, n, m, A[1000], B[1000], Acnt[2000001], Bcnt[2000001], ret;
// 1000*1000 �ִ� 1000ũ���� ���� �ִ� 1000���� ���� 2���� --> 2000001 
void func(int p, int arr[], int arrCnt[]) {
    for (int i = 1; i <= p; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) //j�� ������ ���� �ε��� i�� ������ ũ�� 
            sum += arr[j];
        arrCnt[sum]++;  // a���� �������� i��°�� ���������� �� �������� ������ ������ ���Ƹ��°�..
        if (sum == k) ret++; // ������ ���ڿ��� �� ���ð����Ҷ�
        //���� sum�� 0���� i������ �����տ� ���� ������ ���
        if (i == p) break;  
        // �������� ���� ���ؼ�..? 
        // �� ���������� �������� �����ϰ� 
        // �������� ��������� ���� �����鿡�� ������ �����յ��� ������ ����ϴ� ����. 
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
    //���� �� �Լ��� �����ϰ��� ������ ��� ���ӱ������� ������ �տ� ���� ������ �� ���ں��� ī��Ʈ �Ǿ��ִ�.
    for (int i = 1; i < k; i++) {
        int j = k - i;
        ret += Acnt[i] * Bcnt[j]; // ���� k�� �Ǵ� ����Ǽ��� ���Ѱ�..
    }
    printf("%d", ret);
}