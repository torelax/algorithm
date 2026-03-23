//number 1
/* la - lb -> la
void Union(List *La, List *Lb)	
{
    int i ,k ;	  
    datatype x;
    for (i = 0; i < ListLength(Lb); i++) {     //ListLength获取线性表长度
        x = GetElem(Lb , i);  
        k = LocateElem(La, x);              //x在La中的位置
        ListDel(La,k);
    }    
} 
*/
//number 2la jiao lb ->Lc
/*void anq(List *La, List *Lb, List *Lc)	
{
    ListInit(Lc);
    int i ,k ;	  
    datatype x;
    for (i = 0; i < ListLength(Lb); i++) {     //ListLength获取线性表长度
        x = GetElem(Lb , i);  
        k = LocateElem(La, x);              //表中是否有x
        if ( k != -1 ) 
            ListInsert(Lc, ListLength(Lc), x);
    }    
}*/