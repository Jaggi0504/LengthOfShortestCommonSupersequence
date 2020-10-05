#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int dp[m+1][n+1];
	for(int j=0;j<=n;j++) {
		dp[0][j] = 0;
	}
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return m + n - dp[m][n];
}

int main() {
	string s1, s2;
	cout<<"Enter string 1:"<<endl;
	cin>>s1;
	cout<<endl;
	cout<<"Enter string 2:"<<endl;
	cin>>s2;
	cout<<endl;
	int ans = shortestCommonSupersequence(s1, s2);
	cout<<"Length Shortest Common Supersequence is:"<<ans;
	return 0;
}
