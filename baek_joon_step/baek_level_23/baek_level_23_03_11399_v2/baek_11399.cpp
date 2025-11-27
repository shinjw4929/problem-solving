//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int N = 1000;
   cin >> N;
   vector<int> arr(N);
   for (auto & iter :arr) {
      cin >> iter;
   }
   sort(arr.begin(), arr.end());
   for (int i = 1 ; i < N ; i++) {
      arr[i] += arr[i - 1];
   }
   cout << accumulate(arr.begin(), arr.end(), 0);
   return 0;
}