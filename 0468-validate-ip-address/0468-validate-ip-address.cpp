class Solution {
public:
    string validIPAddress(string queryIP) {
        int dot=0,colon=0;
        for(auto it:queryIP){
            if(it=='.') dot++;
            if(it==':') colon++;
        }
        
        if(dot==3){
            
            string temp;
            for(auto it:queryIP){
                if(it=='.'){
                    if(temp=="" || temp.length()>3) return "Neither";
                    int _amit = stoi(temp);
                    string _asim = to_string(_amit);
                    if(_asim!=temp) return "Neither";
                    if(_amit>255) return "Neither";
                    
                    temp="";
                }else if(it>='0'&&it<='9'){
                    temp+=it;
                }else{
                    return "Neither";
                }
            }
            if(temp=="" || temp.length()>3) return "Neither";
            int _amit = stoi(temp);
            string _asim = to_string(_amit);
            if(_asim!=temp) return "Neither";
            if(_amit>255) return "Neither";
            
            return "IPv4";
            
        }else if(colon==7){
            
            
            string temp;
            for(auto it:queryIP){
                if(it==':'){
                    if(temp=="") return "Neither";
                    if(temp.length()>4) return "Neither";
                    temp="";
                }else if((it>='0'&&it<='9')||(it>='a'&&it<='f')||(it>='A'&&it<='F')){
                    temp+=it;
                }else{
                    return "Neither";
                }
            }
            
            if(temp.length()>4 || temp=="") return "Neither";
            return "IPv6";
        }
        
        return "Neither";
        
    }
};