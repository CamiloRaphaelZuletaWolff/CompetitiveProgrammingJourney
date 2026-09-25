#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;





bool f(string &s,string &c, ll l, ll r, ll la, ll ra){

    // if(){
    //     return true;
    // }
    if((r-l+1)&1){
        // cout<<s.substr(l,r-l+1)<<" "<<c.substr(la,ra-la+1)<<"\n";
        return s.substr(l,r-l+1)== c.substr(la,ra-la+1);}
    ll mid = (r+l)/2;
    ll mid2 = (ra+la)/2; 
    bool ff = (f(s,c,l,mid,la, mid2) && f(s,c,mid+1,r,mid2+1, ra)) || 
    (f(s,c,l,mid,mid2+1, ra) && f(s,c,mid+1,r,la, mid2));
    return ff;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    string s;cin>>s;
    string c;cin>>c;
    ll n = s.size();
    ll sum = accumulate(s.begin(),s.end(),0LL);
    ll sum1 = accumulate(c.begin(),c.end(),0LL);
    cout<<(sum == sum1 && f(s,c,0,n-1,0,n-1)?"YES\n":"NO\n");
    return 0;

}