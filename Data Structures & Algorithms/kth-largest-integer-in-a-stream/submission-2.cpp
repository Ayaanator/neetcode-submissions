class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mh;
    int n;

    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto x : nums) {
            mh.push(x);
            if(mh.size() > n) {
                mh.pop();
            }
        }
    }
    
    int add(int val) {
        mh.push(val);
        if(mh.size() > n) {
            mh.pop();
        }
        return mh.top();
    }
};
