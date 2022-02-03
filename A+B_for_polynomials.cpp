#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        double a;
        double b;
    node(double c,double d){
        a = c;
        b = d;
    }
    void add(node d){
     //   a += d.a;
        b += d.b;
    }
};
bool cmp(node m,node n){
    if(m.a == n.a){
        return m.b > n.b;
    }
    return m.a > n.a;
}
inline bool equal(node c,node d){
    if(c.a == d.a){
        return true;
    }
    return false;
}
int main(){
    int k;
    vector<node> v;
    cin >> k;
    double p,q;
    while(k--){
        cin >> p >> q;
        v.push_back(node(p,q));
    }
    cin >> k;
    while(k--){
        cin >> p >> q;
        v.push_back(node(p,q));
    }
    if(v.size() == 0){
        cout << 0;
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    node cur = v[0];
    vector<node> ans;
    for(int i = 1;i < v.size();++i){
        if(equal(cur,v[i])){
            cur.b += v[i].b;
            if(cur.b == 0){
                if(i != v.size()-1){
                    cur = v[i+1];
                    ++i;
                    if(i == (v.size()-1)){
                if(cur.b != 0)
                    ans.push_back(cur);
            }
                }
                continue ;
            }
            if(i == (v.size()-1)){
                if(cur.b != 0)
                    ans.push_back(cur);
            }
        }
        else{
            ans.push_back(cur);
            cur = v[i];
            if(i == (v.size()-1)){
                if(cur.b != 0)
                    ans.push_back(cur);
            }
        }
    }
    if(v.size() == 1){
        if(cur.b != 0)
    	    ans.push_back(cur);
	}
    cout << ans.size();
    for(int i = 0;i < ans.size();++i){
        cout << " " << ans[i].a << " ";
        printf("%.1f",ans[i].b);
    }
    return 0;
}