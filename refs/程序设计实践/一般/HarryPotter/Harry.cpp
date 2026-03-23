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
    //哈利波特的七本书
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
    	int chap = 0;	//章节  	
    	int ye=1;		//页码
    	int po[2000];
    	cout<<"序号"<<'\t'<<"人名/地名"<<'\t'<<'\t'<<"章节"<<'\t'<<"页码"<<'\t'<<"书名"<<endl;
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
        
		cout<<"一共有 "<< sum << "个搜索结果"<<endl; 
        cout<<"输入要查找的第n个结果所在段落"<<endl; 
        //用于测试时间
		//int t2=clock();
        //cout<<t2-t1;       
        int n;
        char ch2[100];
        while( scanf("%d",&n) == 1) {
        	if(n>sum) {
        		cout<<"输入错误,请重新输入"<<endl;
				continue; 
			}
			//实际根据情况确定打开的是第几本即s[i]
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
			
		// 循环 继续查询或结束 
        cout<<"请继续输入下一个查询?"<<endl;
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
