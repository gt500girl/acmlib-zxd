#include <iostream>

using namespace std;

const int A = 10000;
const int B = 10001;
const int M = A * B;
const int NUM = 1000000;

int main()
{
    srand((unsigned)time(NULL));
    freopen("in.txt", "w", stdout);
    cout << NUM << endl;
    for (int i = 0; i < NUM; i++) {
        int m = rand() % (M-A) + A;
        printf("%d %d %d\n", m, m % A, m % B);
    }
    return 0;
}
