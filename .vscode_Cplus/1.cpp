#include<iostream>
#include <vector>
#include<climits>
#include<ctime>
using namespace std;
void show_array(vector<int> &A)
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
} 
void swap(int *a,int *c)
{
    int b=*a;
    *a=*c;
    *c=b;
    //当函数结束函数的活动记录从栈中弹出，改变的值不会影响实参，
    //用指针可直接操作地址对应的值。
}
void GetRandList(vector<int> &A, int n)
{
	A.resize(n);
	for(int i=0;i<n;i++)
	{
		A[i] = rand()%n;
	}
}

void INSERTION_SORT(vector<int> &A)
{
    // exited with code=0 in 2.574 seconds
    for(int i=1;i<A.size();i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0 and A[j]>key)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
}
int LINEAR_SEARCH(vector<int> &A,int v)
{
    for(int i=0;i<A.size();i++)
        if(A[i]==v)
        return i;
    return -1;
}
void SELECTION_SORT(vector<int> &A)
{
    for(int i=0;i<A.size()-1;i++)
    {
        int MINindex=i;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[j]<A[MINindex])
                MINindex = j;
        }
        swap(A[i],A[MINindex]);
    }
    show_array(A);
}
class MERGEall
{
    public:
    void Merge_sentry(vector<int> &list, int begin1, int begin2, int end)
{
	int n1 = begin2-begin1;
	int n2 = end-begin2+1;
	vector<int> temp1;
	vector<int> temp2;
	temp1.resize(n1+1);
	temp2.resize(n2+1);	
	temp1[n1] = INT_MAX;
	temp2[n2] = INT_MAX;
	for(int i=0;i<n1;i++)
	{
		temp1[i] = list[begin1+i];
	}
	for(int i=0;i<n2;i++)
	{
		temp2[i] = list[begin2+i];
	}
	int i=0;
	int j=0;
	for(int p=begin1;p<=end;p++)
	{
		if(temp1[i]<=temp2[j])
			list[p] = temp1[i++];
		else
			list[p] = temp2[j++];
	}
}
    void MergeSort_sentry(vector<int> &list, int begin, int end)
{
	if(begin<end)
	{
		int mid = (begin+end)/2;
		MergeSort_sentry(list,begin,mid);
		MergeSort_sentry(list,mid+1,end);
		Merge_sentry(list,begin,mid+1,end);
	}
}
    void MERGE(vector<int> &a, int first, int mid, int last, int temp[])
{	
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    while (i <= m && j <= n)
    {		
        if (a[i] <= a[j])
           temp[k++] = a[i++]; 
		else
           temp[k++] = a[j++];  		
    }		
    while (i <= m)
        temp[k++] = a[i++];
	while (j <= n)
        temp[k++] = a[j++];				
    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
    void MERGE_SORT(vector<int> &A,int p,int r,int result[])
{
    if(p<r)
    {
       int q=(p+r)/2;
       MERGE_SORT(A,p,q,result);
       MERGE_SORT(A,q+1,r,result);
       MERGE(A,p,q,r,result);
    }
}
    bool MergeSort(vector<int> &A)
{
	int *p = new int[A.size()];
	if (p == NULL)
		return false;
	MERGE_SORT(A, 1, A.size(), p);
	delete[] p;
	return true;
}
};

int main(int argc, char** argv)
{   
    MERGEall use;    
    vector<int> list;
    GetRandList(list,20);
    show_array(list);
    return 0;
}