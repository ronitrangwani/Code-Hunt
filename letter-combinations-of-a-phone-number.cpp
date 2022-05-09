class Solution {
public:
    string res(vector<vector<char>> &v,vector<string>&ans,string digits,int pos,string s){
        if(pos==digits.size()){
            if(s!="")
            ans.push_back(s);return "";
        }
        int temp=digits[pos]-'0';  
        for(int i=0;i<v[temp].size();i++){
            s.push_back(v[temp][i]);
            res(v,ans,digits,pos+1,s);
            s.pop_back();
        }
        return s;
    }
    
    vector<string> letterCombinations(string digits) {
        string s="";
        vector<vector<char>> v{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        
        vector<string>ans;
        res(v,ans,digits,0,"");
        return ans;
        
    }
};
