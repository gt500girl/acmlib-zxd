#include <iostream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    char str[] = "NENUACMCLUB";
    bool flag = false;
    while (cin >> n) {
        if (!flag) flag = true;
        else printf("\n");
        for (int i = 0; i < n; i++) {
            printf("%c", str[i%11]);
        }
        printf("\n");
    }
    return 0;
}
