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

int main(int argc, char** argv)
{
    int x = 0xaabbccdd;

    // unsigned char 
    unsigned char y = (unsigned char)x;
    unsigned char z = 0xdd;

    if (y == 0xdd)
        cout << "Little Endian";
    else if (y == 0xaa)
        cout << "Big Endian";

    return 0;
}
