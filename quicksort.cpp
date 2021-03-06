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

// Perform the following,
// 1. Pick the end element as pivot
// 2. Initialize pIndex to start of the array
// 3. Now run a for loop and compare a[i] with pivot. If it is
//    less, then swap a[i] with a[pIndex]. This is to make sure that
//    everything to the left of pIndex is less than pivot
// 4. In the end swap the pIndex with pivot(a[end]). This will ensure
//    that all the elements to the left of pIndex is lesser but not sorted.
//    But when we keep splitting the list and keep doing it till list has one
//    element then it becomes sorted.
int partition(int* a, int start, int end)
{
    int pivot = a[end];
    int pIndex = start;

    for(int i = start; i < end; i++)
    {
        if ((a[i] <= pivot))
        {
            if (i != pIndex)
                swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);

    return pIndex;
}


void quick_sort(int* a, int start, int end)
{
    // start < end is the condition to end recursion
    if (start < end)
    {
        int pIndex = partition(a, start, end);

        // call quick sort again with index 
        // 1. from start to one less than pIndex
        // 2. from one after pIndex to end
        quick_sort(a, start, pIndex-1);
        quick_sort(a, pIndex + 1, end);
    }
}


void printArray(int* A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main(int argc, char** argv)
{
    int a[] = { 38, 25, 65, 78, 3, 7, 99, 1, 65 };
    int size = sizeof(a) / sizeof(a[0]);

    // pass the array, start and end
    quick_sort(a, 0, size-1);
    printArray(a, size);
    return 0;
}
