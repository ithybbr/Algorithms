    #include <iostream>
    #include <string>
    #include <cmath>
    using namespace std;
    long hashf(string& g){
        int p = 31;
        long s = g.size();
        long hash = 0;
        for(char c : g){
            int i = 0;
            hash += c * static_cast<long>(pow(p, i));
            i++;
        }
        return hash;
    }
    int main() {
        string word, subword;
        int cost = 0;
        cin >> word >> subword;
        long size = word.size();
        long subsize = subword.size();
        long subhash = hashf(subword);
        for(int i = 0; i <= size - subsize; i++){
            string tempword = word.substr(i, subsize);
            long temphash = hashf(tempword);
            if(temphash == subhash){
                bool match = true;
                for(int k = 0; k < subsize; k++){
                    if(tempword[k] != subword[k]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    cost++;
                    int m = i + subsize - 1;
                    word[m] = '#';
                }
            }
        }
        cout << cost;
        return 0;
    }
