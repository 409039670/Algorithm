#include <iostream>
#include <stdlib.h>
#include<algorithm>
#include <ctime>

using namespace std;
int num = 0  ;

void ramdom(int arr[],int n)
{
   srand ( time(0)) ;
   for ( int i = 0 ; i < n ; i++ )
   {
       arr[i] = rand() %1000 ;
   }
}
//��������
void QuickSort ( int a[] , int low , int high    )
{
    int  i = low , j = high ;
    int  temp = a[low] ;

    while ( i < j )
    {
        while (  i < j && temp <= a[j] )
         {
              j -- ; num ++ ;
         }
        if ( i < j )
        {
            a[i] =a[j] ;
            num += 3 ;
            i ++ ;
        }
        while (  i < j && temp >= a[i])
           {
               i ++ ; num ++ ;
           }
        if ( i < j )
        {
            a[j] = a[i];
            num += 3 ;
            j -- ;
        }
        a[i] = temp ;
        num ++ ;
        if ( low < i )
            QuickSort( a , low , i-1  ) ;
        if ( i < high )
            QuickSort ( a , j +1 , high  ) ;
    }

}
int main()
{
    int  k ;
    int InsertSort ( int a[] , int n );
    int s[100] ;
    for ( int i = 0 ; i < 5  ; i ++ )
    {
     ramdom(s,100) ;
    cout <<"��"<<i+1<<"�β���"<<endl<<"���ɵ�100λ�����Ϊ��" ;
    for ( int  i = 0 ; i < 100 ; i ++ )
    {
      cout << s[i] << " ";
    }
    cout << endl;
    k = InsertSort( s , 100 ) ;
    QuickSort(s,0,100) ;
    cout <<"���ɵ���������Ϊ"<<endl ;
    for ( int  i = 0 ; i < 100 ; i ++ )
    {
      cout << s[i] << " ";
    }
    cout <<endl <<"���������ƶ�����Ϊ"<<num <<"�Σ�ֱ�Ӳ���������ƶ�����Ϊ"<<k << "��."<<endl<<endl ;
    }

 return 0;
}

//ֱ�Ӳ�������

int InsertSort ( int a[] , int n )
{
    int  j ,temp = 0 ;
    int *b = a ;
    for ( int i = 1 ; i < n ; i ++ )
    {
       for (  j = i - 1 ; j >=0  && b[j] > b[j+1] ; j -- )
       {
          swap(b[j] ,b[j+1]) ;
          temp += 3 ;
       }
    }
    return temp ;
}


//ϣ������

void XESort ( int a[] , int n )
{
   int i , j , gap ;
   for ( gap = n / 2 ; gap > 0 ; gap /= 2 )
   {
       for ( i = gap ; i < n ; i ++ )
       {
           for ( j = i - gap ; j >= 0 && a[j] > a[j+gap] ; j -= gap )
           {
               swap ( a[j] , a[j+gap]) ;
           }
       }
   }
}
*/

//ֱ��ѡ������

void ChooseSort ( int a[] , int n )
{
    int temp  ;
    for ( int i = 0 ; i < n - 1 ; i ++ )
    {
        temp = i ;
        for ( int j = i+1 ; j < n ; j ++  )
        {
            if ( a[j] < a[temp] )
            {
                 temp = j ;
            }
        }
        if ( temp != i )
        {
            swap ( a[i] ,a[temp]) ;
        }

    }
}
*/

//ð������

void MPSort ( int a[] , int n )
{
    int i , j , flag = 1 ;
    for ( i = 0 ; i < n && flag == 1 ; i ++ )
    {
        flag = 0 ;
        for ( j = 0 ; j < n-i ; j ++ )
        {
            if ( a[j] > a[j + 1] )
            {
                flag = 1 ;
                swap ( a[j] , a[j+1]) ;
            }
        }
    }
}













