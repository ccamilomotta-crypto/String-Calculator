#include <iostream>
#include <string>
#include "functions.h"

using std::string;

string add(const string& lhs, const string& rhs) {
    // TODO(student): compute sum of arguments
    string a_raw=lhs;
    string b_raw=rhs;

    bool a_neg=false;
    bool b_neg=false;

    int a_start=0;
    if(a_raw.size()>0&&(a_raw[0] =='-' || a_raw[0] =='+')){
        if(a_raw[0]=='-') a_neg =true;
        a_start = 1;
    }
    int b_start =0;
    if(b_raw.size() >0&&(b_raw[0] == '-' ||b_raw[0]=='+')){
        if (b_raw[0] =='-')b_neg=true;
        b_start =1;
    }
    string a ="";
    for(int i = a_start; i <(int)a_raw.size();++i){
        a.push_back(a_raw[i]);
    }
    string b ="";
    for(int i = b_start; i <(int)b_raw.size();++i){
        b.push_back(b_raw[i]);
    }
    if(a.size() ==0) a="0";
    if(b.size() ==0) b="0";

    int i =0;
    while(i < (int)a.size() - 1 &&a[i]=='0'){
        ++i;
    }
    string a2 ="";
    for(int j =i;j<(int)a.size(); ++j){
        a2.push_back(a[j]);
    }
    a =a2;

    i =0;
    while(i <(int)b.size() -1 &&b[i]=='0'){
        ++i;
    }
    string b2 ="";
    for(int j = i; j < (int)b.size(); ++j){
        b2.push_back(b[j]);
    }
    b =b2;
    if(a == "0") a_neg =false;
    if(b == "0") b_neg =false;

    if(a_neg == b_neg){
        int ia =(int)a.size() -1;
        int ib =(int)b.size() -1;
        int carry =0;
        string rev ="";

        while (ia >= 0||ib>=0|| carry > 0) {
            int da =0;
            int db =0;
            if(ia >= 0) da = a[ia] -'0';
            if(ib >= 0) db = b[ib] -'0';

            int sum =da + db + carry;
            int digit =sum % 10;
            carry = sum /10;

            rev.push_back(char('0' + digit));
            --ia;
            --ib;
        }
        string result = "";
        for(int r = (int)rev.size() - 1; r >= 0; --r){
            result.push_back(rev[r]);
        }

        i = 0;
        while(i < (int)result.size() -1 && result[i] =='0'){
            ++i;
        }
        string r2 = "";
        for (int j = i; j < (int)result.size(); ++j) {
            r2.push_back(result[j]);
        }
        result =r2;

        if(a_neg && result !="0"){
            result = "-" + result;
        }
        return result;
    }
    int cmp =0;
    if(a.size() <b.size()){
        cmp =-1;
    }else if(a.size()>b.size()){
        cmp=1;
    }else{
        for(int p = 0; p < (int)a.size(); ++p){
            if(a[p]<b[p]) {
                cmp = -1;
                break;
            }
            if (a[p]>b[p]){
                cmp =1;
                break;
            }
        }
    }
    if (cmp ==0){
        return"0";
    }
    string big =a;
    string small =b;
    bool result_neg =a_neg;

    if (cmp < 0){
        big =b;
        small =a;
        result_neg =b_neg;
    }

    int ib1 =(int)big.size()- 1;
    int is1 =(int)small.size()- 1;
    int borrow =0;
    string rev ="";

    while(ib1 >=0){
        int dbig =big[ib1] -'0';
        int dsmall =0;
        if(is1 >= 0)dsmall = small[is1] -'0';

        dbig=dbig-borrow;
        if(dbig<dsmall){
            dbig +=10;
            borrow =1;
        }else{
            borrow =0;
        }

        int diff = dbig-dsmall;
        rev.push_back(char('0'+ diff));
        --ib1;
        --is1;
    }
    string result = "";
    for(int r = (int)rev.size() - 1; r >=0;--r){
        result.push_back(rev[r]);
    }
    i =0;
    while(i < (int)result.size() - 1 && result[i] =='0'){
        ++i;
    }
    string r2 ="";
    for(int j = i; j < (int)result.size();++j){
        r2.push_back(result[j]);
    }
    result =r2;
    if(result_neg && result != "0"){
        result = "-" +result;
    }
    return result;
}
string subtract(const string& lhs, const string& rhs) {
    // TODO(student): compute difference of arguments
    string neg_rhs ="";
    if(rhs.size() > 0 && rhs[0] == '-'){
        for(int i = 1; i < (int)rhs.size(); ++i){
            neg_rhs.push_back(rhs[i]);
        }
    }else if(rhs.size() > 0 && rhs[0] == '+'){
        neg_rhs.push_back('-');
        for(int i = 1; i < (int)rhs.size(); ++i){
            neg_rhs.push_back(rhs[i]);
            for(int i = 0; i<(int)lhs.size();i++){
            neg_rhs.push_back(rhs[i]);}
        }
    }else{
        neg_rhs.push_back('-');
        for(int i =0;i<(int)rhs.size(); ++i){
            neg_rhs.push_back(rhs[i]);
        }
    }
    return add(lhs, neg_rhs);
}

string multiply(const string& lhs, const string& rhs) {
    // TODO(student): compute product of arguments
    string a_raw =lhs;
    string b_raw =rhs;

    bool a_neg =false;
    bool b_neg =false;

    int a_start = 0;
    if(a_raw.size() > 0 && (a_raw[0] == '-'|| a_raw[0]=='+')){
        if (a_raw[0] =='-') a_neg =true;
        a_start = 1;
    }
    int b_start = 0;
    if(b_raw.size() > 0 && (b_raw[0] == '-' || b_raw[0]=='+')){
        if(b_raw[0] == '-')b_neg=true;
        b_start =1;
    }

    string a ="";
    for(int i = a_start; i < (int)a_raw.size(); ++i){
        a.push_back(a_raw[i]);
    }

    string b = "";
    for(int i = b_start; i < (int)b_raw.size(); ++i){
        b.push_back(b_raw[i]);
    }

    if(a.size() == 0) a ="0";
    if(b.size() == 0) b ="0";

    int i = 0;
    while(i <(int)a.size() -1 && a[i] == '0'){
        ++i;
    }
    string a2 ="";
    for(int j = i; j < (int)a.size(); ++j){
        a2.push_back(a[j]);
    }
    a=a2;
    i =0;
    while(i <(int)b.size() - 1 && b[i] == '0'){
        ++i;
    }
    string b2 ="";
    for(int j = i; j < (int)b.size(); ++j){
        b2.push_back(b[j]);
    }
    b =b2;

    if(a == "0" || b == "0"){
        return "0";
    }
    int n =(int)a.size();
    int m =(int)b.size();
    string res(n + m,'0');

    for(int ia = n - 1; ia >= 0; --ia){
        int carry = 0;
        int da = a[ia] - '0';
        for(int ib = m - 1; ib >= 0; --ib){
            int db = b[ib] -'0';
            int idx = ia + ib +1;

            int cur =res[idx] - '0';
            int prod =da * db + cur + carry;

            res[idx] = char('0' + (prod % 10));
            carry = prod / 10;
        }
        int idx = ia;
        while(carry > 0 && idx >= 0){
            int cur = (res[idx] - '0') + carry;
            res[idx] = char('0' + (cur % 10));
            carry = cur / 10;
            --idx;
        }
    }
    i = 0;
    while(i <(int)res.size() - 1 && res[i] == '0'){
        ++i;
    }
    string r2 ="";
    for(int j = i; j < (int)res.size(); ++j){
        r2.push_back(res[j]);
    }
    res = r2;
    if(a_neg != b_neg){
        res ="-"+res;
    }
    return res;
}
