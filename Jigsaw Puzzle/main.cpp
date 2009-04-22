#include <iostream>
#include <queue>
#include <string>

using namespace std;

//ʹ��string���ʹ洢����״̬
typedef string Jigsaw;

//��ʼ״̬
const Jigsaw st_state = "012345678";
//0-8�Ľ׳ˣ����洢���ӿ����
const int fac[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};

//��״̬���������ĸ�������չ
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

//�������ִ��������е���Ž���Hash����
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
    //��ʼ����ϣ��
    memset(state_hash, -1, sizeof(state_hash));
    state_hash[0] = 0;

    //��ʼ������
    queue<pair<Jigsaw, int> > state_que;
    state_que.push(make_pair(st_state, 0));

    //��������ǰ�ȴ��Hash��
    while (state_que.size() != 0) {
        //ȡ����ͷ��״̬
        Jigsaw cur_state = state_que.front().first;
        int step = state_que.front().second;
        state_que.pop();

        //������1
        step++;
        //���ĸ�����ǰ��
        for (int k = 0; k < 4; k++) {
            Jigsaw new_state = cur_state;
            //�ж�ǰ���Ƿ�ɹ�
            if (ch_state(new_state, k)) {
                //������״̬��Hash��
                int code = hashcode(new_state);
                //�ж���״̬�Ƿ���ֹ�
                if (state_hash[code] < 0) {
                    //����״̬�״γ��֣��������Hash�����������
                    state_hash[code] = step;
                    state_que.push(make_pair(new_state, step));
                }
            }
        }
    }

    Jigsaw fi_state;
    char tmp_str[10];
    //�������벢��Hash���в���ֵ�������
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
