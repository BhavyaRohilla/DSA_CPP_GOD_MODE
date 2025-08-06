#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        if (mid > start && nums[mid + 1] == target)
            return mid + 1;
        if (mid < end && nums[mid - 1] == target)
            return mid - 1;
        if (nums[mid] > target)
            end = mid - 2;
        else
            start = mid + 2;
    }
    return -1;
}

int main()
{
    vector<int> nums = {10, 3, 40, 20, 50, 80, 70}; // nearly sorted
    int target = 40;

    int index = binarySearch(nums, target);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
