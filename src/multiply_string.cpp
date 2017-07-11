#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();

        string ret(size1 + size2, '0');
        int c = 0, k = 0;
    	for (int j = size2-1; j >= 0; j--, c++) {
    		int value, carryout = 0;
    		for (int i = size1-1; i >= 0; i--, k++) {
    			value = ret[c+k] - '0' + (num2[j]-'0') * (num1[i]-'0') + carryout;
    			ret[c+k] = value % 10 + '0';
    			carryout = value / 10;
    		}
    		if (carryout)
    			ret[c+k] += carryout;
    		k = 0;
    	}

    	int i;
    	for (i = ret.size() - 1; i > 0; i--) {
    		if (ret[i] != '0')
    			break;
    	}
    	string final(ret.begin(), ret.begin()+i+1);
    	std::reverse(final.begin(), final.end());
    	return final;
    }

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

    // Better solution.
    string addBinary1(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;	// gaurd
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;			// accumulate, so late
            c /= 2;
        }
        
        return s;
    }
};

int main() {

	Solution sol;

	string num1 = "23";
	string num2 = "23";

	string result = sol.multiply(num1, num2);
	cout << result << endl;

	string bin1 = "1";
	string bin2 = "10";
	cout << sol.addBinary(bin1, bin2) << endl;
}