/**
1.本代码中采用了最朴素的Dijkstra算法，并且邻接矩阵保存图，没有使用堆，若改用邻接表并使用最小堆可能改进时空消耗；
2.算法中记录了第二短路的路径，但输出部分用注释隐去。
*/

#include <iostream>

using namespace std;


//Dijkstra算法
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

//计算Dijkstra算法中的第二候选路径
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

//计算第二短路径
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


//邻接矩阵保存图
int graph_mat[1000][1000];

int main() {
    //File Input
    //freopen("data1.in", "r", stdin);

    //顶点数
    int m;
    while (scanf("%d", &m) != EOF) {
        //初始化
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                graph_mat[i][j] = 99999999;
        //输入
        for (int i = 0; i < m; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int a, w;
                scanf("%d %d", &a, &w);
                graph_mat[i][a-1] = w;
            }
        }
        //保存最短路长度
        int dis[1000];
        for (int i = 0; i < m; i++) dis[i] = 99999999;
        //保存最短路路径
        int path[1000];
        //保存Dijkstra算法中求解每个点的顺序
        int order[1000];

        dij(graph_mat, dis, path, order, m);

        //保存Dijkstra中第二候选最短径
        int seddij[1000];
        //保存第二最短路长度
        int sedlen[1000];
        //保存第二最短路路径
        int sedpath[1000];

        sed_dij(graph_mat, dis, seddij, path, sedpath, m);

        //保存第二最短路径上的选择
        bool sedcho[1000]={false};

        cal_sed(graph_mat, dis, seddij, sedlen, path, sedcho, order, m);

        //输出
        printf("%d\n", sedlen[m-1]);
/* 以下部分为反向输出第二短路径 */
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



