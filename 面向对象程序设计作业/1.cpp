#include<iostream>
#define R 2
#define C 5
using namespace std;
int Second_Max(int *a)
{
	int j=0;
	int max,second_max;
	max=*(a+j);
	j++;
	while(*(a+j)==max&&j<C)
	{
		j++;
	}
	if(j<C)
	{
		if(*(a+j)>max)
		{
			second_max=max;
			max=*(a+j);
		}
		if(*(a+j)<max)
		{
			second_max=*(a+j);
		}
		for(;j<C;j++)
		{
			if(*(a+j)>max)
			{
				second_max=max;
				max=*(a+j);
			}
			if(*(a+j)<max)
			{
				if(*(a+j)>second_max)
				{
					second_max=*(a+j);
				}
			}
		}
		if(max==second_max)
		{
			cout<<"û�дδ�ֵ"<<endl; 
		}
		else
		{
			cout<<"�δ�ֵΪ:"<<second_max<<endl;
		}
	}
	else
	{
		cout<<"û�дδ�ֵ"<<endl; 
	}
	return 0;
}
int main()
{
	int (*p)[C];
	int i,j;
	p=new int[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cin>>*(*(p+i)+j);
		}
	}
	for(i=0;i<R;i++)
	{
		cout<<"��"<<(i+1)<<"��"; 
		Second_Max(*(p+i));
	}
	return 0;
}
