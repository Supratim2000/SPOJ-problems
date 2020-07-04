#include<iostream>
#include<vector>
#include<cstring>
typedef long long int ll;
using namespace std;
const int Nmax=32000;

bool prime[Nmax+1];
vector<int> prime_list;

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=Nmax;i++)
        if(prime[i])
            for(int j=i*i;j<=Nmax;j+=i)
                prime[j]=false;   
    for(int i=2;i<=Nmax;i++)
        if(prime[i])
            prime_list.push_back(i);
}

void seg_sieve(ll l,ll r)
{
    bool arr[r-l+1];
    memset(arr,true,sizeof(arr));
    if (l == 1)
        arr[0] = false;
    for(int i=0;prime_list[i]*prime_list[i]<=r;i++)
    {
        ll currentprime=prime_list[i];
        ll base=(l/currentprime)*currentprime;
        if(base<l)
            base+=currentprime;
        for(ll j=base;j<=r;j+=currentprime)
            arr[j-l]=false;
        if (base == currentprime)
            arr[base - l] = true;
    }
    for (int i = 0; i < r - l + 1; ++i)
    {
        if (arr[i])
            cout << (i + l) << endl;
    }
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        seg_sieve(l,r);
    }

    return 0;
}
