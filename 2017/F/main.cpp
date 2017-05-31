
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
#include <fstream>
#include<ctime>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 260

long long mat[MAX][MAX];
ull a[MAX][2];
int d,K;
int v;
int getIndex(int v){
    int i;
    forl(i,0,d)
    if(a[i][0] > v)
        return i;
    return d-1;
}
long long doit(int prev, int used){
    int i,j,k;
    long long t;
    if(255 - prev < K - used)
        return 1e12;
    if(used == K){
        t = 0;
        int ind = getIndex(prev);
        forl(i,ind,d){
            t += a[i][1]*(a[i][0] - prev)*(a[i][0] - prev);
        }
        return t;
    }
    if(mat[prev][used] != -1)
        return mat[prev][used];
    long long &res = mat[prev][used];

    forl(i,prev+1,256){
        t = 0;
        int ind = getIndex(prev);
        forl(j,ind,d){
            if(a[j][0] > i)
                break;
            long long t1 = a[j][0] - prev;
            t1 = min(t1, i - a[j][0]);
            t += t1*t1*a[j][1];
        }
        long long ans = t + doit(i,used+1);
        if(res == -1)
            res = ans;
        else
            res = min(res,ans);
    }
    return res;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int m,n;
    cin >> d >> K;
    getchar();
    int i,j,k;
    forl(i,0,d){
        cin >> a[i][0] >> a[i][1];
    }
    v = a[d-1][0];
    forl(i,0,MAX){
        forl(j,0,MAX){
            mat[i][j] = -1;
        }
    }
    long long int ans = -1;
    forl(i,0,256){
        long long int t = 0;
        forl(j,0,d){
            if(a[j][0] > i)
                break;
            t += (i-a[j][0])*(i-a[j][0])*a[j][1];
        }
        t += doit(i,1);
        if(ans==-1)
            ans = t;
        else
            ans = min(ans,t);
    }
    cout << ans << endl;
    return 0;
}
