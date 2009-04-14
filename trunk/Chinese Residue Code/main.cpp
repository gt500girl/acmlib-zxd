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

int m[1000000];
int ra[1000000];
int rb[1000000];

int decipher() {
    //Defination.
    int n;

    int a, b;
    //Input.
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &m[i], &ra[i], &rb[i]);
    }
    //Calculate.
    int sta_time = clock();

    int ga, gb;
    ga = m[0] - ra[0];
    gb = m[0] - rb[0];
    for (int i = 1; i < n; i++) {
        ga = gcd_rep(m[i] - ra[i], ga);
        gb = gcd_rep(m[i] - rb[i], gb);
        printf("\t%d %d\n", ga, gb);
    }

    int end_time = clock();
    //Output.
    cout << ga << ' ' << gb << endl;

    cout << end_time - sta_time << endl;
}

int main()
{
    freopen("in.txt", "r", stdin);
    decipher();
    return 0;
}
