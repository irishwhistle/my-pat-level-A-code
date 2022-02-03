#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a;
    long long int b;
    cin >> a >> b;
    long long int c = a+b;
    if(c == 0){
        cout << 0;
        return 0;
    }
    bool negative = false;
    if(c < 0){
        negative = true;
        c *= (-1);
    }
    stack<int> num;
    int count = 0;
    while(c > 0){
        int ys = c % 10;
        num.push(ys);
        c /= 10;
        ++count;
    }
   // cout << "count "<< count << endl;
    int r = count % 3;
    int tr = r;
    count -= r;
    bool fo = false;
    if(negative){
        cout << "-";
    }
    while(r--){
    	fo = true;
        cout << num.top();
        num.pop();
    }
    int index = 0;
    if(count == 0){
        return 0;
    }
    while(count){
        if((index % 3 == 0 && fo)){
            cout << ",";
        }
        else if(!fo){
        	fo = true;
		}
        ++index;
        cout << num.top();
        num.pop();
        --count;
    }
    return 0;
}
