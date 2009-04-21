#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

pair<int, int> encode_state(string state, char jigsaw[3][3]) {
    int i0, j0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jigsaw[i][j] = state[i * 3 + j];
            if (jigsaw[i][j] == '0') {
                i0 = i; j0 = j;
            }
        }
    }
    return make_pair(i0, j0);
}

string code_state(char jigsaw[3][3]) {
    string state;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state.push_back(jigsaw[i][j]);
        }
    }
    //cout << '\t' << state << endl;
    return state;
}

string ch_state(string state, int ch) {
    char jigsaw[3][3];
    pair<int, int> coodr = encode_state(state, jigsaw);
    char t;
    bool flag = false;
    switch (ch) {
        case 0:
            if (coodr.second > 0) {
                t = jigsaw[coodr.first][coodr.second];
                jigsaw[coodr.first][coodr.second] = jigsaw[coodr.first][coodr.second-1];
                jigsaw[coodr.first][coodr.second-1] = t;
                flag = true;
            }
            break;
        case 1:
            if (coodr.first < 2) {
                t = jigsaw[coodr.first][coodr.second];
                jigsaw[coodr.first][coodr.second] = jigsaw[coodr.first+1][coodr.second];
                jigsaw[coodr.first+1][coodr.second] = t;
                flag = true;
            }
            break;
        case 2:
            if (coodr.second < 2) {
                t = jigsaw[coodr.first][coodr.second];
                jigsaw[coodr.first][coodr.second] = jigsaw[coodr.first][coodr.second+1];
                jigsaw[coodr.first][coodr.second+1] = t;
                flag = true;
            }
            break;
        case 3:
            if (coodr.first > 0) {
                t = jigsaw[coodr.first][coodr.second];
                jigsaw[coodr.first][coodr.second] = jigsaw[coodr.first-1][coodr.second];
                jigsaw[coodr.first-1][coodr.second] = t;
                flag = true;
            }
            break;
    }
    if (flag) return code_state(jigsaw);
    else return state;
}

int chg_int(string str) {
    int r = 0;
    for (int i = 0; i < str.size(); i++) {
        r *= 10;
        r += (char)str[i]-48;
    }
}

set<string> state_hash[1000000];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    const string st_state = "012345678";
    char tmp_str[10];
    string fi_state;

    while (scanf("%s", &tmp_str) != EOF) {
        //printf("%s\n", tmp_str);
        fi_state = tmp_str;
        set<string> state_set;
        queue<string> state_que;
        //state_set.insert(st_state);
        state_hash[12345].insert("678");
        state_que.push(st_state);
        int step = 0;
        for (int i = 0; i < 1000000; i++) state_hash[i].clear();
        while (state_que.size() != 0) {
            string cur_state = state_que.front();
            //cout << cur_state << '-' << fi_state << endl;
            if (cur_state == fi_state) break;
            state_que.pop();
            for (int k = 0; k < 4; k++) {
                string new_state = ch_state(cur_state, k);
                if (new_state != cur_state) {
                    if (state_hash[chg_int(new_state.substr(0, 6))].insert(new_state.substr(6, 3)).second) {
                        state_que.push(new_state);
                    }
                }
            }
            //cout << state_que.size() << endl;
            step++;
        }
        if (state_que.size() == 0) printf("NO\n");
        else printf("%d\n", step);
    }
    return 0;
}
