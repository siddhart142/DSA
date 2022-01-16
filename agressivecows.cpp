#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool canplace(int arr[],int n, int c ,int target)
{
	int cnt=1,pos=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]-pos>=target)
		{
			pos=arr[i];
			cnt++;
		}
	}
	if(cnt==c)
		return true;
	else
		return false;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		int arr[n];
		int i;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		int l=arr[0],r=arr[n-1]-arr[0];
		int mid,res;
		while(l<=r)
		{
			mid=l+((r-l)/2);
			if(canplace(arr,n,c,mid))
			{
				res=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		cout<<res<<"\n";
	}
	return 0;
}