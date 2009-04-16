#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    int r;
    while (r = a % b, r != 0) {
        a = b, b = r;
    }
    return b;
}



void encrypt() {
    freopen("in.txt", "r", stdin);
    //Defination.
    int n;
    int m, ra, rb;
    int ga, gb;

    while (scanf("%d", &n) != EOF) {
        time_t sta_time = clock();

        ga = 0;
        gb = 0;
        //Input with calculate.
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &m, &ra, &rb);
            ga = gcd(m - ra, ga);
            gb = gcd(m - rb, gb);
        }
        //Output.
        if (ga == 0 || gb == 0) printf("I don't know!\n");
        else cout << (long long)ga * gb / gcd(ga, gb) <<endl;

        time_t end_time = clock();
        //printf(":%.3lf\n", (float)(end_time - sta_time) / 1000);
    }
}

int main() {
    encrypt();
//    int a, b;
//    cin >> a >> b;
//    cout << gcd(a, b) << endl;
    return 0;
}
