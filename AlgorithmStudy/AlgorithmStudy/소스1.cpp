#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int X;
    scanf("%d", &X);

    int shoesNum;
    scanf("%d", &shoesNum);

    vector<vector<int>> shoes(shoesNum, vector<int>(4, 0));
    int a, b, c, d;
    for (int i = 0; i < shoesNum; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        shoes[i][0] = a;
        shoes[i][1] = b;
        shoes[i][2] = c;
        shoes[i][3] = d;
    }
    //shoes Á¤·Ä
    sort(shoes.begin(), shoes.end(), &compare);

    int distance = 0;
    int speed = 1;
    int s = 0;
    bool change = false;

    vector<int> timestamp(X + 1, 1);
    for (int i = 0; i < shoesNum; i++) {
        int start = shoes[i][0];
        int end = shoes[i][0] + shoes[i][1] + shoes[i][2] - 1;
        int prv;
        if (change)
            prv = shoes[s][0] + shoes[s][1] + shoes[s][2] - 1;
        else
            prv = end;
        int now = 0;
        int wear = 0;
        if (prv < end)
            prv = end;
        if (end > X || shoes[i][0] + shoes[i][1] - 1 > X)
            continue;
        for (int j = start; j <= prv; j++) {
            now += timestamp[j];
            if (j >= start + shoes[i][1]) {
                if (j <= end)
                    wear += shoes[i][3];
                else
                    wear += 1;
            }
        }

        if (now <= wear) {
            if (change && (shoes[s][0] + shoes[s][1] + shoes[s][2] - 1) > end) {
                for (int j = end + 1; j <= shoes[s][0] + shoes[s][1] + shoes[s][2] - 1; j++)
                    timestamp[j] = 1;
            }
            s = i;
            change = true;
            for (int j = start; j <= end; j++) {
                if (j < start + shoes[i][1])
                    timestamp[j] = 0;
                else
                    timestamp[j] = shoes[i][3];
            }
        }
    }

    for (int i = 1; i <= X + 1; i++) {

        distance += timestamp[i - 1];
    }

    cout << distance;

    return 0;
}