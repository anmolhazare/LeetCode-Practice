class Solution {
public:
    bool halvesAreAlike(string s) {
        int a=0;
        int b=0;
        int n = s.length();
        map<char,int> mp;
        mp['a']=1; mp['e']=1; mp['i']=1; mp['o']=1; mp['u']=1;
        mp['A']=1; mp['E']=1; mp['I']=1; mp['O']=1; mp['U']=1;
        
        for(int i=0;i<(n/2);i++){
            if(mp.count(s[i])>0) a++;
        }
        for(int i=(n/2);i<n;i++){
            if(mp.count(s[i])>0) b++;
        }
        
        return a==b;
    }
};