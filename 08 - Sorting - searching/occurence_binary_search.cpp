#include "../header.h"

int firstOcc(vector<int> &nums, int target)
{
    int ans = -1;
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int lastOcc(vector<int> &nums, int target)
{
    int ans = -1;
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {firstOcc(nums, target), lastOcc(nums, target)};
}

int findTotalOcc(vector<int> &nums, int target)
{
    int start = firstOcc(nums, target);
    int end = lastOcc(nums, target);
    int total = end - start + 1;
    return total;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5}; // sorted array
    int target = 2;

    vector<int> range = searchRange(nums, target);
    int total = findTotalOcc(nums, target);

    if (range[0] == -1)
        cout << "Target not found in array.\n";
    else
    {
        cout << "First Occurrence at index: " << range[0] << endl;
        cout << "Last Occurrence at index: " << range[1] << endl;
        cout << "Total Occurrences: " << total << endl;
    }

    return 0;
}
