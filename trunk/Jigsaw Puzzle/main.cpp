#include <iostream>
#include <queue>
#include <string>

using namespace std;

//使用string类型存储方格状态
typedef string Jigsaw;

//初始状态
const Jigsaw st_state = "012345678";
//0-8的阶乘，打表存储，加快计算
const int fac[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};

//将状态依参数沿四个方向扩展
bool ch_state(Jigsaw& jigsaw, int ch) {

    int i0;
    for (i0 = 0; i0 < 9; i0++)
        if (jigsaw[i0] == '0') break;

    bool flag = false;
    switch (ch) {
        case 0:
            if (i0 - 3 >= 0) {
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

//根据数字串在排列中的序号进行Hash编码
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
    //初始化哈希表
    memset(state_hash, -1, sizeof(state_hash));
    state_hash[0] = 0;

    //初始化队列
    queue<pair<Jigsaw, int> > state_que;
    state_que.push(make_pair(st_state, 0));

    //接受输入前先打好Hash表
    while (state_que.size() != 0) {
        //取出队头的状态
        Jigsaw cur_state = state_que.front().first;
        int step = state_que.front().second;
        state_que.pop();

        //步数加1
        step++;
        //沿四个方向前进
        for (int k = 0; k < 4; k++) {
            Jigsaw new_state = cur_state;
            //判断前进是否成功
            if (ch_state(new_state, k)) {
                //计算新状态的Hash码
                int code = hashcode(new_state);
                //判断新状态是否出现过
                if (state_hash[code] < 0) {
                    //若新状态首次出现，则将其记入Hash表，并加入队列
                    state_hash[code] = step;
                    state_que.push(make_pair(new_state, step));
                }
            }
        }
    }

    Jigsaw fi_state;
    char tmp_str[10];
    //接受输入并从Hash表中查找值返回输出
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
