class MinStack {
public:
    vector<pair<int,int>> v;
    int val;
    int mn;
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        pair<int,int> pr;
        mn =  min(mn,val);
        pr.first = val;
        pr.second = mn;
        v.push_back(pr);
    }
    
    void pop() {
        if(!v.size()){
            cout<<"invalid"<<'\n';
        }
        else{
            v.pop_back();
            if(v.size()){
                mn = v.back().second;
            }
            else{
                mn = INT_MAX;
            }
        
        }
    }
    
    int top() {
        if(!v.size()){
            return -1;
        }
        else{
            return v.back().first;
        }
    }
    
    int getMin() {
        if(!v.size()){
            return -1;
        }
        else{
            return v.back().second;
        }
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