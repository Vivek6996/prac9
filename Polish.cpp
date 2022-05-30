#include "Polish.h"

#include <iostream>
#include <stack>
#include <string>

using namespace std;


Polish::Polish(){

    pre = "";
}

Polish::Polish(string function){
    pre = function;
}

void Polish::set(string function){
    pre = function;
}

string Polish::convert(){
    
    string in = "";

    stack<int> sk; 

    int vFun = 1;
    int val = 0;
    int d = 0;

    for (int i = pre.length() - 1; i >= 0 && vFun == 1; i--){
        
        char x = pre[i];

        if (x == ' '){
            d = 0;
        }
         else if (isdigit(x)) {
        d++;

        if (d == 1){
            val = x - '0';
        } else {
            val = val + (x - '0') * 10;
            sk.pop();
        }

        sk.push(val);

        if (val > 99){
            vFun = 0;
        }
    

    } else if ((x == '+' || x == '-' || x == '*' || x == '/')&& sk.size()>=2 && in.length()==0) {

        int n = sk.top();
        sk.pop();
        int nn = sk.top();
        sk.pop();
        ostringstream y;

        y << in << "(" << n << " " << x << " " << nn << ")";
        in = y.str();
        d = 0;
    } else if ((x == '+' || x == '-' || x == '*' || x == '/')&& sk.size()==1 && in.length()>0) {

        int n = sk.top();
        sk.pop();
        ostringstream y;

        y << in << " " << x << " " << n;
        in = y.str();
        d = 0;

    } else if ((x == '+' || x == '-' || x == '*' || x == '/')&& sk.size()>=2 && in.length()>0) {

        int n = sk.top();
        sk.pop();
        ostringstream y;

        y << "(" << in << " " << x << " " << n << ")";
        in = y.str();
        d = 0;
    } else {
        vFun = 0;
    }

    
    }
    if (vFun == 0 || sk.size() > 0) {
        in = "Error";
    
}
    return in;
}

int Polish::calc(){

    int ans = 0;
    stack<int> sk;
    int vFun = 1;
    int val = 0;
    int d = 0;

    for (int i = pre.length()-1;i>=0 && vFun == 1; i--){

        char x = pre[i];

        if (x == ' ') {
            d = 0;
        } else if (isdigit(x)) {
            d++;

            if (d==1){
                val = x - '0';

            } else {
                val = val + (x-'0') * 10;
                sk.pop();
            }

            sk.push(val);

            if (val>99){
                vFun = 0;
            }

        } else if (x == '+' && sk.size()>=2) {

            int n = sk.top();
            sk.pop();
            int nn = sk.top();
            sk.pop();
            sk.push(n+nn);
            d = 0;
        } else if (x == '-' && sk.size()>=2){
            int n = sk.top();
            sk.pop();
            int nn = sk.top();
            sk.pop();
            sk.push(n-nn);
            d = 0;
        } else if (x == '*' && sk.size()>=2) {
            int n = sk.top();
            sk.pop();
            int nn = sk.top();
            sk.pop();
            sk.push(n*nn);
            d = 0;
        } else if (x == '/' && sk.size()>=2) {
            int n = sk.top();
            sk.pop();
            int nn = sk.top();
            sk.pop();
            sk.push(n/nn);
            d = 0;
        } else {
            vFun = 0;
        }
    }

    if(vFun ==1 && !sk.empty()){
        ans = sk.top();
        sk.pop();
    }

    return ans;

}