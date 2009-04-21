/**
1.�������в����������ص�Dijkstra�㷨�������ڽӾ��󱣴�ͼ��û��ʹ�öѣ��������ڽӱ�ʹ����С�ѿ��ܸĽ�ʱ�����ģ�
2.�㷨�м�¼�˵ڶ���·��·���������������ע����ȥ��
*/

#include <iostream>

using namespace std;


//Dijkstra�㷨
void dij(int graph[1000][1000], int dis[1000], int path[1000], int order[1000], int size) {
    int minNode, minVal;
    bool caled[1000] = {false};
    dis[0] = 0;
    path[0] = 99999999;
    order[0] = 0;
    int i, j;
    for (i = 0; i < size; i++) {
        minVal = 99999999;
        for (j = 0; j < size; j++) {
            if (!caled[j] && dis[j] < minVal) {
                minVal = dis[j];
                minNode = j;
            }
        }
        caled[minNode] = true;
        order[i] = minNode;
        for (j = 0; j < size; j++) {
            if (dis[minNode] + graph[minNode][j] < dis[j]) {
                dis[j] = dis[minNode] + graph[minNode][j];
                path[j] = minNode;
            }
        }
    }
}

//����Dijkstra�㷨�еĵڶ���ѡ·��
void sed_dij(int graph[1000][1000], int dis[1000], int sed[1000], int path[1000], int sedpath[1000], int size) {
    for (int i = 0; i < size; i++) {
        int sed_val = 99999999;
        sedpath[i] = 99999999;
        for (int j = 0; j < size; j++) {
            if (j != path[i] && dis[j] + graph[j][i] < sed_val) {
                sed_val = dis[j] + graph[j][i];
                sedpath[i] = j;
            }
        }
        sed[i] = sed_val;
    }
}

//����ڶ���·��
void cal_sed(int graph[1000][1000], int dis[1000], int seddij[1000], int sedlen[1000], int path[1000], bool sedcho[1000], int order[1000], int size) {
    sedlen[0] = seddij[0];

    for (int i = 1; i < size; i++) {
        if (seddij[order[i]] < sedlen[path[order[i]]] + graph[path[order[i]]][order[i]]) {
            sedlen[order[i]] = seddij[order[i]];
        } else {
            sedlen[order[i]] = sedlen[path[order[i]]] + graph[path[order[i]]][order[i]];
            sedcho[order[i]] = true;
            //sedpath[order[i]] = path[order[i]];
        }
    }
}


//�ڽӾ��󱣴�ͼ
int graph_mat[1000][1000];

int main() {
    //File Input
    //freopen("data1.in", "r", stdin);

    //������
    int m;
    while (scanf("%d", &m) != EOF) {
        //��ʼ��
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                graph_mat[i][j] = 99999999;
        //����
        for (int i = 0; i < m; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int a, w;
                scanf("%d %d", &a, &w);
                graph_mat[i][a-1] = w;
            }
        }
        //�������·����
        int dis[1000];
        for (int i = 0; i < m; i++) dis[i] = 99999999;
        //�������··��
        int path[1000];
        //����Dijkstra�㷨�����ÿ�����˳��
        int order[1000];

        dij(graph_mat, dis, path, order, m);

        //����Dijkstra�еڶ���ѡ��̾�
        int seddij[1000];
        //����ڶ����·����
        int sedlen[1000];
        //����ڶ����··��
        int sedpath[1000];

        sed_dij(graph_mat, dis, seddij, path, sedpath, m);

        //����ڶ����·���ϵ�ѡ��
        bool sedcho[1000]={false};

        cal_sed(graph_mat, dis, seddij, sedlen, path, sedcho, order, m);

        //���
        printf("%d\n", sedlen[m-1]);
/* ���²���Ϊ��������ڶ���·�� */
//        int j = m-1;
//        while (j != 0) {
//            printf("%d->", j+1);
//            if (sedcho[j]) {
//                j = path[j];
//            }
//            else {
//                j = sedpath[j];
//                break;
//            }
//        }
//        while (j != 0) {
//            printf("%d->", j+1);
//            j = path[j];
//        }
//        printf("1\n");
    }
    return 0;
}



