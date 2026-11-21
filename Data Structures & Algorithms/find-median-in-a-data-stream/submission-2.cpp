class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    vector<int> nums;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mx.push(num);
        if(!mn.empty() && mn.top() < mx.top()) {
            mn.push(mx.top());
            mx.pop();
        }

        if(mx.size() > mn.size() + 1) {
            mn.push(mx.top());
            mx.pop();
        }

        if(mn.size() > mx.size() + 1) {
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if (mn.size() == mx.size()) {
            return (mn.top() + mx.top()) / 2.0;
        } else if (mn.size() > mx.size()) {
            return mn.top();
        } else {
            return mx.top();
        }
    }
};
