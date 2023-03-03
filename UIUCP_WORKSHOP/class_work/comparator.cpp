#include<bits/stdc++.h>
using namespace std;

struct Coordinate
{
    int x, y, z;
};
int main()
{
    vector< Coordinate > v;
    v.push_back({12, 15, 13});
    v.push_back({10, 9, 15});
    v.push_back({8, 5, 3});
    v.push_back({8, 20, 8});
    v.push_back({8, 20, 9});
    v.push_back({8, 20, 15});


    sort(v.begin(), v.end(), [&](Coordinate a, Coordinate b)
         {
            if(a.x == b.x)
            {
                if(a.y==b.y)
                {
                    return a.z > b.z;
                }
                else
                    return a.y < b.y;
            }
            else
                return a.x > b.x;

         });

    for(Coordinate x : v)
    {
        cout << x.x << " " << x.y << " " << x.z << endl;
    }

    return 0;
}
