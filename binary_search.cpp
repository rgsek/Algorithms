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

// Run the recursion till start and end are same
// 1. If key found in middle return index
// 2. If key is less than a[mid] then search from start
//    to mid-1
// 3. If key is greater than a[mid] then search from mid+1
//    to end
int binsearch(int* a, int start, int end, int key)
{
    if (end >=  start)
    {
        int mid = (start + end)/2;
        if (key < a[mid])
            return binsearch(a, start, mid-1, key);
        else if(key > a[mid])
            return binsearch(a, mid+1, end, key);
        else if(key == a[mid])
            return mid;

        return -1;
    }

    return -1;
}

// Initialize an array with some elements and return the index of key
// receiveid from user. If no key then return -1
int main(int argc, char** argv)
{
    int a[10] = {1, 23, 45, 67, 89, 99, 100, 234, 456, 567};
    int size = sizeof(a)/sizeof(a[0]);
    int key;
    cin >> key;
    int found = binsearch(a, 0, size-1, key);
    cout << "found = " << found << endl;

    return 0;
} 
