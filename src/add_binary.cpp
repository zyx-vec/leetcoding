class Solution {
public:
    string addBinary(string a, string b) {
        int size1 = a.size();
        int size2 = b.size();
        int max_size, min_size;

        string* m;
        string* n;
        if (size1 > size2) {
        	max_size = size1;
        	min_size = size2;
        	m = &a, n = &b;
        } else {
        	max_size = size2;
        	min_size = size1;
        	m = &b, n = &a;
        }

        int diff = max_size - min_size;
        string ret(max_size+1, '0');
        int carryout = 0, value, c = 0;
        for (int i = min_size-1; i >= 0; i--, c++) {
        	value = (*m)[diff+i] - '0' + (*n)[i] - '0' + carryout;
        	ret[c] = value % 2 + '0';
        	carryout = value / 2;
        }
        for (int i = diff-1; i >= 0; i--, c++) {
        	value = (*m)[i] - '0' + carryout;
        	ret[c] = value % 2 + '0';
        	carryout = value / 2;
        }
        if (carryout)
        	ret[c] = carryout + '0';

        int i;
        for (i = ret.size()-1; i > 0; i--) {
        	if (ret[i] != '0')
        		break;
        }
        string final(ret.begin(), ret.begin()+i+1);
        std::reverse(final.begin(), final.end());
        return final;
    }
};