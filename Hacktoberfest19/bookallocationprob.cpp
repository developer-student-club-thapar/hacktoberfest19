#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool canplace(ll pages[],ll books,ll students,ll mid){
	ll stud=1;
	ll currentpages =0;
	for(int i=0;i<books;i++)
	{
		if(currentpages + pages[i]>mid)
		{
			currentpages = pages[i];
			stud++;
			if(stud>students)
			{
				return false;
			}
		}
			else
			{
				currentpages+=pages[i];
			}
	}
	return true;
}


int main(){
    int n;
    cin>>n;
for(int r=0;r<n;r++){
ll books,students;
cin>>books>>students;
ll pages[books];
for(ll i = 0;i<books;i++){
	cin>>pages[i];
}
ll s=pages[books-1];
ll e=0;
for(ll i = 0;i<books;i++){
	e+=pages[i];
}
ll ans=0;
while(s<=e){
ll mid = (s+e)/2;
if(canplace(pages,books,students,mid))	{
	ans = mid;
	e = mid-1;
}
else{
	s = mid+1;
}

}

cout<<ans<<endl;
}
return 0;
}