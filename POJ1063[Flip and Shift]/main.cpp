#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int cas;
    cin >> cas;
    for (int c = 0; c < cas; c++) {
        int num;
        int one_odd = 0, one_even = 0;
        bool disk[30];

        cin >> num;

        for (int i = 0; i < num; i++) {
            cin >> disk[i];
            if (disk[i] == 1) {
                if (i % 2 == 0) one_odd++;
                else one_even++;
            }

        }
        if (num % 2 == 0 and abs(one_odd - one_even) > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
