#include <iostream>

using namespace std;

int josephus(int k) {
    if (k == 1) return 1;
    if (k % 2 == 0) return 2*josephus(k/2)-1;
    else return 2*josephus(k/2)+1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while (cin >> n) {
        cout << josephus(n) << endl;
    }
    return 0;
}
