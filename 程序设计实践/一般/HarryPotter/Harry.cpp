#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
//#include <ctime>
using namespace std;
int is_h(char ch[],int len);
int main() {
    ifstream fin;
    char** s;
    //�������ص��߱���
    s = new char *[7];
    s[1] = "harry0.txt";
    s[0] = "harry1.txt";    
    char m[20];
    while(scanf("%s",&m) == 1){  
		//int t1=clock();    
    	int len = strlen(m);
    	char ch[len];
    	int j = 1;
    	int sum = 0;	
    	int chap = 0;	//�½�  	
    	int ye=1;		//ҳ��
    	int po[2000];
    	cout<<"���"<<'\t'<<"����/����"<<'\t'<<'\t'<<"�½�"<<'\t'<<"ҳ��"<<'\t'<<"����"<<endl;
        for(int i=0;i<=0;i++){
        	fin.open(s[i]);
        	while(fin.get(ch,len+1,EOF) && fin.eof() == false){
        		
        		if(strncmp(ch,"CHAPTER",len) == 0){
        			chap++;
        			fin.seekg(-len+1,ios::cur);
				} 
				else if( is_h(ch,len) ) {										
					ye++;					
				}   		
        		else if(strncmp(ch,m,len)==0){
        			cout<< j << '\t' << ch 
						<< '\t' << '\t' << '\t' 
						<< chap << '\t'<< ye <<'\t'<< s[i] << endl;
					po[j-1]= fin.tellg()-len; 
        			j++;
        			sum++;  					    			
				}				
				else 
					fin.seekg(-len+1,ios::cur);
			}			
        	fin.clear();
        	fin.close();
        	
        }        
        
		cout<<"һ���� "<< sum << "���������"<<endl; 
        cout<<"����Ҫ���ҵĵ�n��������ڶ���"<<endl; 
        //���ڲ���ʱ��
		//int t2=clock();
        //cout<<t2-t1;       
        int n;
        char ch2[100];
        while( scanf("%d",&n) == 1) {
        	if(n>sum) {
        		cout<<"�������,����������"<<endl;
				continue; 
			}
			//ʵ�ʸ������ȷ���򿪵��ǵڼ�����s[i]
        	fin.open(s[0]);
        	fin.seekg(po[n-1],ios::beg);
        	fin.get(ch2[0]);
        	while(ch2[0] != '\n') {
        		fin.seekg(-2,ios::cur);
        		fin.get(ch2[0]);
			}        	
			while(fin.get(ch2,100) ) {
				cout<<ch2;	
			}
						
		}     
			
		// ѭ�� ������ѯ����� 
        cout<<"�����������һ����ѯ?"<<endl;
    }  
}
int is_h(char ch[], int len) {
	for(int i = 0 ;i < len-1 ;i++) {
		if(ch[i] == '\n' && (ch[i+1] >= '0' && ch[i+1] <= '9')) {
			return i+1;
		}
	}
	return 0;
}
