#include <stdio.h>

int main()
{
    int cas, c;
    scanf("%d", &cas);
    for (c = 0; c < cas; c++) {
        int num, i;
        int one_odd = 0, one_even = 0;
        int disk;
        scanf("%d", &num);
        if (num % 2 == 0){
            for (i = 0; i < num; i++) {
                scanf("%d", &disk);
                if (disk == 1) {
                    if (i % 2 == 0) one_odd++;
                    else one_even++;
                }
            }
            if (abs(one_odd - one_even) > 1) printf("NO\n");
            else printf("YES\n");
        }
        else {
            for (i = 0; i < num; i++) scanf("%d", &disk);
            printf("YES\n");
        }
    }
    return 0;
}
