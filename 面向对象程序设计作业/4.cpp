#include <iostream>
#include <string.h>
#define max 100//ÿ���ַ���������ַ���
using namespace std;

class stringoperation
{
private:
	char string[10][max];
public:
	stringoperation()//���캯�� �ַ�������
	{
		cout<<"�����˹��캯������ַ���\n"; 
		for(int i=0;i<10;i++)
			for (int j = 0; j < max; j++)
				string[i][j] = '\0';
	}
	stringoperation(char x[])//�任���캯��
	{
		cout << "���ñ任���캯����"<<endl;
		for (int i = 0; i < 10; i++)
			strcpy(string[i],x);
	}
	stringoperation(const stringoperation &another)//���ƹ��캯��
	{
		cout << "���ø��ƹ��캯����"<<endl;
		for (int i = 0; i < 10; i++)
			strcpy(string[i], another.string[i]);
	}
	void input()//�ַ�������
	{
		char s[80];
		cout << "�����ַ������뺯����"<<endl;
		int i = 0;
		while (1)
		{
			cout << "�������������ַ������(1-10)��";
			cin >> i;
			if (i <= 10 && i >= 1)
				break;
			cout << "�ַ�����Ŵ������������롣"<<endl;
			while(cin.get() != '\n') ;
		}
		cout << "������������ַ�����"<<endl;
		cin >> string[i-1];
	}
	char* asciimin(int minquantity[10])//����asciiֵ��Сֵ����
	{
		cout << "���ò���asciiֵ��Сֵ������" << endl;
		static char min[10];//��¼ÿ���ַ�������Сֵ
		int count;//��¼��Сֵ�ĸ���
		for (int i = 0; i < 10; i++)
		{
			count=1;
			char minchar = string[i][0];
			for (int j = 1; string[i][j] != '\0'&&j < max; j++)
			{
				if (string[i][j] == minchar)
					count++;
				if (string[i][j] < minchar)
				{
					minchar = string[i][j];
					count = 1;
				}
			}
			min[i] = minchar;
			minquantity[i] = count;
		}
		cout << "�ַ���asciiֵ��Сֵ���ַ�������ɣ�"<<endl;
		return min;
	}
	void stringcmp()//�ַ�����С�������к���
	{
		cout << "�����ַ�����С�������к�����" << endl;
		for(int i=0;i<10;i++)
			for (int j = 0; j < i; j++)
			{
				if (strcmp(string[i], string[j]) < 0)
				{
					char temp[max];
					strcpy(temp,string[i]);
					strcpy(string[i],string[j]);
					strcpy(string[j],temp);
				}
			}
	}
	void disp()//�ַ������
	{
		cout << "�����ַ������������" << endl;
		cout << "�ַ���������£�" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (string[i][0] == '\0')
				continue;
			cout << string[i] << endl;
		}
	}
};

int main()
{
	stringoperation ss1;
	ss1.disp();
	for(int i=0;i<10;i++)
		ss1.input();
	ss1.disp();
	cout<<"----------------\n";
	char x[max];
	cout<<"������һ���ַ���:\n";
	cin>>x;
	stringoperation ss2 = x;
	ss2.disp();
	cout<<"----------------\n";
	stringoperation ss3(ss1);
	ss3.disp();
	int minquantity[10];
	char ch[10];
	strcpy(ch,ss3.asciimin(minquantity));
	cout <<"ÿ���ַ�����ascii��Сֵ�ֱ��ǣ�"<< ch << endl;
	cout << "ÿ���ַ�����ascii��Сֵ�����ֱ�Ϊ";
	for (int j = 0; j < 10; j++)
		cout << minquantity[j]<<" ";
	cout << endl;
	ss3.stringcmp();
	ss3.disp();
	return 0;
}
