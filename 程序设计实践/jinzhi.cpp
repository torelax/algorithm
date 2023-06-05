#include<iostream>
#include<cstring> 
using namespace std ;
int main(){
	char nub[100] ;
	int nub2[100] ;
	cin >> nub ;
	int m = strlen(nub) ;
	for(int j = 0 ; j < m ; j++){
		nub2[j] = nub[j]-48 ;
	}
	int sum = 0 ;
	if(nub2[0] == 0)
		for(int i = 0 ; i < m ; i++){
			sum += ( nub2[i] << (m-i-1) ) ;
		}
	else{
		for( int i=1 ; i < m ; i++ ){
			sum += ( nub2[i] << (m-i-1) ) ;
		}
		sum = sum - ( 1 << (m-1) ) ;
	}
	cout << sum ;
}
