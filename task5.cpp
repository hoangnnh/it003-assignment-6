#include <bits/stdc++.h>
using namespace std;

int N;

int get_ans(const vector<int> &nums) {

    map<int, int> Hash;
    for (auto const &id: nums) {
        if (Hash.find(id) != Hash.end())
            Hash[id] += 1;
        else
            Hash.insert({id, 1});
    }


    int count = 0;
    for (auto const &data: Hash) {
        if (data.first != data.second) {
            int d = data.first - data.second;

            if (d > 0)
                count += data.second;
            else
                count -= d;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) cin >> nums[i];

    int count = get_ans(nums);

    cout << count;

    return 0;
}