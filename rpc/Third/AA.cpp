#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


double distancia(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    double a,b; cin>>a>>b;
    double c,d; cin>>c>>d;
    double e,f; cin>>e>>f;

    double lu = 1000000000000.0;

    for (ll i = 0; i < 3; i++)
    {
        double fijo1, fijo2, var1,var2, var3, var4;

        // for (ll i = 0; i < 3/; i++)
        // {
            if(i == 0){
                fijo1 = a; 
                fijo2 = b;
                var1 = c;
                var2 = d;
                var3 = e;
                var4 = f;
            }
            if(i == 1){
                
                fijo1 = c; 
                fijo2 = d;
                var1 = a;
                var2 = b;
                var3 = e;
                var4 = f;
            }
            if(i == 2){
                fijo1 = e; 
                fijo2 = f;
                var1 = c;
                var2 = d;
                var3 = a;
                var4 = b;
            }

            double longitud = distancia(var1,var2,var3,var4);
            // cout<<longitud<<endl;
            lu = min(lu, abs((var1 - var3)*(fijo1 - var1) + (var2 -var4)*(fijo2 - var2))/longitud);
            lu = min(lu, abs((var3 - var1)*(fijo1 - var3) + (var4 -var2)*(fijo2 - var4))/longitud);
            lu = min(lu, abs(longitud/2.0 - distancia((var1+var3)/2.0,(var2+var4)/2.0,fijo1,fijo2)));
            


        // }

    }
    
    cout<<fixed<<setprecision(9)<<lu<<endl;
    

    return 0;

}