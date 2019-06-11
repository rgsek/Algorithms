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

#if RECURSIVE
int fibonacci(int n)
{
    int f, f1, f2;
    if ( n == 1 || n == 0)
        return n;
    else
    {
        f1 = fibonacci(n-1);
        f2 = fibonacci(n-2);
        f = f1 + f2;
        return f;
    }
}
#endif

// Not really saving all values in an array. Just saving current and previous two that is needed. To truly
// exhibhit dynamic programming, the for loop can be changed to,
// F[i] = F[i-1] + F[i - 2] // where F[0] = 0 and F[1] = 1 to be initalized
int fibonacci(int num)
{
    int i = 0;
    int prev_1 = 1;
    int prev_2 = 1;
    int res = 1;
    if (num == 0)
        return 0;

    if (num == 1 || num == 2)
        return 1;

    for (i = 2; i < num; i++)
    {
        res =prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = res;
    }

    return res;
}

int main(int argc, char** argv)
{
    int num;
    int res;
    cin >> num;
    res = fibonacci(num);
    cout << "Fibonacci of " << num << "= " << res;
    return 0;
}