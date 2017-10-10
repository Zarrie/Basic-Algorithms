#include <stdio.h>
#include <vector>

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
bool visited[MAX] = {0};

vector<int> path;

void print_path()
{
    for(int i = 0 ; i < path.size() ; ++i)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

//testing how many calls of DFA(i) are there
unsigned int totals = 0;

void DFS(unsigned int i, unsigned int j)
{
    ++totals;
    path.push_back(i);
    if (i == j){
        print_path();
        return;
    }
    visited[i] = 1;
    for(int k = 0 ; k < adj_list[i].size() ; ++k)
    {
        if(visited[adj_list[i][k]] == 0)
        {
            DFS(adj_list[i][k], j);
            path.pop_back();
        }
    }
    visited[i] = 0;
}

int main()
{
    init();
    DFS(0,2);

    printf("%d", totals);

    return 0;
}
