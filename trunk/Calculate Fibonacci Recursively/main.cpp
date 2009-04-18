#include <iostream>

using namespace std;

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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    while (cin >> n >> m) {
        if (m == 0) m = 2;
        cout << fib(n-m+1) << endl;
    }
    return 0;
}
