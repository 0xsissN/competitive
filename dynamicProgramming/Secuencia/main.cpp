#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<long long> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> DP(n+1, 0);
    DP[0] = 0;
    DP[1] = nums[0];

    long long maxSum = DP[1];

    for (int i = 1; i <= n; ++i) {
        DP[i] = max(nums[i - 1], DP[i - 1] + nums[i - 1]);
        maxSum = max(maxSum, DP[i]);
    }
    cout << maxSum << endl;
    return 0;
}
