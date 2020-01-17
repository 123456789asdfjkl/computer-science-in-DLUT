#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class cLink
{
    friend class cList;
    cLink *next;
    char name[20];//����
    int number;//ѧ��
    char sex[5];//�Ա�
    char birth[10];//��������
    int chinese;//���ĳɼ�
    int math;//��ѧ�ɼ�
    int english;//Ӣ��ɼ�
    int sum;//�ܳɼ�
public:
    cLink(){

    }
    cLink(char a[],int b,char c[], char d[], int e,int f,int g)
    {
        strcpy(name,a);
        number=b;
        strcpy(sex,c);
        strcpy(birth,d);
        chinese=e;
        math=f;
        english=g;
        sum=e+f+g;
    }

    cLink *get_next(void)
    {
        return(next);
    }

    void print(void)
    {
        cout<<name<<"\t"<<number<<"\t"<<sex<<"\t"<<birth<<"\t "<<chinese<<"\t          "<<math<<"         \t"<<english<<"        \t"<<sum<<"   \n";
    }

};
class cList
{
protected:
    cLink *first;
    cLink *last;
public:
    cList(void)
    {
        first=last=new cLink;
    }
    ~cList()
    {
        Clear();
        delete first;
    }
    cList& Insert(const cLink &x);
    void Delete(char x[]);
    void Delete(int x);
    cList& Clear(void);
    void Find(char x[]);
    void Find(int x);
    void Max_and_Min(void);
    int Count(void);
    void Sort(void);
    void Disp(void);
};
cList& cList::Insert(const cLink &x) {
    cLink *ptr=first;
    first=new cLink;
    *first=x;
    first->next=ptr;
    return *this;
}
//  ѧ��Ψһ��˲������ظ�
void cList::Delete(int x) {
    cLink *ptr=first;
    cLink *ptr1;
    if (first!=last) {
        if (ptr->number==x)
        {
            first=first->next;
            ptr1=ptr;
            delete(ptr1);
        } else {
            ptr = ptr->next;
            ptr1 = first;
            while (ptr != last) {
                if (ptr->number == x) {
                    ptr1->next = ptr->next;
                    delete(ptr);
                    break;
                }
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }
        }
    }
    cout<<"ɾ������б�:\n";
    cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
    Disp();
}
//  ������Ψһ��������������˿��Ƕ��
void cList::Delete(char x[]) {
    cLink *ptr=first;
    cLink *ptr1;
    if (first!=last) {
        if (!(strcmp(ptr->name,x)))
        {
            first=first->next;
            ptr1=ptr;
            delete(ptr1);
        } 
        ptr = ptr->next;
        ptr1 = first;
        while (ptr != last) {
            if (!(strcmp(ptr->name,x))) {
                ptr1->next = ptr->next;
                delete(ptr);
            }
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
    
    }
    cout<<"ɾ������б�:\n";
    cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
    Disp();
}
cList& cList::Clear() {
    cLink *ptr=first;
    while(ptr!=last){
        cLink *next=ptr->next;
        delete(ptr);
        ptr=next;
    }
    first=last;
    return *this;
}
//  ѧ��Ψһ��˲������ظ�
void cList::Find(int x) {
    cLink *ptr=first;
    cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
    while (ptr != last) {
        if (ptr->number == x) {
            ptr->print();
            break;
        }
        ptr = ptr->next;
    }
}
//  ������Ψһ��������������˿��Ƕ��
void cList::Find(char x[]) {
    cLink *ptr=first;
    cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
    while (ptr != last) {
        if (!(strcmp(ptr->name,x))) {
        	
            ptr->print();
        }
        ptr = ptr->next;
    }
}
void cList::Max_and_Min() {
    cLink *ptr=first;
    cLink *max,*min;
    if (ptr!=last){
        max=min=ptr;
        ptr=ptr->next;
        while (ptr!=last){
            if(ptr->sum>max->sum){
                max=ptr;
            }
            if (ptr->sum<min->sum){
                min=ptr;
            }
            ptr=ptr->next;
        }
        cout<<"���ѧ���ɼ���Ϣ���£�\n";
        cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
        max->print();
        cout<<"���ѧ���ɼ���Ϣ���£�\n";
        cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
        min->print();

    } else{
        cout<<"��Ϊ�գ������������Сֵ\n";
    }
}

int cList::Count() {
    int count=0;
    cLink *ptr=first;
    while(ptr!=last){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void cList::Sort() {
    int count=Count();
    cLink *ptr1,*ptr2,*ptr3,*ptr;
    ptr1=first;
    ptr2=first->next;
    while(count) {
    	ptr1=first;
    	ptr2=first->next;
        if (ptr2 != last) {
            if (ptr1->sum < ptr2->sum) {
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
                first = ptr2;
            }
        }
        ptr3 = first;
        ptr1 = first->next;
        ptr2 = ptr1->next;
        while (ptr2 != last) {
            if (ptr1->sum < ptr2->sum) {
                ptr3->next = ptr1->next;
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
                ptr = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        count--;
    }
    ptr=first;
    cout<<"������ѧ���ɼ���Ϣ:\n";
    Disp();
}
void cList::Disp() {
    cLink *ptr=first;
    cout<<"����\t"<<"ѧ��\t"<<"�Ա�\t"<<"����������\t"<<"���ĳɼ�\t"<<"��ѧ�ɼ�\t"<<"Ӣ��ɼ�\t"<<"�ܳɼ�\n";
    while (ptr!=last){
        ptr->print();
        ptr=ptr->next; 
    }
}
void biao(){
    cout<<" ----------------------------------------------------------------\n";
    cout<<"|\t0.����ѧ����Ϣ                                            |\n";
    cout<<"|\t1.���ݸ�����ѧ��������ѧ��ɾ����ѧ���ڵ�                  |\n";
    cout<<"|\t2.���ݸ�����ѧ��������ѧ�Ų���ѧ����Ϣ������ʾ����        |\n";
    cout<<"|\t3.���Ҳ���ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ                    |\n";
    cout<<"|\t4.ͳ�������е�ѧ������                                    |\n";
    cout<<"|\t5.������ڵ㰴�ܳɼ��Ӹߵ�������                          |\n";
    cout<<"|\t6.��ʾѧ��ȫ����Ϣ                                        |\n";
    cout<<"|\t7.�˳�                                                    |\n";
    cout<<" ----------------------------------------------------------------\n";
}
int main()
{
    cList list;
    int a;
    int b;
    int count;
    char name1[20];
    int number1;
    char name[20];//����
    int number;//ѧ��
    char sex[5];//�Ա�
    char birth[10];//��������
    int chinese;//���ĳɼ�
    int math;//��ѧ�ɼ�
    int english;//Ӣ��ɼ�
    int sum;//�ܳɼ�
    int flag;
    while(1){
        biao();
        cout<<"��ѡ������Ҫ�Ĳ���:";
        cin>>a;
        if(a>=0&&a<=7){
            switch (a){
                case 0:
                    cout<<"����������:";
                    cin>>name;
                    cout<<"������ѧ��:";
                    cin>>number;
                    cout<<"�������Ա�:";
                    cin>>sex;
                    cout<<"��������������գ�";
                    cin>>birth;
                    cout<<"���������ĳɼ�:";
                    cin>>chinese;
                    cout<<"��������ѧ�ɼ�:";
                    cin>>math;
                    cout<<"������Ӣ��ɼ�:";
                    cin>>english;
                    list.Insert(cLink(name,number,sex,birth,chinese,math,english));
                    break;
                case 1:
                    cout<<"��ѡ��1.��������2.��ѧ�ţ���";
                    cin>>b;
                    switch (b){
                        case 1:
                            cout<<"������Ҫɾ��������:";
                            cin>>name1;
                            list.Delete(name1);
                            break;
                        case 2:
                            cout<<"������Ҫɾ����ѧ��:";
                            cin>>number1;
                            list.Delete(number1);
                            break;
                    }
                    break;
                case 2:
                    cout<<"��ѡ��1.��������2.��ѧ�ţ���";
                    cin>>b;
                    switch (b){
                        case 1:
                            cout<<"������Ҫ�鿴������:";
                            cin>>name1;
                            list.Find(name1);
                            break;
                        case 2:
                            cout<<"������Ҫ�鿴��ѧ��:";
                            cin>>number1;
                            list.Find(number1);
                            break;
                    }
                    break;
                case 3:
                    list.Max_and_Min();
                    break;
                case 4:
                    count=list.Count();
                    cout<<"�����е�ѧ������Ϊ"<<count<<"��\n";
                    break;
                case 5:
                    list.Sort();
                    break;
                case 6:
                    list.Disp();
                    break;
                case 7:
                    flag=1;
                    break;
            }
            if(flag){
                break;
            }
        } else{
            cout<<"�������";
        }

    }
    return 0;
}


