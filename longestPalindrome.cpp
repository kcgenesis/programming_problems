#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
       
        if(s.size()==1){return s;}
        vector<int> ind;
        vector<int> len;
        for(int i=0;i<s.size();i++){
            if(i==1){
                if(s[i]==s[i-1]){
                    ind.push_back(i-1);
                    len.push_back(2);
                }
            }else if(i==2){
                if(s[i]==s[i-1]){
                   if(s[i]==s[i-2]){
                       len[len.size()-1] += 1; 
                   }else{
                        ind.push_back(i-1);
                        len.push_back(2);
                   }
                }else if(s[i]==s[i-2]){
                    ind.push_back(i-2);
                    len.push_back(3);
                }
            }else if(i>2){
                if(s[i]==s[i-1]){
                   if(s[i]==s[i-2]){
                       len[len.size()-1] += 1; 
                   }else{
                        ind.push_back(i-1);
                        len.push_back(2);
                   }
                }else if(s[i]==s[i-2]){
                    if(s[i-1]==s[i-3]){
                        len[len.size()-1] += 1;    
                    }else{
                        ind.push_back(i-2);
                        len.push_back(3);    
                    }
                }
            }
        }
        
        int ls=0;
        int rs=0;
        
        for(int i=0;i<ind.size();i++){
            
            ls = ind[i];
            rs = ind[i]+len[i]-1;
            int a=0;
            while(true){
                if((a==0)&&(s[ls]!=s[rs])){
                    len[i] -= 1;
                }
                ls--;
                rs++;
                if((ls>=0)&&(rs<s.size())){
                    if(s[ls]==s[rs]){
                        len[i] += 2;
                        ind[i] -= 1;        
                    }else{
                        
                        break;
                    }
                }else{
                    break;
                }
                
                a++;
            }
            
        }
        
        int max = 0;
        int maxind = 0;
        for(int i=0;i<len.size();i++){
            if(len[i]>max){
                max = len[i];
                maxind = i;
            }
        }
        
        string result;
        if(len.size()==0){
           return s.substr(0,1);
        }else{
            result = s.substr(ind[maxind],len[maxind]);
        }
        
        
        return result;
    }
};

int main(){

	Solution test;
	string a = "teststringabababababababaaaaaaaaaaa";

	cout << "INPUT:" << endl;
	cout << a << endl;

	cout << "OUTPUT:" << endl;
	cout << test.longestPalindrome(a) << endl;

	return 0;
}
