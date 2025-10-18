#include "bits/stdc++.h"
#include <climits>
using namespace std;
int n , a , b , c;
vector<int> graph[1005];
int lvl[1005] , mx = INT_MIN ;
int main(){
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        cin>> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}