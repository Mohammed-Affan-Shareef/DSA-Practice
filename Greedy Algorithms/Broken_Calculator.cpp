#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using vi=vector<int>;
using vll=vector<long long>;
static const int MOD=1e9+7;
inline void fastio(){ios::sync_with_stdio(false);cin.tie(nullptr);}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target==startValue)return 0;
        int operations=0;
        while(target>startValue){
            if(target%2==0)target/=2;
            else target+=1;
            operations++;
        }
        return operations+startValue-target;
    }
};