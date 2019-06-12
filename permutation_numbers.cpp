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

#define LEN 4

/* Function to swap values at two pointers */
void swap(int *x, int *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  
/*
Starting from the number 1 2 3 4 this is how each sub branch will look. Have split it into multiple
sub branches for illustration sake
sub branch 1:
                                     1 2 3 4

                            1 2 3 4                 

        1 2 3 4           1 3 2 4             1 4 3 2

 1 2 3 4    1 2 4 3    1 3 2 4   1 3 4 2   1 4 3 2   1 4 2 3 
     

sub branch 2:
                                    1 2 3 4

                               2 1 3 4                 

        2 1 3 4              2 3 1 4             2 4 3 1

  2 1 3 4    2 1 4 3    2 3 1 4   2 3 4 1   2 4 3 1   2 4 1 3 

  sub branch 3:
                                    1 2 3 4

                           3 2 1 4                 

        3 2 1 4          3 1 2 4             3 4 1 2

  3 2 1 4    3 2 4 1   3 1 2 4   3 1 4 2   3 4 1 2   3 4 2 1 

  sub branch 4:
                                    1 2 3 4

                    4 2 3 1                 

        4 2 3 1          4 3 2 1             4 1 3 2

  4 2 3 1    4 2 1 3   4 3 2 1   4 3 1 2   4 1 3 2   4 1 2 3 


*/

void permutation(int *a, int l, int r)  
{  
    int i;  
    if (l == r)  
    {
        for (i = 0; i < LEN; i++)
            cout << a[i] << " ";  
        cout << endl;
    }
    else
    {  
        for (i = l; i <= r; i++)  
        {  
            swap((a+l), (a+i));  
            permutation(a, l+1, r);  
            swap((a+l), (a+i)); //backtrack  
        }  
    }  
}  

/* Driver program to test above functions */
int main()  
{  
    int str[] = {1,2,3,4};  
    int n = LEN;  
    permutation(str, 0, n-1);  
    return 0;  
}  