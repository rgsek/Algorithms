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

/* print the numbers */
void print(int a[], int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

/* Keep swapping the numbers next to each other for total count */
void print_combination(int a[], int size)
{
	int temp,count = 0;
	for (int j = 1; j <= size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			temp = a[i];
			a[i]= a[i+1];
			a[i+1] = temp;
			print(a, size);
			count++;
		}
	}
	cout << count << " done" << endl;
	return;
}

int main(int argc, char** argv)
{
	int a[] = {1,2,3,4};
	int size = sizeof(a)/sizeof(int);

	print_combination(a, size);
	return 0;
}
