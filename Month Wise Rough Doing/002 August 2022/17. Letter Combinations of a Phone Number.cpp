class Solution {
public:
    int keypad(int num, string output[]){
   string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    if(num==0){
        output[0]="";
        return 1;
    }
    int last = num%10;
    int smallOutputSize = keypad(num/10,output);

    // Copy output array
    string* temp = new string[smallOutputSize];
    for(int i=0;i<smallOutputSize;i++){
        temp[i]=output[i];
    }

    for(int i=0;i<key[last].size();i++){
        for(int j=0;j<smallOutputSize;j++){
            output[i*smallOutputSize+j] = temp[j]+key[last][i];
        }
    }
    return key[last].length()*smallOutputSize;
    
}
    int digit(string st){
        if(st.length()==0) return 0;
        int d = (int)st[st.size()-1]-48;
        int ans = digit(st.substr(0, st.size()-1));
        return (ans*10)+d;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> vt;
        if(digits.length()==0){
            return vt;
        }
        string *output = new string[1000];
        int ans = keypad(digit(digits),output);
        for(int i=0;i<ans;i++){
            vt.push_back(output[i]);
        }
        return vt;
    }
};
