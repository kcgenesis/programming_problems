#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1){return s;}
        
        string o;
        
        int r=0;
        int i,nextZig;
        while(r<numRows){

            i=0; 
            nextZig = 0;
            while(nextZig-(numRows-1) < (int) s.length()){
                if((r!=numRows-1)&&(r!=0)){
                    if(nextZig-r<s.length()){o.push_back(s[nextZig-r]);}
                }
                if(nextZig+r<s.length()){o.push_back(s[nextZig+r]);}
                i++;
                nextZig = 2*i*(numRows-1);
            }
            r++;
        }
        
        return o;
        
    }
};