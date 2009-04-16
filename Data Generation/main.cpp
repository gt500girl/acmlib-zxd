#include <iostream>

using namespace std;



int main()
{
    int A, B, M, NUM;
    scanf("%d %d %d", &A, &B, &NUM);
    M = A * B;
    srand((unsigned)time(NULL));
    freopen("in.txt", "w", stdout);
    printf("%d\n", NUM);
    for (int i = 0; i < NUM; i++) {
        int m = rand() * rand() % M;
        printf("%d %d %d\n", m, m % A, m % B);
    }
    return 0;
}
