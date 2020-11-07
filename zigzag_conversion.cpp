#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1){
            return s;
        }
        
        vector <vector<char>> v;
        for(int i=0;i<numRows;i++){
            v.push_back(vector<char>()); 
        }
        

        int a=0;
        int b=0;
        bool d=false;

        for(int i=0;i<s.length();i++){
            cout<<s[i]<<endl;
            if((a==numRows)||(a<0)){
                if(d==false){
                    d=true;
                    a-=2;
                    b++;
                }
                else if(d==true){
                    d=false;
                    a+=2;
                     b--;
                }
            }

            while((int) v[a].size() -1 < b){
                v[a].push_back(' ');
            }

            v[a][b]=s[i];
            if(d==false){
                a++;    
            }else if(d==true){
                a--;
                b++;
            }
            
            
        }
  
        string o;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]!=' '){
                    o.push_back(v[i][j]);    
                }
            }
        }
        
        return o;
    }
};