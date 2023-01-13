class MinStack {
public:
    
    vector < pair<int,int> > container;
    int topPtr;
    int minval;
    MinStack() {
        topPtr = -1;
        minval = INT_MAX;
    }
    
    void push(int val) {
        minval = min(minval, val);
        container.push_back(make_pair(val, minval));
        topPtr++;
        return;
    }
    
    void pop() {
        container.pop_back();
        topPtr--;
        if(topPtr>= 0)
            minval = container[topPtr].second;
        else
            minval = INT_MAX;
        return;
    }
    
    int top() {
        return container[topPtr].first;
    }
    
    int getMin() {
        return container[topPtr].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */