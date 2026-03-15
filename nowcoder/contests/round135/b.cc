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
        for(int i = 1;i<=n;++i)
        {
            cin>>v[i];
            if(i == v[i])
            {
                ans+=1;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}