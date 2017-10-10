#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

class GroceryBagger
{
public:
    int minimumBags(int strength, vector<string> itemType)
    {
        map<string, int> it;
        size_t size = itemType.size();
        unsigned int i;
        for (i = 0 ; i < size ; ++i){
            ++it[itemType[i]];
        }

        map<string, int>::iterator itr;
        for(itr = it.begin(), i = 0 ; itr != it.end() ; ++itr){
            i += (itr->second / strength);
            if (itr->second%strength != 0) ++i;
        }
        return i;
    }

};

int main()
{
    GroceryBagger b_1;

    int strength = 11;
    vector<string> items =  {"GTIIHVQ", "GTIIHVQ", "PFPDCBOEJ", "PFPDCBOEJ", "JFRIOPWZXTAWOBPSMLNFMBQATNVWC", "GTIIHVQ", "JFRIOPWZXTAWOBPSMLNFMBQATNVWC", "GTIIHVQ", "PFPDCBOEJ", "GTIIHVQ", "GTIIHVQ", "PFPDCBOEJ", "FXOKNOCHJPFKXOXZNBTQKFBSNBHAOGYQIGFDHNL", "GTIIHVQ", "GTIIHVQ", "PFPDCBOEJ", "GTIIHVQ", "PFPDCBOEJ", "JFRIOPWZXTAWOBPSMLNFMBQATNVWC", "GTIIHVQ", "GTIIHVQ", "GTIIHVQ", "PFPDCBOEJ", "GTIIHVQ", "GTIIHVQ", "GTIIHVQ", "GTIIHVQ", "GTIIHVQ", "PFPDCBOEJ", "GTIIHVQ", "PFPDCBOEJ", "PFPDCBOEJ"};
    int x = b_1.minimumBags(strength,items);
    printf("%d ", x);

    return 0;
}

/**
Problem Statement

You have just begun working as a grocery bagger at the local TopGrocer food store. Your job is to place all of a customer's items into bags, so they can be carried from the store. Your manager has instructed you to use as few bags as possible, to minimize the store's overall cost. However, for the customer's convenience, you are instructed that only items of the same type can be placed in the same bag. For instance, a produce item can be bagged with any other produce items, but not with dairy items.

You are given a String[] itemType indicating the type of each item that needs to be bagged. You are also given an int strength indicating the maximum number of items that can be placed in each bag. You are to return an int indicating the minimum number of bags required to package the customer's items.


Definition

Class:	GroceryBagger
Method:	minimumBags
Parameters:	int, String[]
Returns:	int
Method signature:	int minimumBags(int strength, String[] itemType)
(be sure your method is public)


Constraints
-	strength will be between 1 and 50, inclusive.
-	itemType will contain between 0 and 50 elements, inclusive.
-	Each element of itemType will contain between 1 and 50 characters, inclusive.
-	Each element of itemType will contain only the characters 'A'-'Z'.

Examples
0)

2
{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}
Returns: 4
Here, you have six items. You could put two items in each bag, but you would have to mix item types. The single meat item must get its own bag. The two dairy items fit in one bag. The three produce items will require two bags.
1)

3
{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}
Returns: 3
Similar to above, but now we have stronger bags. Note again, though, that if we were allowed to mix item types, we could get away with only 2 bags. But since item types cannot be mixed, we need 3 bags.
2)

10
{}
Returns: 0
The bags are really strong, but we didn't buy anything.
3)

5
{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}
Returns: 7
Notice that a customer doesn't necessarily pay for the items in any particular order, but the bagger still has to be responsible for sorting them out. In this case, though, one bag for each item type suffices.
4)

2
{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}
Returns: 8
As above, but our produce requires two bags now.
*/
