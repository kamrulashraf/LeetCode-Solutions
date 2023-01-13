class MedianFinder {
public:
    vector<int> container;
    MedianFinder() {
    }
    
    void addNum(int num) {
        container.push_back(num);
        
        int sz = container.size() - 1;
        while(sz - 1 >= 0 && container[sz-1] > container[sz]){
            swap(container[sz], container[sz-1]);
            sz--;
        }
    }

    void addNum1(int num) {
        if(container.empty()){
            container.push_back(num);
        }
        else{
            container.insert(lower_bound(container.begin(), container.end(), num), num);
        }
    }
    
    double findMedian() {
        int sz = container.size();
        if(sz&1){
            return container[sz/2];
        }
        else{
            return ((double) container[sz/2] + (double) container[sz/2-1])/2.0;
        }
    }
};


class MedianFinder {
public:
    priority_queue <int> p;
    priority_queue < int, vector<int>, greater<int> > q;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(p.empty()){
            p.push(num);
        }
        else if(p.top() >= num){
            p.push(num);
        }
        else{
            q.push(num);
        }
        
        int sz = p.size() + q.size();
        if(sz&1){
            if(p.size() <= q.size()){
                p.push(q.top());
                q.pop();
            }
            else if(p.size() - q.size() > 1){
                q.push(p.top());
                p.pop();
            }
        }
        else if(p.size() != q.size()){
            if(p.size() < q.size()){
                p.push(q.top());
                q.pop();
            }
            else{
                q.push(p.top());
                p.pop();
            }
        }
    }
    
    double findMedian() {
        int sz = q.size() + p.size();
        
        if(sz&1){
            return p.top();
        }
        else{
            return (p.top() + q.top())/ 2.0;
        }
    }
};

class MedianFinder {
public:
    priority_queue <int> p;
    priority_queue < int, vector<int>, greater<int> > q;
    MedianFinder() {
    }
    
    void addNum(int num) {
        p.push(num);
        q.push(p.top());
        p.pop();
        
        if(p.size() < (p.size()+q.size()+1)/2){
            p.push(q.top());
            q.pop();
        }
        
    }
    
    double findMedian() {
        int sz = q.size() + p.size();
        
        if(sz&1){
            return p.top();
        }
        else{
            return (p.top() + q.top())/ 2.0;
        }
    }
    
};


class MedianFinder {
public:
    multiset<int> store;
    multiset<int> :: iterator it;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int sz = store.size();
        store.insert(num);
        if(store.size() == 1){
            it = store.begin();
        }
        else{
            int sz = store.size()&1;
            if(sz && num >= *it){
                it++;
            }
            
            if(!sz && num < *it){
                it--;
            }
        }
    }
    
    double findMedian() {
        
        int sz = store.size();
        
        if(sz&1)
            return *it;
        else {
            multiset<int> :: iterator temp;
            temp = it;
            temp ++;
            return (*it + *temp)/2.0;
        }
    }
    
};