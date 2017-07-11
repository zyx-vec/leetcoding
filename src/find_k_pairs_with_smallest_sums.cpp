struct Pair {
	int x, y;
	Pair() { }
	Pair(int _x, int _y) : x(_x), y(_y) { }
	Pair(const Pair& o) {
		x = o.x; y = o.y;
	}
};

bool operator>(const Pair& lhs, const Pair& rhs) {
	return (lhs.x+lhs.y) > (rhs.x+rhs.y);
}

ostream& operator<<(ostream& os, const Pair& p) {
	return os << "(" << p.x << ", " << p.y << ") -> sum: " << p.x + p.y;
}

// min heap
template <typename T>
struct Heap {
	vector<T> cont;
	int size;
	
	Heap(int n) {
		cont.reserve(n+1);
		cont.resize(n+1);
		size = 0;
	}
	
	int count() { return size; }
	
	void swap(int m, int n);
	void heapify(int n);
	void make_heap();
	T extractMin();
	void decrease(int n, const T&);
	void insert(const T&);
	void print();
};

template <typename T>
void Heap<T>::print() {
	cout << "current size is: " << size << endl;
	for(int i = 1; i <= size; i++) {
		cout << cont[i] << endl;
	}
}

template <typename T>
void Heap<T>::swap(int m, int n) {
	T tmp = cont[m];
	cont[m] = cont[n];
	cont[n] = tmp;
}

template <typename T>
void Heap<T>::heapify(int n) {	// n [1..]
	int l = n*2, r = l+1;
	if(l > size) {			// no child
		return;
	}
	else if(l == size) {	// only left child
		int i;
		if(cont[n]>cont[l]) {
			swap(n, l);
		}
		return;
	}
	else {					// double child
		int i = cont[n]>cont[l] ? l : n;
		i = cont[i]>cont[r] ? r : i;
		
		if(i != n) {		// swap and recurisively heapify
			swap(i, n);
			heapify(i);
		}
		else {				// hit the buttom
			return;
		}
	}
}

template <typename T>
void Heap<T>::make_heap() {
	for(int i = size/2; i >= 0; i--) {
		heapify(i);
	}
}

template <typename T>
void Heap<T>::decrease(int n, const T& target) {
	cont[n].x = target.x;
	cont[n].y = target.y;
	// index from 1 to n
	while(n != 1 && cont[n/2]>cont[n]) {
		swap(n/2, n);
		n /= 2;
	}
}

template <typename T>
void Heap<T>::insert(const T& value) {
	size++;
	cont[size] = value;
	
	decrease(size, value);
}

template <typename T>
T Heap<T>::extractMin() {
	assert(1 <= size);
	swap(1, size);
	size--;
	heapify(1);
	
	return cont[size+1];
}

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int sz1 = nums1.size(), sz2 = nums2.size();
        Heap<Pair> h(sz1*sz2);
		
		for(int i = 0; i < sz1; i++) {
			for(int j = 0; j < sz2; j++) {
				h.insert(Pair(nums1[i], nums2[j]));
			}
		}
		
		vector<pair<int, int> > ret;
		for(int i = 0; i < k && h.count() > 0; i++) {
			Pair t = h.extractMin();
			ret.push_back(make_pair(t.x, t.y));
		}
		
		return ret;
    }
};