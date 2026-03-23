#include<iostream>
int main(){
	int n;
	std::cin>>n;
	for(int i=0;i<=n;i++){
		if(1<<i==n){
			std::cout<<'A';
			break;
		}
		else if(1<<i>n){
			std::cout<<'B';
			break;
		}
		
	}
	
}