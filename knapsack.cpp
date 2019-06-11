/*
 * Copyright 2019
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Gnanasekar Rajakumar (gnanasekar.r29@gmail.com)
 */

#include <iostream>

using namespace std;


/*
Not explaining the Knapsack problem here. Certainly google can help :)

There are certain key steps that needs to be well visualized to understand the implementation better.
1) create a table of all capacities(upto max given) and see what happens to value when you include the 
   item and what happens when you do not include the item. This is the key. Based on that take a decision and update the
   value corresponding to the weight.

2) In the following case you iterate through item by item and update the value against the weight. 
   a) Choose item if weight is less than current weight in the iteration - In that case,
     value = max(val(current) + val(for remaining weight calculated earlier) , val(previous weight))
      i.e.,  max(val[i] + table[prev][w - weight[i]], table[prev][w])

   b) If weight is greater than current iteration then just carry forward prev calculated value

             w ->
i val weight 0  1  2  3  4  5  6  7  8  9 
 -----------------------------------------
0 (10) 2     0  0  10 10 10 10 10 10 10 10
1 (8) 2      0  0  10 10 18 18 18 18 18 18
2 (2) 4      0  0  10 10 18 18 18 18 20 20
3 (11) 9     0  0  10 10 18 18 18 18 20 20

*/

int knapSack(int capacity, int weight[], int val[], int n)
{
    int i, w, prev;
    int **KS_Table = (int**)malloc(sizeof(int*) * (n));
    for (i = 0; i < n; i++)
        KS_Table[i] = (int*)malloc(sizeof(int*) * (capacity));



    for (i = 0; i < n; i++)
    {
        prev = i-1;
        for (w = 0; w <= capacity; w++)
        {
            if (w == 0)
                KS_Table[i][w] = 0;
            else if (i == 0)
            {
                if (weight[i] <= w)
                    KS_Table[i][w] = val[i];
                else
                    KS_Table[i][w] = 0;
            }
            else if (weight[i] <= w)
                KS_Table[i][w] = max(val[i] + KS_Table[prev][w - weight[i]], KS_Table[prev][w]);
            else
                KS_Table[i][w] = KS_Table[prev][w];
        }
    }

    return KS_Table[n-1][capacity];
}

int main()
{
    int val[5] = {10, 8, 2, 11};
    int weight[5] = {2, 2, 4, 9};
 
    int capacity = 9;
    int optimumval = knapSack(capacity, weight, val, 4);
    cout << "Optimum val " << optimumval << endl;

    int val1[5] = {1, 8, 2, 11};
    int weight1[5] = {10, 2, 4, 9};
    optimumval = knapSack(capacity, weight1, val1, 4);
    cout << "Optimum val " << optimumval << endl;

    int val2[5] = {1, 8, 2, 3};
    int weight2[5] = {10, 2, 4, 9};
    optimumval = knapSack(capacity, weight2, val2, 4);
    cout << "Optimum val " << optimumval << endl;

    return 0;
}