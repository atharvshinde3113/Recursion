void func(vector<string> &ans, string output, int index, string s){
    if(index>=s.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    func(ans,output,index+1,s);
    //include
    char a = s[index];
    output.push_back(a);
    func(ans,output,index+1,s);    
}


vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    string output;
    int index = 0;
    func(ans,output,index,s);
    return ans;

}