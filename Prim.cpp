#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#define infinite 0
#define point_max_num  10
typedef int graph[point_max_num][point_max_num];

int Prim( graph g, int n , int* line )
{
    int symbol[n];
    int min_d = g[1][0] , a = 2 ,road = 0;
    int t1 , t2  , temp;
    for ( int i = 0 ; i < n ; i ++ )
            symbol[i] = -1 ;
    for ( int i = 1 ; i < n-1 ; i ++ )
        for ( int j = 0 ; j <= i ; j ++ )
        {
            if ( g[i][j] < min_d && g[i][j])
            {
                min_d = g[i][j] ;
                symbol[1] = i ;
                symbol[0] = j ;
            }
        }
    line[0]= symbol[1] ;
    line[1] = symbol[0] ;
    road += g[symbol[1]][symbol[0]];
    g[symbol[1]][symbol[0]] =  0 ;
    g[symbol[0]][symbol[1]] = 0 ;
    int k = 2 ;
    while ( k< n )
    {
        temp = 999999;
        for ( int i = 0 ; i < k ; i ++ )
           for ( int  j = 0 ; j < n ; j ++ )
           {
               if ( g[symbol[i]][j] && g[symbol[i]][j] < temp )
               {
                   temp = g[symbol[i]][j] ;
                   symbol[k] = j ;
                   t1 = symbol[i] ;
                   t2 = j ;
               }
           }
        line[a++] = t1 ;
        line[a++] =t2 ;
        road +=g[t1][t2];
        k = k + 1 ;
        for (int i = 0 ; i < k ; i ++ )
        {
            for ( int j = 0 ; j < k ; j ++ )
            {
                if ( g[symbol[i]][symbol[j]])
                    g[symbol[i]][symbol[j]] = 0 ;
            }
        }
    }
    return road;
}

int main()
{
    FILE *fr;
    int i,j,weight,n;
    int distance ;
    graph G;
    for(i = 0 ; i < point_max_num ; i ++ )
        for(j = 0 ; j < point_max_num ; j ++ )
            G[i][j] = infinite;
    fr = fopen("prim.txt","r");
    if(!fr)
    {
        printf("fopen failed\n");
        exit(1);
    }
    fscanf(fr,"%d",&n);
    int line[2*n];
    while(fscanf(fr,"%d%d%d", &i, &j, &weight) != EOF)
    {
        G[i-1][j-1] = weight;
        G[j-1][i-1] = weight;
    }
    cout <<n<<endl;
    for(i = 0 ; i < n ; i ++ )
    {
        for(j = 0 ; j < n ; j ++ )
            cout <<G[i][j]<<" ";
        cout <<endl;
    }
    cout << endl ;
    distance = Prim(G,n,line);
    cout << "最小生成树为"<<endl;
    for ( int i = 0 ; i < n-1; i ++ )
    {
        cout <<line[2*i]+1<<"----"<<line[2*i+1]+1<<endl;
    }
    cout <<endl<<"最小权重为"<<distance <<endl ;
    return 0;
}
/*  prim.txt
6
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
5 6 6
4 6 2
*/