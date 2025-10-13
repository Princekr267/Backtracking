#include<iostream>
#include<cstring>
using namespace std;
void subsets(string str, string subset){
    if(str.size()==0){
        cout<<subset<<endl;
        return;
    }
    char ch=str[0];
    subsets(str.substr(1, str.size()-1), subset+ch);
    subsets(str.substr(1, str.size()-1), subset);
}
void permutations(string str, string ans){
    int n=str.size();
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        char ch=str[i];
        string nextStr=str.substr(0,i)+str.substr(i+1, n-i-1);
        permutations(nextStr, ans+ch);
    }
}
int main(){
    string str="abc";
    string subset="";
    subsets(str, subset);
    permutations(str, subset);
    return 0;
}