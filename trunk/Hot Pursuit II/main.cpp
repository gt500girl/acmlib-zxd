#include <iostream>
#include <vector>

using namespace std;

void dij(vector<pair<int, int> > graph[1000], int dis[1000], int path[1000], int order[1000], int size) {
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
        for (j = 0; j < graph[minNode].size(); j++) {
            if (dis[minNode] + graph[minNode][j].second < dis[graph[minNode][j].first]) {
                dis[graph[minNode][j].first] = dis[minNode] + graph[minNode][j].second;
                path[graph[minNode][j].first] = minNode;
            }
        }
    }
}

void sed_dij(vector<pair<int, int> > graph[1000], int dis[1000], int sed[1000], int path[1000], int sedpath[1000], int size) {
    for (int i = 0; i < size; i++) {
        int sed_val = 99999999;
        sedpath[i] = 99999999;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j].first != path[i] && dis[graph[i][j].first] + graph[i][j].second < sed_val) {
                sed_val = dis[graph[i][j].first] + graph[i][j].second;
                sedpath[i] = graph[i][j].first;
            }
        }
        sed[i] = sed_val;
    }
}

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

int graph_mat[1000][1000];

int main() {
    //freopen("data1.in", "r", stdin);
    int m;
    while (scanf("%d", &m) != EOF) {
        vector<pair<int, int> > graph_pos[1000];
        vector<pair<int, int> > graph_neg[1000];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                graph_mat[i][j] = 99999999;
        for (int i = 0; i < m; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int a, w;
                scanf("%d %d", &a, &w);
                graph_pos[i].push_back(make_pair(a-1, w));
                graph_neg[a-1].push_back(make_pair(i, w));
                graph_mat[i][a-1] = w;
            }
        }
        int dis[1000];
        int path[1000];
        int order[1000];
        for (int i = 0; i < m; i++) dis[i] = 99999999;
        dij(graph_pos, dis, path, order, m);
        int seddij[1000];
        int sedlen[1000];
        int sedpath[1000];
        sed_dij(graph_neg, dis, seddij, path, sedpath, m);
        bool sedcho[1000]={false};
        cal_sed(graph_mat, dis, seddij, sedlen, path, sedcho, order, m);
        printf("%d\n", sedlen[m-1]);
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



