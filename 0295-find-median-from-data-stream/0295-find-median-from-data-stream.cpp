class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.empty() || num<maxHeap.top()){
            maxHeap.push(num);
        } else{
            minHeap.push(num);
        }
        
        if(abs((int)maxHeap.size()-(int)minHeap.size())>1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (double)(maxHeap.top()+minHeap.top())/2;
        }
        
        return maxHeap.top();
    }
};