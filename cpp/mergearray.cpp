#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            cout << total  << "\t" << i << "\t" << nums1[i] << "\t" << j << "\t" << nums2[j] << endl;
            if (nums1[i] > nums2[j]) {
                nums1[total--] = nums1[i--];
            } else {
                nums1[total--] = nums2[j--];
            }
        }

        if (j >= 0) {
            nums1[total--] = nums2[j--];
        }
    }
};

int main()
{
    vector<int> a = {1,2,4};
    vector<int> b = {1,6,10};
    Solution S;
    S.merge(a,3,b,3);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << "\t";
    }
}
