class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
		
		if(len == 0) return true;
		
		if(len % 2) return false;
		
		bool res = true;
		vector<char> v;
		
		if(	s[0] == '(' ||
			s[0] == '[' ||
			s[0] == '{') {
			
			v.push_back(s[0]);
			
			for(int i = 1; i < len; i++) {
				switch(s[i]) {
					case ')':
						do {
							if(v.back() == '(') {
								v.pop_back();
							}
							else {
								res = false;
								goto ret;
							}
						} while(0);
						break;
					case ']':
						do {
							if(v.back() == '[') {
								v.pop_back();
							}
							else {
								res = false;
								goto ret;
							}
						} while(0);
						break;
					case '}':
						do {
							if(v.back() == '{') {
								v.pop_back();
							}
							else {
								res = false;
								goto ret;
							}
						} while(0);
						break;
					default :
						v.push_back(s[i]);
						break;
				}
			}
		}
		else {
		    res = false;
		}
		
		ret:
		return res && (v.size() == 0);
    }
};