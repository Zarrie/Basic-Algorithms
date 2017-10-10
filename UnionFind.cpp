#include <iostream>
#include <stdio.h>

/// UNION FIND DATA STRUCTURE IMPLEMENTATION
/// Author : Zarrie

class union_find                                   // representing _SET_ math structure and some usual operations for it's elements
{
private:

    unsigned int* id;                       // storing elements 1, ... ,n-1         /               id[p] is parent of p;
    unsigned int* inner_nodes;              // maintain array to count number of objects in the tree inner_nodes at i.
    size_t size_;

    unsigned int root(unsigned int p){      // returns root of node p               /               id[id[[id[...[id[p]]...]]]] is root of p
        while (p != id[p]){
            id[p] = id[id[p]];              // path compression
                                            // ( Make every other node in path point to it's
                                            // grandparent ( thereby halving path length ).
            p = id[p];
        }
        return p;
    }

public:

    union_find(size_t size){
        size_ = size;
        id = new size_t[size];
        inner_nodes = new size_t[size];

        for(int count = 0 ; count < size ; count++){        // initialize every node's parent as the node itself
            id[count] = count;
        }

        for(int count = 0 ; count < size ; count++){        // no inner nodes at initialization ( every node is root )
            inner_nodes[count] = 1;
        }
    }

    ~union_find(){ delete id; }

    void unite(unsigned int p, unsigned int q){     // unite node p and node q
        unsigned int i = root(p);
        unsigned int j = root(q);

        if(i == j) { return; }               // nodes are already connected

        if(inner_nodes[i] < inner_nodes[j]){        // if the T_with_root(p) < T_with_root(q) -> link p to q
            id[i] = j;
            inner_nodes[j] += inner_nodes[i];       // subtree with root j has inner_nodes[i] more inner_nodes after merging trees
        }
        else{                                       // if the T_with_root(p) > T_with_root(q) -> link q to p
            id[j] = i;
            inner_nodes[i] += inner_nodes[j];       // subtree with root i has inner_nodes[j] more inner_nodes after merging trees
        }
    }

    bool connected(unsigned int p, unsigned int q){
        return (root(p) == root(q));
    }

    void print(){
        for(int count = 0 ; count < size_ ; count++){
            printf("%d ", id[count]);
        }
        printf("\n");
    }

};

void test()
{
    union_find set_1(10);

    set_1.unite(1,2);
    set_1.unite(3,4);
    set_1.unite(4,5);
    set_1.unite(5,2);

    bool check = set_1.connected(2,5);

    printf("%d ", check);
}


int main()
{
    test();

    return 0;
}
