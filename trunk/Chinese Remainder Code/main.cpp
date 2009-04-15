#include <iostream>

using namespace std;

int gcd_rec(int a, int b) {
    if (b == 0) return a;
    int r = a % b;
    return r == 0 ? b : gcd_rec(b, r);
}

int gcd_rep(int a, int b) {
    if (b == 0) return a;
    int r;
    while (r = a % b, r != 0) {
        a = b, b = r;
    }
    return b;
}



int decipher() {
    //Defination.
    int n;
    int a, b, m, ra, rb;
    int ga = 0, gb = 0;

    time_t sta_time = clock();
    //Input with calculate.
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &m, &ra, &rb);
        ga = gcd_rep(m - ra, ga);
        gb = gcd_rep(m - rb, gb);
    }
    //Output.
    printf("%d\n", ga * gb / gcd_rep(ga, gb));

    time_t end_time = clock();
    printf(":%.3lf\n", (float)(end_time - sta_time) / 1000);
}

int main()
{
    freopen("in.txt", "r", stdin);
    decipher();
    return 0;
}
