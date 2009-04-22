#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

typedef string Jigsaw;

const Jigsaw st_state = "012345678";
const int fac[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};

bool ch_state(Jigsaw& jigsaw, int ch) {

    int i0;
    for (i0 = 0; i0 < 9; i0++)
        if (jigsaw[i0] == '0') break;

    bool flag = false;
    switch (ch) {
        case 0:
            if (i0 - 3 > 0) {
                jigsaw[i0] = jigsaw[i0-3];
                jigsaw[i0-3] = '0';
                flag = true;
            }
            break;
        case 1:
            if (i0 % 3 < 2) {
                jigsaw[i0] = jigsaw[i0+1];
                jigsaw[i0+1] = '0';
                flag = true;
            }
            break;
        case 2:
            if (i0 + 3 < 9) {
                jigsaw[i0] = jigsaw[i0+3];
                jigsaw[i0+3] = '0';
                flag = true;
            }
            break;
        case 3:
            if (i0 % 3 > 0) {
                jigsaw[i0] = jigsaw[i0-1];
                jigsaw[i0-1] = '0';
                flag = true;
            }
            break;
    }
    return flag;
}

int hashcode(Jigsaw jigsaw) {
    bool app_flag[9] = {false};
    int i, j;
    int code = 0;
    for (i = 0; i < 8; i++) {
        j = jigsaw[i] - 48;
        app_flag[j--] = true;
        int k = 0;
        for (; j >= 0; j--) {
            if (!app_flag[j]) k++;
        }
        code += k * fac[8-i];
    }
    return code;
}

int state_hash[362880];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(state_hash, -1, sizeof(state_hash));

    queue<pair<Jigsaw, int> > state_que;
    state_hash[0] = 0;
    state_que.push(make_pair(st_state, 0));

    while (state_que.size() != 0) {
        Jigsaw cur_state = state_que.front().first;
        int step = state_que.front().second;
        state_que.pop();
        step++;
        for (int k = 0; k < 4; k++) {
            Jigsaw new_state = cur_state;
            if (ch_state(new_state, k)) {
                int code = hashcode(new_state);

                if (state_hash[code] < 0) {
                    //cout << cur_state << "->" << new_state << ':' << step << endl;
                    state_hash[code] = step;
                    state_que.push(make_pair(new_state, step));
                }
            }
        }
        //if (step > 6) break;
    }

    Jigsaw fi_state;
    char tmp_str[10];
    while (scanf("%s", &tmp_str) != EOF) {
        fi_state = tmp_str;
        int code = hashcode(fi_state);
        //printf("%d\n", code);
        int step = state_hash[code];
        if (step < 0) printf("NO\n");
        else printf("%d\n", step);
    }
    return 0;
}
