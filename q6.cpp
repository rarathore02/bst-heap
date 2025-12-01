#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i){
        while(i > 0 && heap[(i-1)/2] < heap[i]){
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i){
        int n = heap.size();
        while(true){
            int largest = i;
            int left = 2*i+1, right = 2*i+2;

            if(left < n && heap[left] > heap[largest]) largest = left;
            if(right < n && heap[right] > heap[largest]) largest = right;

            if(largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int top(){
        return heap.empty() ? -1 : heap[0];
    }

    void pop(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    MaxHeap pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Priority Queue top: " << pq.top() << endl;
    pq.pop();
    cout << "After pop, new top: " << pq.top() << endl;
}
