#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 27

using std::vector;
using std::queue;

void init();

vector<vector<int>> adj_list(MAX);

unsigned int pred[MAX];             // for every node i pred[i] is ancestor of i in the BFS traversal
bool visited[MAX] = {0};

void BFS(unsigned int node){
    queue<int> curr;
    unsigned int tmp = node;

    curr.push(tmp);
    visited[tmp] = 1;

    unsigned int count;
    while (!curr.empty()){
        tmp = curr.front();
        curr.pop();
        for(count = 0 ; count < adj_list[tmp].size() ; ++count){
            if (visited[adj_list[tmp][count]] == 0){
                curr.push(adj_list[tmp][count]);
                visited[adj_list[tmp][count]] = 1;
                pred[adj_list[tmp][count]] = tmp;
            }
        }
    }
}
bool path = true;
void print(unsigned i, unsigned j){
    if (j == -1){
            path = false;
        printf("No path exists!\n");
        return;
    }
    if (i != j){
        print(i, pred[j]);
    }
    if(path){
        printf("%d ", j);
    }
}

void shortest_path(unsigned i, unsigned j){                  // find shortest path between nodes i and j
    BFS(i);
    print(i,j);
}

int main()
{
    init();
    shortest_path(0,23);

    return 0;
}


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

    // not connected with the rest of the graph G
    adj_list[24] = {25,26};
    adj_list[25] = {26};
    adj_list[26] = {};

    for (int i = 0 ; i < MAX ; ++i){
        pred[i] = -1;
    }
}
