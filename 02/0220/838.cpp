class Solution {
public:
    string pushDominoes(string dominoes) {
        char last = '0';
        int lastIndex = 0;
        string ret = "";
        for(int i = 0; i < dominoes.size(); i++) {
            //cout << i << endl;
            if(dominoes[i] == 'R') {
                if(last == '0') {
                    for(int j = lastIndex; j < i; j++) {
                        ret += '.';
                    }
                } else if(last == 'R') {
                    for(int j = lastIndex + 1; j < i; j++) {
                        ret += 'R';
                    }
                } else if(last == 'L') {
                    for(int j = lastIndex + 1; j < i; j++) {
                        ret += '.';
                    }
                }
                ret += 'R';
                last = 'R';
                lastIndex = i;
            } else if(dominoes[i] == 'L') {
                if(last == '0') {
                    for(int j = lastIndex; j < i; j++) {
                        ret += 'L';
                    }
                } else if(last == 'R') {
                    int mid = (i - lastIndex) / 2 + lastIndex;
                    for(int j = lastIndex + 1; j < mid; j++) {
                        ret += 'R';
                    }
                    if((i - lastIndex) % 2) {
                        if(lastIndex != mid) {
                            ret += 'R';
                        }
                        
                    } else {
                        ret += '.';
                    }
                    for(int j = mid + 1; j < i; j++) {
                        ret += 'L';
                    }
                } else if(last == 'L') {
                    for(int j = lastIndex + 1; j < i; j++) {
                        ret += 'L';
                    }
                }
                ret += 'L';
                last = 'L';
                lastIndex = i;
            }
            
            //cout << ret << endl;
        }
        
        if(last == '0') {
            for(int j = lastIndex; j < dominoes.size(); j++) {
                ret += '.';
            }
        } else if(last == 'L') {
            for(int j = lastIndex + 1; j < dominoes.size(); j++) {
                ret += '.';
            }
        } else {
            for(int j = lastIndex + 1; j < dominoes.size(); j++) {
                ret += 'R';
            }
        }
            
        return ret;
    }
};