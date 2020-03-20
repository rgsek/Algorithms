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

#include <stdio.h>

#define BYTE unsigned char

int main(int argc, char** argv)
{
	BYTE pos = 0;
	BYTE pos_comp = 0;
	BYTE var = 0;
	BYTE tmp = 0;
	int i = 0;

	BYTE output[256];
	output[0] = 0;
	output[0xff] = 0xff;

	for (var = 1; var < 0xff; var++)
	{
		output[var] = var;
		for (i = 0; i < (sizeof(BYTE) * 8) /2; i++)
		{
			pos = i;
			pos_comp = (sizeof(BYTE) * 8) - i -1;

			tmp = (((var >> pos) & 0x1) << pos_comp) | (((var >> pos_comp) & 0x1) << pos);

			output[var] &= ~((1 << pos) | (1 << pos_comp));

			output[var] |= tmp;
		}

		printf("(var = 0x%x and output[var]=0x%x\n", var, output[var]);
	}
}
