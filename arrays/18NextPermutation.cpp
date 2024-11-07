#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int index = -1;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin() + index + 1, nums.end());
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    nextPermutation(nums);

    cout << "Next permutation: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
