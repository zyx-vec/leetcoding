void swap(vector<int>& cont, int i, int j) {
    int tmp = cont[i];
    cont[i] = cont[j];
    cont[j] = tmp;
}

// 1 to size is valid content.
struct Heap {
    Heap(vector<int>& nums) {
        size = nums.size();
        cont.reserve(size+1);
        cont.resize(size+1);
        for(int i = 0; i < size; i++) {
            cont[i+1] = nums[i];
        }
    }
    
    void heapify(int n);
    void makeHeap();
    int extractMax();
    void printHeap();
    
    int size;
    vector<int> cont;
};

void Heap::heapify(int n) {
    if(n*2 > size) {
        return;
    }
    else if(n*2 == size) {  // one left child
        if(cont[n*2] > cont[n]) {
            swap(cont, n*2, n);
        }
        return;
    }
    else {                  // double child
        int i = (cont[n*2]>cont[n*2+1]) ? n*2 : n*2+1;
        if(cont[i] > cont[n]) {
            swap(cont, i, n);
            heapify(i);     // heapify the adjusted child branch recurisively
        }
        else {              // done
            return;
        }
    }
}

void Heap::makeHeap() {
    for(int i = size/2; i > 0; i--) {
        heapify(i);
    }
}

int Heap::extractMax() {
    swap(cont, 1, size);
    size--;
    heapify(1);
    
    return cont[size+1];
}

void Heap::printHeap() {
    for(int i = 1; i <= size; i++) {
        cout << cont[i] << ' ';
    }
    cout << endl;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap h(nums);
        h.makeHeap();
        
        int ret;
        for(int i = 0; i < k; i++) {
            ret = h.extractMax();
        }
        
        return ret;
    }
};
