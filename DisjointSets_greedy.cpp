#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

const int INF = 10000000;

int take_time(vector <int> t, int i)
{
    for (int j = 0 ; j < t.size() ; j++){
        if (t[j] >= i){
            return t[j];
        }
    }
    return INF;
}


class Boxing
{
public:
    	int maxCredit(vector<int> a,vector<int> b,vector<int> c,vector<int> d,vector<int> e){
            int count = 0;
            for (int i = 0 ; i < 180000 ; ++i){
                int bs[5];
                bs[0] = take_time(a,i);
                bs[1] = take_time(b,i);
                bs[2] = take_time(c,i);
                bs[3] = take_time(d,i);
                bs[4] = take_time(e,i);
                sort(bs, bs + 5);
                if (i == 0){
                    for (int k = 0 ; k < 5 ; ++k){
                        printf("%d ", bs[k]);
                    }
                    printf("\n");
                }
                if (bs[2] <= i + 1000){
                    count++;
                    i = bs[2];
                }
            }
            return count;
        }
};

int main()
{
    vector<int> a,b,c,d,e;
//    a = {5990, 6985, 17723, 18784, 20958, 26433, 27925, 29068, 34574, 39404, 39961, 52385, 61619, 67571, 69079, 71683, 76016, 77748, 79929, 79942, 83772, 86008, 90871, 92029, 92895, 95040, 99406, 106093, 109832, 111714, 114326, 115461, 118375, 123873, 124070, 127204, 130167, 134872, 135251, 139682, 141782, 142837, 151104, 158085, 160856, 163874, 170734, 173038, 173124, 179615};
//    b = {12605, 13835, 16403, 18397, 18568, 19172, 19645, 23229, 25607, 31723, 32089, 32436, 33012, 42898, 44695, 55663, 60634, 64704, 65858, 66595, 67057, 67500, 69060, 69671, 70288, 75940, 79076, 79608, 94714, 114741, 118019, 123599, 130401, 131280, 136012, 138743, 141284, 142172, 148411, 149675, 150070, 152978, 153206, 157338, 157356, 159875, 162145, 163073, 173452, 174169};
//    c = {6314, 11673, 18740, 32338, 36256, 38728, 39063, 42030, 45585, 46830, 52297, 61046, 61085, 66019, 72246, 73199, 73617, 85000, 91849, 97412, 97723, 100716, 100927, 102447, 103616, 116332, 120475, 123782, 139454, 143663, 144075, 150883, 151120, 152183, 153475, 153661, 154452, 157076, 159166, 161365, 165992, 171242, 171868, 172309, 172784, 175837, 175902, 178248, 178859};
//    d = {7540, 13808, 17898, 19074, 19394, 27970, 40304, 48853, 49506, 50631, 52266, 52473, 54344, 55260, 59663, 60235, 62136, 63861, 67360, 67520, 67660, 72177, 74169, 77411, 83827, 88394, 89716, 93588, 98557, 104525, 106318, 110903, 116276, 118109, 119318, 119392, 122442, 122623, 125319, 129273, 137152, 137260, 141872, 147669, 148620, 151715, 154407, 163392, 163960, 168826};
//    e = {1307, 3302, 3646, 6741, 10217, 24069, 25045, 25617, 36166, 38588, 40843, 49777, 51433, 51524, 63389, 65744, 69457, 70002, 71456, 73600, 74296, 74620, 75943, 78866, 82864, 83867, 85497, 85517, 90879, 94100, 95914, 105759, 108018, 110401, 112565, 114407, 115743, 116012, 119734, 126263, 135184, 137207, 144413, 145286, 146748, 147420, 150406, 151795, 154445, 170406};
    a = {100,200,300,1200,6000};
    b = {};
    c = {900,902,1200,4000,5000,6001};
    d = {0,2000,6002};
    e = {1,2,3,4,5,6,7,8};

    Boxing b_1;
    int credits = b_1.maxCredit(a,b,c,d,e);
    printf("%d", credits);
    return 0;
}

/**
Problem Statement
In Olympic boxing, there are five judges who press a button when they think that a particular boxer has just landed a punch.
The times of the button presses are recorded, and the boxer receives credit for a punch if at least three of the judges
press their buttons within 1 second of each other.This "algorithm" needs a lot of refinement.
Here is the version that you should implement. Find the maximum number of disjoint time intervals that can be chosen such that
each interval is of duration 1 second or less and contains button presses from at least 3 different judges. Two intervals are
disjoint if every time within one interval is strictly less than every time in the other. We give the boxer credit for one
punch during each interval.The duration of an interval is the amount of time between the instant when it starts and when it ends,
and a punch may be included in an interval if its recorded time is at the start, end, or in between. So, for example, the interval
from 1 to 4 has duration 3, and a punch recorded at time 1, 2, 3, or 4 is in that interval. The intervals 1 to 4 and 5 to 22 are disjoint,
but the intervals 1 to 4 and 4 to 22 are not disjoint.

Create a class Boxing that contains a method maxCredit that is given five int[]s, a, b, c, d, and e, representing the times of
the button presses of the five judges in milliseconds. The method returns the maximum credits that can be given to the boxer.

Definition

Class:	Boxing
Method:	maxCredit
Parameters:	int[], int[], int[], int[], int[]
Returns:	int
Method signature:	int maxCredit(int[] a, int[] b, int[] c, int[] d, int[] e)
(be sure your method is public)

Constraints
-	Each of the five arguments will contain between 0 and 50 elements inclusive.
-	Each element of each of the arguments will be between 0 and 180,000 inclusive.
-	The elements within each of the arguments will be in strictly increasing order.

Examples
0)

{1,2,3,4,5,6}
{1,2,3,4,5,6,7}
{1,2,3,4,5,6}
{0,1,2}
{1,2,3,4,5,6,7,8}
Returns: 6
This match had a fast start, with 6 punches credited in the first 6 milliseconds of the match! One way to choose 6 disjoint intervals
is to choose [1,1], [2,2], [3,3], [4,4], [5,5], [6,6] each of which contains button presses from judges a, b, and c.
There are three button presses in the time interval from 7 through 8, but only from two different judges so no additional credit can be given.
1)

{100,200,300,1200,6000}
{}
{900,902,1200,4000,5000,6001}
{0,2000,6002}
{1,2,3,4,5,6,7,8}
Returns: 3
One way to form three intervals is [0,1000], [1001,2000], [6000,6002]
2)

{5000,6500}
{6000}
{6500}
{6000}
{0,5800,6000}
Returns: 1
Any interval that doesn't include 6000 will not have enough button presses, so we can form only one disjoint interval with credit for a punch.
*/
