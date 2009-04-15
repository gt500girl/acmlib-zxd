#include <iostream>

using namespace std;

const int A = 100000000;
const int B = 99999999;
const int M = A * B;
const int NUM = 100000;

int main()
{
    srand((unsigned)time(NULL));
    freopen("in.txt", "w", stdout);
    printf("%d\n", NUM);
    for (int i = 0; i < NUM; i++) {
        long long m = rand()*rand() % M;
        printf("%lld %lld %lld\n", m, m % A, m % B);
    }
    return 0;
}
