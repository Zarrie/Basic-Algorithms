#include <stdio.h>
#include <vector>

#define MAX 27

using std::vector;

vector<vector<int>> adj_list(MAX);

void init();

unsigned pred[MAX];
bool visited[MAX] = {0};

bool cycle(unsigned i){
    unsigned count;
    for (count = 0 ; count < adj_list[i].size() ; ++i){
        if (visited[adj_list[i][count]] != 0 && adj_list[i][count] != pred[i]){
            return true;
        }
    }
    return false;
}

bool cycle_ = false;

void DFS(unsigned node){
    visited[node] = 1;
    for (unsigned i = 0 ; i < adj_list[node].size() ; ++i){
        if(visited[adj_list[node][i]] == 0){
            pred[adj_list[node][i]] = node;
            if (cycle(node)){
                cycle_ = true;
                return;
            }
            DFS(adj_list[node][i]);
        }
    }
    return;
}


int main()
{
    init();
    DFS(24);
    if (cycle_){
        printf("There is cycle!\n");
    }
    else {
        printf("There is not cycle!\n");
    }

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
    adj_list[25] = {24,26};
    adj_list[26] = {24,25};

    for (unsigned i = 0 ; i < MAX ; ++i){
        pred[i] = -1;
    }
}
