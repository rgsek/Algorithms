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
#include <vector>

using namespace std;

void merge(int* a, std::vector<int>& left, std::vector<int>& right)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

    // compare the first unpicked element of left(which is already sorted) with
    // first unpicked of right(which is also sorted). Based on which is lesser
    // keep updating the parent list 'a'.
	while ((i < nL) && (j < nR))
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			k++;
			i++;
		}
		else
		{
			a[k] = right[j];
			k++;
			j++;
		}
	}
    // Copy the left overs to end of parent. The end list is already sorted
	while (i < nL)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < nR)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}


void merge_sort(int* a, int size)
{
    // This is the exit criteria of the recursive loop. When the
    // size goes under 2 then we have reached the last level of
    // recursion. Start sorting and merging them
	if (size < 2)
		return;

    // Find the mid point and keep splitting the list into two.
    // Copy the left side and right side to a temporary list.
    // Once we have gone to the last level of recursion we can
    // start modifying the main list because the sub lists anyways
    // contain all the elements now
	int mid = size / 2;
	std::vector<int> left;
	std::vector<int> right;

	for (int i = 0; i < mid; i++)
		left.push_back(a[i]);
	for (int i = mid; i < size; i++)
		right.push_back(a[i]);

    // call merge sort with left and right array to keep splitting them
	merge_sort(&left[0], mid);
	merge_sort(&right[0], size - mid);

    // start merging the sub lists with immediate parent
	merge(a, left, right);
}


void printArray(int* A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Lets take a global array and perform merge sort in it
int main(int argc, char** argv)
{
    int a[] = { 38, 25, 65, 78, 3, 7, 99, 1, 65 };
    int size = sizeof(a) / sizeof(a[0]);

    // pass the array and the array size
	merge_sort(a, size);
	printArray(a, size);
	return 0;
}
