#include <stdio.h>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;


class PlayGame
{
public:
    size_t saveCreatures(vector<int> you, vector<int> computer)
    {
        sort(you.begin(), you.end());
        sort(computer.begin(), computer.end());
        size_t up_bound_u = you.size() - 1;
        size_t down_bound_u = 0;
        size_t up_bound_comp = computer.size() - 1;
        size_t down_bound_comp = 0;
        size_t saved_strength = 0;

        while (up_bound_u >= down_bound_u && up_bound_comp >= down_bound_comp){
            if (you[up_bound_u] > computer[up_bound_comp]){
                saved_strength += you[up_bound_u];
                --up_bound_u;
                --up_bound_comp;
            }
            else{
                ++down_bound_u;
                --up_bound_comp;
            }
        }
        return saved_strength;
    }
};

int main()
{
    vector<int> you =
{651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849};
    vector<int> computer =
{16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82};

    PlayGame test;
    size_t test_result = test.saveCreatures(you,computer);
    printf("%d ", test_result);


    return 0;
}
/**
Problem Statement for PlayGame


Problem Statement
    	You are playing a computer game and a big fight is planned between two armies. You and your computer opponent will line up your respective units in two rows, with each of your units facing exactly one of your opponent's units and vice versa. Then, each pair of units, who face each other will fight and the stronger one will be victorious, while the weaker one will be captured. If two opposing units are equally strong, your unit will lose and be captured. You know how the computer will arrange its units, and must decide how to line up yours. You want to maximize the sum of the strengths of your units that are not captured during the battle.

You will be given a int[] you and a int[] computer that specify the strengths of the units that you and the computer have, respectively. The return value should be an int, the maximum total strength of your units that are not captured.

Definition

Class:	PlayGame
Method:	saveCreatures
Parameters:	int[], int[]
Returns:	int
Method signature:	int saveCreatures(int[] you, int[] computer)
(be sure your method is public)


Constraints
-	you and computer will have the same number of elements.
-	you and computer will contain between 1 and 50 elements, inclusive.
-	Each element of you and computer will be between 1 and 1000, inclusive.

Examples
0)

{5, 15, 100, 1, 5}
{5, 15, 100, 1, 5}
Returns: 120
Your units with strengths of 100 and 15, along with one of your strength 5 units, can avoid capture.
1)

{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
Returns: 0
All units are equally strong, so all your units are captured.
2)

{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}
{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
Returns: 99
You assign your weakest unit to the computer's strongest unit. Then you assign all your other units in such a way that each of your units has a strength one higher than the opposing unit. So all your units except the weakest one avoid capture.
3)

{2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Returns: 65
All your units can win.
4)

{651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}
{16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}
Returns: 25084

*/
