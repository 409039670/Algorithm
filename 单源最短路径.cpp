#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define Max_Num  70
#define INF  99
int G[Max_Num][Max_Num] ;
int Point[Max_Num] ;

using namespace std;

void least_dis ( int G[Max_Num][Max_Num] , int num , int  a )
{
    int dis[num] ;
    for ( int i = 0 ; i < num ; i ++ )
    {
        if ( i == a )
            dis[i] = 0 ;
        else dis[i] = G[a][i] ;
    }
    for ( int i = 0 ; i <  num  ; i ++ )
    {
        if ( i == a )
            continue ;
        for ( int j = 0 ; j < num  ; j ++)
        {
            if ( dis[i] >= (G[a][j] + G[j][i]))
            {
                dis[i] = G[a][j] + G[j][i] ;
                G[a][i] = dis[i];
                G[i][a] = dis[i];
            }

        }
    }
}

void init ( )
{
    for ( int i = 0 ; i < Max_Num ; i ++ )
        for ( int j = 0 ; j < Max_Num ; j ++ )
            G[i][j] =INF ;
    for ( int i = 0 ; i < Max_Num ; i ++ )
        Point[i] = INF ;
}

int read( FILE * fi)
{
    int s1 , s2 ,s3 , num ;
    int counter = 0 ;
    fi = fopen("graph.txt","r");
    if ( !fi )
    {
        cout << " open file failed !" << endl ;
        exit(1) ;
    }
    fscanf(fi,"%d",&num) ;
    while ( fscanf(fi ,"%d%d%d",&s1,&s2,&s3 ) != EOF)
    {
        if ( Point[s1] == INF)
        {
            Point[s1] = counter ++ ;
            if ( Point[s2] == INF )
            {
                Point[s2] = counter ++ ;

            }
            G[Point[s1]][Point[s2]] = s3 ;
            G[Point[s2]][Point[s1]] = s3 ;
        }
        else
        {
            if ( Point[s2] == INF )
            {
                Point[s2] = counter ++ ;
            }
            G[Point[s1]][Point[s2]] = s3 ;
            G[Point[s2]][Point[s1]] = s3 ;
        }
    }
    for ( int i = 0 ; i < num ; i ++ )
    {
        for ( int j = 0 ; j < num ; j ++ )
            cout << G[i][j]<<"\t" ;
        cout << endl ;
    }
    return num ;
}
int main()
{
    FILE *fi ;
    int  num ;
    init ( ) ;
    num = read( fi );
    for ( int i = 0 ; i < num ; i ++ )
        least_dis(G,num, i);
    cout <<endl <<endl ;
    for ( int i = 0 ; i < num ; i ++ )
    {
        for ( int j = 0 ; j < num ; j ++ )
            cout << G[i][j]<<"\t" ;
        cout << endl ;
    }
    return 0;
}
