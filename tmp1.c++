/*
A delivery boy wants to deliver some items on his way from office to home. 
You need to find the optimized path he should take from office to home and deliver all his deliveries on his way.
It is 101 X 101 grid. Office, home , delivery points are represented via coordinated (x,y) where 0 <= x <= 100, 0 <= y <= 100.
distance between two points (x1, y1) and (x2,y2) is computed as |x1 - x2| + |y1 - y2|

You need to find the optimized path from office to home covering all delivery locations and return the optimized path length as output.
You will be given the input in the 2 lines

first line - N (no. of delivery locations)
second line - (x,y) coordinates of office, followed by home, followed by all N delivery locations.

3
0 0 100 100 20 30 50 50 70 70

output: The length of the optimized path taken.

For above input, the output is 200
*/

//solution from CareerCup
#include<iostream>
using namespace std;

int abs(int aa)
{
	if(aa<0)
		return -1*aa;
	return aa;
}

int x[12],y[12],ox,oy,hx,hy,vis[12],ans,n,ct;

void solve(int xx,int yy,int visited,int curr_cost,int idx)
{
	int cost = 0;

	if(visited==n){
		curr_cost += abs(xx-hx)+abs(yy-hy);
		ans = min(ans,curr_cost);
	}

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			cost = curr_cost + abs(xx-x[i]) + abs(yy-y[i]);
			solve(x[i],y[i],visited+1,cost,i);
			

			vis[i]=0;
		}
	}

	
}

int main()
{
	ct=0;
	cin>>n;
	ans = 8888888;
	cin>>ox>>oy;
	cin>>hx>>hy;
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
		cin>>x[i]>>y[i];
	}
	solve(ox,oy,0,0,0);
	cout<<ans;
}