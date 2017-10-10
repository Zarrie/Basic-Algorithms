#include <vector>
#include <stdio.h>

#define MAX 24

using std::vector;

/* adjacency list of the graph G */
vector<vector<int>> adj_list(MAX);

void init(){
    adj_list[0] = {1,2};
    adj_list[1] = {0,6,7};
    adj_list[2] = {0,3,4,5};
    adj_list[3] = {2,4};
    adj_list[4] = {2,3,10};
    adj_list[5] = {2,6,9,10,11};
    adj_list[6] = {1,5};
    adj_list[7] = {1,8,12};
    adj_list[8] = {7,13};
    adj_list[9] = {5,13,14};
    adj_list[10] = {4,5,14,15};
    adj_list[11] = {5,15};
    adj_list[12] = {7,16};
    adj_list[13] = {8,9,14,17,18,21};
    adj_list[14] = {9,10,13,18,19};
    adj_list[15] = {10,11,19};
    adj_list[16] = {12,20,21};
    adj_list[17] = {13,21,22};
    adj_list[18] = {13,14,22,23};
    adj_list[19] = {14,15};
    adj_list[20] = {16,21};
    adj_list[21] = {13,16,17,20,22};
    adj_list[22] = {17,18,21};
    adj_list[23] = {18};
}

/* flag visited */
unsigned int visited[MAX] = {0};

void DFS (unsigned int node){
    visited[node] = 1;
    printf("%d ", node);

    for (unsigned int i = 0 ; i < adj_list[node].size() ; ++i){
        if(visited[adj_list[node][i]] == 0){
            DFS(adj_list[node][i]);
        }
    }
}

int main()
{
    init();
    DFS(0);
    printf("\n");
    for(int i = 0; i < MAX ; ++i){
        printf("%d ", visited[i]);
    }
}
