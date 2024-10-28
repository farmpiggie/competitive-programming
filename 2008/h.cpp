/*
how to solve prob for a given query q?
  
all a_i -> (a_i % x)
sort these values, pick median (0 indexed, value is at a[n / 2])
 
how can we quickly find (a_i % x) for all x in q?
 
note that a_i <= n <= 1e5, so maybe we can do something with the factors of these #s?
upper bound on factors(a_i) <= 50
 
given y | x, (y divides x)
if a % x == z < y,
then a % y == z.
otherwise, if a % x == z > y, then a % y == z % y
 
if a % b == x and a % c == y, we can find a % (b * c) using CRT
but is this even useful LOL

 
 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
