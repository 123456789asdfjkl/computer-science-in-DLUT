#include <iostream>
#include <string.h>
#define max 100
using namespace std;

class stringoperation
{
	private:
		char string[max];
	public:
		stringoperation()
		{
			for (int i = 0; i < max; i++)
				string[i] = '\0';
		}
		void input()
		{
			cout << "������������ַ�����\n";
			cin >> string;
		}
		void operator==(stringoperation &second);
		void exchange()
		{
			bool ascii[2][max];//��һ�м�¼ascii���ֵ���ڶ��м�¼ascii��Сֵ
			char maxchar = string[0], minchar = string[0];
			for (int i = 0; i < 2; i++)
				for (int j = 0; string[j] != '\0'&&j < max; j++)
					ascii[i][j] = false;
			ascii[0][0] = true, ascii[1][0] = true;
			for (int i = 1; string[i] != '\0'&&i < max; i++)
			{
				if (string[i] > maxchar)
				{
					maxchar = string[i];
					for (int j = 0; j < i; j++)
						ascii[0][j] = false;
					ascii[0][i] = true;
				}
				if (string[i] < minchar)
				{
					minchar = string[i];
					for (int j = 0; j < i; j++)
						ascii[1][j] = false;
					ascii[1][i] = true;
				}
				if (string[i] == maxchar)
					ascii[0][i] = true;
				if (string[i] == minchar)
					ascii[1][i] = true;
			}
			for (int i = 0; string[i] != '\0'&&i<max; i++)
			{
				if (ascii[0][i] == true)
					string[i] = minchar;
				if (ascii[1][i] == true)
					string[i] = maxchar;
			}
			cout << "�ַ�����ASCII��������С���ַ�ת����ɣ�\n";
		}
		void disp()
		{
			cout << "�ַ���������£�\n" << string<<"\n";
		}
};

void stringoperation::operator==(stringoperation &second)
{
	if (strcmp(string, second.string) > 0)
		cout << "���ַ�����ASCII��ֵ�ϴ����" << string<<"\n";
	else if (strcmp(string, second.string) < 0)
		cout << "���ַ�����ASCII��ֵ�ϴ����" << second.string<<"\n";
	else
		cout << "���ַ�����ͬ\n";
}

int main()
{
	stringoperation ss1,ss2;
	ss1.input();
	ss1.disp();
	ss2.input();
	ss2.disp();
	ss1 == ss2;
	cout << "������ַ���1����ASCII��ֵ������С���ַ����н�������\n";
	ss1.exchange();
	ss1.disp();
	return 0;
}
