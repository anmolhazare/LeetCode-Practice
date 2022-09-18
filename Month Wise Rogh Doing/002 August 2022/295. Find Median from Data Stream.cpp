class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.size()==0){
            max.push(num);
            return;
        }
        
        if(max.size()>min.size()){
            if(num<max.top()){
                min.push(max.top());
                max.pop();
                max.push(num);
            }else{
                min.push(num);
            }
        }else{
            if(num<max.top()){
                max.push(num);
            }else{
                min.push(num);
                max.push(min.top());
                min.pop();
            }
        }
    }
    
    double findMedian() {
      if(max.size()==min.size()){
          return (double)(max.top()+min.top())/2.0;
      }else{
          return max.top();
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
