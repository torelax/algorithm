#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int igl[n],igr[n],rng[n],g2[n];
	for(int i=0;i<n;i++){
		cin>>igl[i]>>igr[i]>>rng[i]>>g2[i];
	}
	for(int i=0;i<n;i++) {
		if( rng[i] >= g2[i] && rng[i] >= igr[i])
			cout<<"RNG niubility"<<endl;
		else if(rng[i] < g2[i] && rng[i] < igl[i])
			cout<<"Pride makes one retrogress"<<endl;
		else 
			cout<<"impasse"<<endl;
	}
}
