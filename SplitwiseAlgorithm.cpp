#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Graph
{
	map<string,int> g;
	public:
	void transaction(string giver,string receiver, int amount)
	{
		if(g.find(giver)==g.end())
			g[giver]=-1*amount;
		else
			g[giver]=g[giver]-amount;
		if(g.find(receiver)==g.end())
			g[receiver]=amount;
		else
			g[receiver]=g[receiver]+amount;
	}
	void splitMoney()
	{
		int d,c,amount;
		set<pair<int,string> > s;
		for(auto itr:g)
		{
			if(itr.second!=0)
				s.insert({itr.second,itr.first});
		}
		while(s.size()>0)
		{
			auto debit=s.begin();
			auto credit=--s.end();
			s.erase(debit);
			s.erase(credit);
			d=debit->first;
			c=credit->first;
			// cout<<d<<" "<<c<<endl;
			string dp=debit->second;
			string cp=credit->second;
			amount=min(abs(d),c);
			cout<<dp<<" will give "<<amount<<" to "<<cp<<endl;
			d+=amount;
			c-=amount;
			if(d!=0)
				s.insert({d,dp});
			if(c!=0)
				s.insert({c,cp});
		}
	}
};
int main()
{
	int friends,NoOfTransactions,i;
	cin>>friends;
	Graph g;
	cin>>NoOfTransactions;
	string giver,receiver;
	int amount;
	while(NoOfTransactions--)
	{
		cin>>giver>>receiver>>amount;
		g.transaction(giver,receiver,amount);
	}
	g.splitMoney();
}
