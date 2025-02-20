#include <bits/stdc++.h>
using namespace std;
string addStrings(const std::string &num1, const std::string &num2) {
    string result = "";
    int carry = 0;

    long long i = num1.size() - 1;
    long long j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}
string giaiMa(long long current, string &input, vector <string> &ans){
    if (current > input.length()){
        return "0";
    }
    else if (current == input.length()){
        return "1";
    }
    else if (current == input.length()-1){
        if (input[current] != '0'){
            return "1";
        }
        return "0";
    }
    // else if (current )
    else{
        if (ans[current] != "-1"){
            return ans[current];
        }
        if (input[current]=='0'){
            return ans[current]='0';
        }
        else if (input[current]=='1'){
            return ans[current]=  addStrings(giaiMa(current+1, input, ans), giaiMa (current+2,input, ans));
            //25114
            // 2-> 25
            //2 5 -> 25 1 -> 25 11
            // 2 5 1 -> 2 5 11 -> 25 1 1 -> 25 1 14 -> 
        }
        else if (input[current]=='2'){
            if (input[current+1] != '7' && input[current+1] != '8' && input[current+1]!= '9'){
                return ans[current]= addStrings(giaiMa(current+1, input, ans),giaiMa (current+2,input, ans));
            }
            else{
                return ans[current]= giaiMa(current+1, input, ans);
            }
        }
        else{
            return ans[current]= giaiMa(current+1, input, ans);
        }
    }
}
int main(){
    // freopen("dpcode.inp", "r", stdin);
    // freopen("dpcode.out", "w", stdout);
    string input;
    while (getline (cin, input)){
        if (input =="0"){
            break;
        }
        vector <string> ans (input.length(),"-1");
        cout <<giaiMa (0, input, ans)<< endl;
    }
    return 0;
}
    