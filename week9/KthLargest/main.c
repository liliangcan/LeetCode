class KthLargest {
public:
    // vector<int> v;           //超时
    // int k;
    // KthLargest(int k, vector<int>& nums) {
    //     this->k = k;
    //     for(int i = 0; i < nums.size(); i++){
    //         add(nums[i]);
    //     }

    // }
    // int add(int val) {
    //     if(v.size() < k || val > v[0]){      //加了一些判断都超时
    //         v.push_back(val);
    //         sort(v.begin(),v.end());
    //         if(v.size() > k){
    //             v.erase(v.begin());
    //         }
    //         return v[0];
    //     }else{
    //         return v[0];
    //     }
    // }

    //使用优先队列
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& x: nums) {
            add(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
