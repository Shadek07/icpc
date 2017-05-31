
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

#define MAX 100005

bool mat[26][26];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int m,n;
    cin >> m >> n;
    getchar();
    int i,j,k;
    ms(mat,false);
    forl(i,0,26){
        mat[i][i] = true;
    }
    forl(i,0,m){
        char c1,c2;
        cin >> c1 >> c2;
        mat[c1-'a'][c2-'a'] = true;
    }
    getchar();
    forl(k,0,26){
        forl(i,0,26){
            forl(j,0,26){
                if(i!= j && i!= k && j!= k){
                    mat[i][j] |= mat[i][k]&&mat[k][j];
                }
            }
        }
    }
    char in1[51], in2[51];
    forl(i,0,n){
        cin >> in1 >> in2;
        int len1 = strlen(in1);
        int len2 = strlen(in2);
        if(len1 != len2){
            cout << "no\n";
            continue;
        }
        bool ok=true;
        forl(j,0,len1){
            if(!mat[in1[j]-'a'][in2[j]-'a']){
                ok=false;
                break;
            }
        }
        if(ok)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
