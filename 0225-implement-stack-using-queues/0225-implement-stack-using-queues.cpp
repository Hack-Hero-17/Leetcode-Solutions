class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        // Constructor, no initialization needed for queues
    }
    
    void push(int x) {
        q2.push(x); // Push the new element into q2
        // Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap the names of q1 and q2
        swap(q1, q2);
    }
    
    int pop() {
        int topElement = q1.front(); // Get the top element
        q1.pop(); // Remove the top element
        return topElement;
    }
    
    int top() {
        return q1.front(); // The top element is at the front of q1
    }
    
    bool empty() {
        return q1.empty(); // Check if q1 is empty
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */