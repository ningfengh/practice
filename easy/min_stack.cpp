class MinStack {
public:
    
	stack <int> mystack;
    stack <int> minstack;
    int current_min;
	void push(int x) {
        mystack.push(x);
        if (minstack.empty()) minstack.push(x);
        else if (minstack.top()>x) minstack.push(x);
        else minstack.push(minstack.top());
    }

    void pop() {
        mystack.pop();
        minstack.pop();
    }

    int top() {
        return mystack.top();
    }

    int getMin() {
        return minstack.top();
    }
};