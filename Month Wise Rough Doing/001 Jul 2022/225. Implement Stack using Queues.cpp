class MyStack {
public:
    queue<int> qu1;
    queue<int> qu2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(qu1.size()!=0){
            qu2.push(qu1.front());
            qu1.pop();
        }
        qu1.push(x);
        while(qu2.size()!=0){
            qu1.push(qu2.front());
            qu2.pop();
        }
    }
    
    int pop() {
        int h = qu1.front();
        qu1.pop();
        return h;
    }
    
    int top() {
        return qu1.front();
    }
    
    bool empty() {
        if(qu1.size()==0){
            return true;
        }else{
            return false;
        }
    }
};
