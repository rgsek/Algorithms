/*
 * Copyright 2020
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


#include <stdio.h>


// Sample data
// (1,3)
// (1,2)
// (1,5)
// (2,6)
// (4,10)
// (7,8)
// (13,14)
// For the above data compute the sum of overall time intervals between the samples
//

int main(int argc, char** argv)
{
	int dataset[9][2] = {{1,3}, {1,2}, {1,5}, {1,20}, {2,6}, {4,10}, {7,8}, {13,14}, {23,24}};
	int s_win, e_win = 0;
	int result = 0;
	int tot_samples = sizeof(dataset)/sizeof(dataset[0]);
	int i = 0;

	printf("size of dataset[0] : %ld\n", sizeof(dataset[0]));
	printf("size of dataset[0][0] : %ld\n", sizeof(dataset[0][0]));
	printf("----- samples:%d -----\n", tot_samples);
	s_win = dataset[0][0];
	e_win = dataset[0][1];

	for (i = 1; i < tot_samples; i++)
	{
		if (dataset[i][0] <= e_win)
		{
			if (dataset[i][1] <= e_win)
				continue;
			else
				e_win = dataset[i][1];
		}
		else if(dataset[i][0] > e_win)
		{
			result += (e_win - s_win);
			s_win = dataset[i][0];
			e_win = dataset[i][1];
		}

		printf("(%d,%d)\n", dataset[i][0], dataset[i][1]);
	}
	result += (e_win - s_win);

	printf("result:%d\n", result);
	return 0;
}
