#include <iostream>

using namespace std;


//递推计算Fibonacci第k项，计算时结果对9973取余
int fib(int k) {
    int f0 = 0, f1 = 1, t;
    for (int i = 2; i <= k; i++) {
        t = f1;
        f1 = (f0 + f1) % 9973;
        f0 = t;
    }
    return f1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    while (cin >> n >> m) {
        if (n < 2) {
        //n=1,n=0时不递归，直接得到答案
            cout << 0 << endl;
        } else {
            //m=0时与m=2的答案相同
            if (m == 0) m = 2;
            //输出
            cout << fib(n-m+1) << endl;
        }
    }
    return 0;
}
