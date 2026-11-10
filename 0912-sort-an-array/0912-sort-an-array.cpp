class Solution {
public:
    void merge(vector<int>& a, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        while(i <= mid && j <= r) {
            if(a[i] <= a[j])
                temp.push_back(a[i++]);
            else
                temp.push_back(a[j++]);
        }

        while(i <= mid)
            temp.push_back(a[i++]);

        while(j <= r)
            temp.push_back(a[j++]);

        for(int k = l; k <= r; k++)
            a[k] = temp[k-l];
    }

    void divide(vector<int>& a, int l, int r) {
        if(l >= r) return;

        int mid = l + (r-l)/2;

        divide(a, l, mid);
        divide(a, mid+1, r);

        merge(a, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);
        return nums;
    }
};