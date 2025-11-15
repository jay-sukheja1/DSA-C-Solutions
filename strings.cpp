#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// string using arrays
// int main(){
    // char str1[]={'H','e','l','l','o','\0'};
    // cout<<str1<<endl;
    // char str[]="Hello";
    // cout<<str<<endl;
    // char str2[12];
    // cout<<"Enter in a string: ";
    // cin>>str2; // will read input until the first space
    // cout<<"You entered: "<<str2<<endl;
    // cin.getline(str2,12); // will read the entire line including spaces
    // cout<<"You entered: "<<str2<<endl;
    // cout<<"Enter in a string: ";
    // cin.getline(str2,100,'.'); // will read until the delimiter '.'
    // cout<<"You entered until '.': "<<str2<<endl;
    // for(char c : str2){
    //    cout<<c<<endl;
    // }
//     char str3[]="Hello World";
//     int len=0;
//     for(int i=0; i<str3[i]!='\0'; i++){
//         len++;
//     }
//     cout<<"Length of str3 is: "<<len<<endl;
//     return 0;
// }

// string using string class

bool ispalindrome(string str){
    string revstr=str;
    reverse(revstr.begin(),revstr.end());
    if(str==revstr){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    if(ispalindrome("racecar")){
        cout<<"Palindrome"<<endl;
    } else {
        cout<<"Not Palindrone"<<endl;
    }
    return 0;
}

bool validpalindrome(string str){
    int n=str.length();
    int st=0, end=n-1;
    while(st<end){
        if(isalnum(!str[st])){st++; continue;}
        if(isalnum(!str[end])){end--; continue;}
        if(tolower(str[st])==tolower(str[end])){
            return true;
        }
        st++;
        end--;
    }
    return false;
}

void remallocc(string str,string part){
    while(str.find(part)<str.length() && str.length()>0){
        str.erase(str.find(part),part.length());
    }
    cout<<str;
}

bool isfreqsame(int freq1[], int freq2[]){
    for(int i=0; i<26; i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkinclusion(string s1,string s2){
    int freq[26]={};

    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }

    int windsize=s1.length();
    for(int i=0;i<s2.length();i++){
        int windidx=0,idx=i;
        int windfreq[26]={0};

        while(windidx<windsize && idx<s2.length()){
            windfreq[s2[idx]-'a']++;
            windidx++;
            idx++;
        }
        if(isfreqsame(freq,windfreq)){
            return true;
        }
    }
    return false;
}

string reversewords(string str){
    reverse(str.begin(),str.end());
    int n=str.length();
    string ans="";
    for(int i=0;i<n;i++){
        string word;
        while(i<n && str[i]!=' '){   // extract each word
            word+=str[i];
            i++;
        }
        reverse(word.begin(),word.end());   // reverse the word back to original
        if(word.length()>0){
            ans+=" "+word;
        }
    }
    return ans.substr(1);
}

int stringcompression(vector<char> arr){
    int n=arr.size();
    int idx=0;
    for(int i=0;i<n;i++){
        char ch = arr[i];
        int count = 0;
        while(i<n && arr[i]==ch){
            count++;
            i++;
        }
        if(count==1){arr[idx++]=ch;}
        else{
            arr[idx++]=ch;
            string str=to_string(count);
            for(char dig : str){
                arr[idx++]=dig;
            }
        }
        i--;    
    }
    arr.resize(idx);
    return idx;     // we only have to return the size of the array formed
}


/* int main(){
    string str="Hello World";  // dynamic, can resize automatically in runtime, which is not possible in char arrays
    cout<<str<<endl;
    string str2="People";
    string str3=str+" "+str2; // concatenation
    cout<<str3<<endl;
    cout<<(str==str2)<<endl; // comparison
    cout<<(str<str2)<<endl; // lexicographical comparison
    cout<<"Length of str3 is: "<<str3.length()<<endl; // length of string
    string str4;
    cout<<"Enter in a string: ";
    // cin>>str4; // will read input until the first space
    getline(cin,str4); // will read the entire line including spaces, until newline, can add delimiter as 3rd argument
    cout<<"You entered: "<<str4<<endl;
    for(int i=0; i<str4.length(); i++){  // these two loops do the same thing
        cout<<str4[i]<<" ";
    }
    cout<<endl;
    for(char c : str4){
        cout<<c<<" ";
    }
    cout<<endl;
    int n=str4.length();
    // int st=0,end=n-1;     // char array method
    // while(st<end){
    //     swap(str4[st],str4[end]);
    //     st++;
    //     end--;
    // }
    // cout<<str4<<endl;
    reverse(str4.begin(),str4.end());
    cout<<str4<<endl;
    string str5="racecar";
    if(ispalindrome(str5)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
} */