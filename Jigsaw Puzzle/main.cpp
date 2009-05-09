#include <iostream>

using namespace std;

//ʹ��string���ʹ洢����״̬
typedef char Jigsaw[10];

//��ʼ״̬
const Jigsaw st_state = "012345678";
//0-8�Ľ׳ˣ����洢���ӿ����
const int fac[9][9] = {0,0,0,0,0,0,0,0,0,
    0, 1, 2, 6, 24, 120, 720, 5040, 40320,
    0, 2, 4, 12, 48, 240, 1440, 10080, 80640,
    0, 3, 6, 18, };


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


typedef struct Jigsaw_Que {
    Jigsaw jigsaw;
    int step;
};
Jigsaw_Que state_que[362880];

int state_hash[362880];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    //��ʼ����ϣ��
    memset(state_hash, -1, sizeof(state_hash));
    state_hash[0] = 0;

    //��ʼ������
    strcpy(state_que[0].jigsaw, st_state);
    int front = 0;
    int tail = 1;

    //��������ǰ�ȴ��Hash��
    while (tail - front != 0) {
        //ȡ����ͷ��״̬
        Jigsaw & cur_state = state_que[front].jigsaw;
        int step = state_que[front].step;
        front++;

        //������1
        step++;
        //���ĸ�����ǰ��
        for (int k = 0; k < 4; k++) {
            Jigsaw new_state;
            strcpy(new_state, cur_state);
            //�ж�ǰ���Ƿ�ɹ�
            if (ch_state(new_state, k)) {
                //������״̬��Hash��
                int code = hashcode(new_state);
                //�ж���״̬�Ƿ���ֹ�
                if (state_hash[code] < 0) {
                    //����״̬�״γ��֣��������Hash�����������
                    state_hash[code] = step;
                    strcpy(state_que[tail].jigsaw, new_state);
                    state_que[tail].step = step;
                    tail++;
                }
            }
        }
    }

    //��ʱ����������ַ����飬����scanf���룬�ӿ��ٶ�
    Jigsaw fi_state;
    //�������벢��Hash���в���ֵ�������
    while (scanf("%s", &fi_state) != EOF) {
        int code = hashcode(fi_state);
        //printf("%d\n", code);
        int step = state_hash[code];
        if (step < 0) printf("NO\n");
        else printf("%d\n", step);
    }
    return 0;
}
