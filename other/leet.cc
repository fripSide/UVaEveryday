#include <cstdio>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        printf("%d %d search\n", l, r);
        if (nums[m] < target) {
            if (nums[m] < nums[l]) {
                if (nums[r] > target) {
                    l = m + 1;
                } else r = m - 1;
            } else if (nums[m] >= nums[l]) {
                l = m + 1;
            }
        } else if (nums[m] > target) {
            if (nums[m] > nums[l]) {
                if (target > nums[l]) r = m - 1;
                else l = m + 1;
            } else if (nums[m] <= nums[l]) {
                r = m - 1;
            }
        } else return m;
    }
    return -1;
}

int main() {
    vector<int> vv = {3, 1};
    printf("%d\n", search(vv, 1));
    return 0;
}
