#include <stdio.h>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

/***
    ///We define a Failure Set as a set of fans which are not necessary to cool the system. In other words, if the fans in a Failure Set break,
    ///the system can still be properly cooled by the remaining fans.
    ///The count of a Failure Set is the number of fans in the set.

    ///Maximum Failure Set (MFS) = A MFS is a Failure Set of fans with the largest count possible.
    ///Maximum Failure Count (MFC) =  The MFC is the largest value such that all fan sets with count <= MFC are Failure Sets.
*/

class FanFailure
{
public:
    vector<int> getRange(vector<int> capacities, int minCooling)
    {
        vector<int> result(2);
        unsigned int MFS_c = 0;
        sort(capacities.begin(), capacities.end());
        unsigned int pos = 0;
        unsigned int sum = 0;
        unsigned int sum_2;
        unsigned int size = capacities.size();
        for (pos = 0 ; pos < size ; ++pos){
            sum += capacities[pos];
        }
        sum_2 = sum;
        pos = 0;
        while (pos < size){
            if (sum - capacities[pos] >= minCooling){
                sum -= capacities[pos];
                ++MFS_c;
            }
            ++pos;
        }
        result[0] = MFS_c;
        pos = size - 1;
        unsigned int MFC = 0;
        while (pos >= 0){
            if ((sum_2 - capacities[pos]) < minCooling){
                result[1] = MFC;
                return result;
            }
            sum_2 -= capacities[pos];
            ++MFC;
            pos -= 1;
        }
        result[1] = MFC;
        return result;
    }
};

int main()
{
    vector<int> capacities = 	{349, 735, 687, 160, 84, 478, 405, 396, 841, 479, 301, 13, 152, 246, 949, 849, 657,
    318, 264, 552, 491, 730, 259, 844, 972, 427, 340, 736, 655, 944, 935, 700,
    932, 748, 430, 767, 808, 753, 752, 30, 504, 876, 447, 793, 417};
    int minCooling = 10722;

    FanFailure f_1;
    vector<int> res = f_1.getRange(capacities,minCooling);

    printf("{ %d , %d }\n", res[0], res[1]);

    return 0;
}
/**

 Problem Statement for FanFailure


Problem Statement

In a robust computer system, one of the most important pieces is the cooling. Without proper cooling, processors can heat up to over 400 degrees C. The reliability of a system can be measured by determining how many fans can fail without risking the system processor. Each fan can be assigned a value indicating how much capacity it has to cool the system, and we can define a minimum cooling capacity, which the sum of the fan capacities must exceed to properly cool the system. We define a Failure Set as a set of fans which are not necessary to cool the system. In other words, if the fans in a Failure Set break, the system can still be properly cooled by the remaining fans. The count of a Failure Set is the number of fans in the set.

To measure the reliability, we will define two values, the Maximum Failure Set (MFS) and the Maximum Failure Count (MFC). A MFS is a Failure Set of fans with the largest count possible. A set of fans may have more than one MFS (see below). A Failure Set is an MFS if and only if there are no Failure Sets with a higher count. The MFC is the largest value such that all fan sets with count <= MFC are Failure Sets. In other words, any set of fans of size MFC or less can fail, and the system will still be properly cooled by the remaining fans.

Consider the fan set with capacities 1, 2, 3, and a cooling requirement of 2. Two MFSs with a count of 2 exist: fans 1 and 3, or fans 1 and 2. However, the MFC is not 2 because fans 2 and 3 is not a Failure set (fan 1 could not cool the system properly by itself). Thus, the MFC is 1, because if any single fan fails, the system can still be cooled.

You will be given a int[] capacities, which designates how many units of cooling each fan provides, and an int minCooling, which designates the minimum units of cooling required to cool the system. Your method should return a int[], where the first value should be the number of fans in the Maximum Failure Set (MFS), and the second value should be the Maximum Failure Count (MFC).


Definition

Class:	FanFailure
Method:	getRange
Parameters:	int[], int
Returns:	int[]
Method signature:	int[] getRange(int[] capacities, int minCooling)
(be sure your method is public)


Constraints
-	capacities has between 1 and 50 elements, inclusive.
-	each element of capacities is between 1 and 1000, inclusive.
-	minCooling is between 1 and 50000, inclusive.
-	The sum of all elements in capacities will be greater than or equal to minCooling.

Examples
0)

{1,2,3}
2
Returns: { 2,  1 }
Example from the problem statement.
1)

{8,5,6,7}
22
Returns: { 0,  0 }
No fans can fail in this system.
2)

{676, 11, 223, 413, 823, 122, 547, 187, 28}
1000
Returns: { 7,  2 }
If you eliminate fans with 676, 11, 413, 122, 547, 187, and 28, you are left with 223 + 823 = 1046 units of cooling, which is sufficient, yielding an MFS size of 7. If you eliminate 676, 823, and 547, you are left with only 984 units of cooling. All combinations of 2 or less fans breaking leaves sufficient cooling, so the MFC is 2.
3)

{955, 96, 161, 259, 642, 242, 772, 369, 311, 785,
 92, 991, 620, 394, 128, 774, 973, 94, 681, 771,
 916, 373, 523, 100, 220, 993, 472, 798, 132, 361,
 33, 362, 573, 624, 722, 520, 451, 231, 37, 921,
 408, 170, 303, 559, 866, 412, 339, 757, 822, 192}
3619
Returns: { 46,  30 }
*/
