#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx          priority_queue<int> // maxheap
#define pqmn          priority_queue<int,vector<int>,greater<int> >//minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());



signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n,e,h,a,b,c;
        cin>>n>>e>>h>>a>>b>>c;

        int mxo = e/2;
        int mxm = h/3;
        int mxcake = min(e,h);
         
        //  deb2(mxo,mxm);
        //  cout<<endl;
        //  deb(mxcake);

        if(n>mxo and n>mxm and n>mxcake)
            cout<<"-1"<<endl;
        else{
            vector<pair<int, char>> v;
            v.pb({a, 'A'});
            v.pb({b, 'B'});
            v.pb({c, 'C'});
            sort(all(v));
            // for (int i = 0; i < 3; i++)
            // {
            //     cout << v[i].first << " " << v[i].second << endl;
            // }
            int price = 0;
            if (v[0].second == 'A' and n > 0)
            {              
               
               if (n >= (e / 2))
               {
                   price += a * (e / 2);
                   n = n - (e / 2);
               }
               else
               {
                   price += a * n;
                   n = 0;
               }
               e = e % 2;
               if (v[1].second == 'B' and n > 0)
               {
                 
                 if (n >= (h / 3))
                 {
                     price += b * (h / 3);
                     n = n - (h / 3);
                 }
                 else
                 {
                     price += b * n;
                     n = 0;
                 }
                  h = h % 3;

                  if (e >= 1 and h >= 1)
                  {
                      if(e>=h)
                       {
                           
                           if (n >= h)
                           {
                               price += c * h;
                               n = n - h;
                           }
                           else
                           {
                               price += c * n;
                               n = 0;
                           }
                       }
                       else if(e<h)
                       {
                         
                           if (n >= e)
                           {
                               price += c * e;
                               n = n - e;
                           }
                           else
                           {
                               price += c * n;
                               n = 0;
                           }
                       }
                   }

               }
               else if (v[1].second == 'C' and n > 0)
               {
                   if(e>=1)
                  {
                      if (n >= min(e, h))
                      {
                          price += c * min(e, h);
                          n = n - min(e, h);
                      }
                      else
                      {
                          price += c * n;
                          n = 0;
                      }
                      if (e <= h)
                      {
                          h = h - e;
                          e = e - e;
                      }
                      else
                      {
                          e = e - h;
                          h = h - h;
                      }
                   if (n >= (h / 3))
                   {
                       price += b * (h / 3);
                       n = n - (h / 3);
                   }
                   else
                   {
                       price += b * n;
                       n = 0;
                   }
                   }
               }
            }
            //B
            else if (v[0].second == 'B' and n>0)
            {
                
                if (n >= (h / 3))
                {
                    price += b * (h / 3);
                    n = n - (h / 3);
                }
                else
                {
                    price += b * n;
                    n = 0;
                }
                h = h%3;
                if (v[1].second == 'C' and n>0)
                {
                    if(h>=1 and e>=1)
                    {
                        
                        if (n >= min(e, h))
                        {
                            price += c * min(e, h);
                            n = n - min(e, h);
                        }
                        else
                        {
                            price += c * n;
                            n = 0;
                        }
                        if (e <= h)
                        {
                            h = h - e;
                            e = e - e;
                        }
                        else
                        {
                            e = e - h;
                            h = h - h;
                        }
                    }

                    if (n >= (e / 2))
                    {
                        price += a * (e / 2);
                        n = n - (e / 2);
                    }
                    else
                    {
                        price += a * n;
                        n = 0;
                    }

                    e = e % 2;
                }
                if (v[1].second == 'A' and n > 0)
                {
                   
                    if (n >= (e / 2))
                    {
                        price += a * (e / 2);
                        n = n - (e / 2);
                    }
                    else
                    {
                        price += a * n;
                        n = 0;
                    }
                    e = e % 2;
                    if (h >= 1 and e >= 1)
                    {
                        
                        if (n >= min(e, h))
                        {
                            price += c * min(e, h);
                            n = n - min(e, h);
                        }
                        else
                        {
                            price += c * n;
                            n = 0;
                        }
                        
                    }
                }
            }
            //C
            else if (v[0].second == 'C' and n > 0)
            {
                if (h >= 1 and e >= 1)
                {
                    if (n >= min(e, h))
                      {   price += c * min(e, h);
                          n = n - min(e, h);
                        }
                    else
                    {
                        price += c * n;
                        n = 0;
                    }
                    if (e <= h)
                    {
                        h = h - e;
                        e = e - e;
                    }
                     else{
                         e = e - h;
                         h = h - h;
                     }
                }

                if (v[1].second == 'A' and n >0 )
                {
                   if(n >= (e/2)){
                        price += a * (e / 2);
                        n = n-(e/2);
                   }
                   else{
                       price += a * n;
                       n = 0;
                   }
                    e = e % 2;

                    if (n >= (h / 3))
                    {
                        price += b * (h / 3);
                        n = n - (h / 3);
                    }
                    else
                    {
                        price += b * n;
                        n = 0;
                    }
                }
                // deb(price);
                // deb2(e,h);
                if (v[1].second == 'B' and n > 0)
                {
                    if (n >= (h / 3))
                    {
                        price += b * (h / 3);
                        n = n - (h / 3);
                    }
                    else
                    {
                        price += b * n;
                        n = 0;
                    }
                    if (n >= (e/2))
                    {
                        price += a * (e / 2);
                        n = n - (e / 2);
                    }
                    else
                    {
                        price += a * n;
                        n = 0;
                    }
                    e = e % 2;
                }
            }
            cout << price << endl;
        }

        

    }
    return 0;
}