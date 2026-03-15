#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n+1);
        int ans = 0;
        int flag = 1;
        for(int i = 1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]!=i)
            {
                flag = 0;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i = 2;i<=n;++i)
        {
            if(v[i] == i-1&&v[i-1]==i)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            cout<<"NO"<<endl;
            
        }
        else
        {
            cout<<"YES"<<endl;
            
        }
        
    }
    return 0;
}