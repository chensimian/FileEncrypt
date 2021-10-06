#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 1250
#define MaxValue 2000000
using namespace std;


//�����㶨��
typedef struct LNode
{   char key;
    int number;
    LNode *next;
}*Link;

//����һ���½��
Link CreateNode(void)
{
	//��ʼ��������
    Link newnode =(LNode*)malloc(sizeof(LNode));
    if(newnode!=NULL)
    {
        newnode->number=0;
        newnode->next=NULL;
    }
    return newnode;
}

int *Number(string fileName) 
{
    char c;
    bool flag;
	int i = 0;
	
    static int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream(fileName.c_str());//Դ�ļ�
	in_stream>>noskipws;
    ofstream out_stream;//����ļ�
    in_stream.is_open();
    //��Դ�ļ�����
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //������ļ�����
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //�����ļ������ζ�ȡÿ���ַ�
    while(in_stream>>c)
    {
        flag=true;//��־c��������������
        //���������ж�c�Ƿ��Ѿ�������������
        for(current=head;current!=NULL;current=current->next)
        {
            //c�Ѿ����ڣ�c��Ӧ��Ƶ����1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag��Ϊfalse
                break;//����forѭ��
            }

        }
        if(flag)
        {
            //c�����ڣ������½��
            Link newnode=CreateNode();
            newnode->key=c;
            newnode->number++;
            newnode->next=head;
            head=newnode;
        }
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
    }
    //cout<<"The result:"<<endl;//����̨���
    //���������ļ�
    out_stream<<"��ĸ"<<"\tƵ��"<<endl;
    //���������ֱ����������̨���ļ���
    for(current=head;current!=NULL;current=current->next)
    {
        //cout<<current->key<<' '<<current->number<<'\n';
        out_stream<<current->key<<"\t"<<current->number<<endl;
		W[i]=current->number;
        i++;
    }
	return W;
    //�ر���
    in_stream.close();
    out_stream.close();
    //�ͷ�����ռ�
    for(current=head;current!=NULL;current=current->next)
        delete current;
    
}

int Count(string fileName)
{
	char c;
    bool flag;
	int i = 0;
	
    int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream(fileName.c_str());//Դ�ļ�
	in_stream>>noskipws;//���ո�
    ofstream out_stream;//����ļ�
    in_stream.is_open();
    //��Դ�ļ�����
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //������ļ�����
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //�����ļ������ζ�ȡÿ���ַ�
    while(in_stream>>c)
    {
        flag=true;//��־c��������������
        //���������ж�c�Ƿ��Ѿ�������������
        for(current=head;current!=NULL;current=current->next)
        {
            //c�Ѿ����ڣ�c��Ӧ��Ƶ����1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag��Ϊfalse
                break;//����forѭ��
            }

        }
        if(flag)
        {
            //c�����ڣ������½��
            Link newnode=CreateNode();
            newnode->key=c;
            newnode->number++;
            newnode->next=head;
            head=newnode;
        }
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
    }
    //cout<<"The result:"<<endl;//����̨���
    //���������ļ�
    out_stream<<"��ĸ"<<"\tƵ��"<<endl;
    //���������ֱ����������̨���ļ���
    for(current=head;current!=NULL;current=current->next)
    {
        out_stream<<current->key<<"\t"<<current->number<<endl;
		W[i]=current->number;
        i++;
    }
	return i;
    //�ر���
    in_stream.close();
    out_stream.close();
    //�ͷ�����ռ�
    for(current=head;current!=NULL;current=current->next)
        delete current;
	
}


char *Word(string fileName) 
{
    char c;
    bool flag;
	int i = 0;
	static char Z[Max];
    int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream(fileName.c_str());//Դ�ļ�
	in_stream>>noskipws;
    ofstream out_stream;//����ļ�
    in_stream.is_open();
    //��Դ�ļ�����
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //������ļ�����
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //�����ļ������ζ�ȡÿ���ַ�
    while(in_stream>>c)
    {
        flag=true;//��־c��������������
        //���������ж�c�Ƿ��Ѿ�������������
        for(current=head;current!=NULL;current=current->next)
        {
            //c�Ѿ����ڣ�c��Ӧ��Ƶ����1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag��Ϊfalse
                break;//����forѭ��
            }

        }
        if(flag)
        {
            //c�����ڣ������½��
            Link newnode=CreateNode();
            newnode->key=c;
            newnode->number++;
            newnode->next=head;
            head=newnode;
        }
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
    }
    //cout<<"The result:"<<endl;//����̨���
    //���������ļ�
    out_stream<<"��ĸ"<<"\tƵ��"<<endl;
    //���������ֱ����������̨���ļ���
    for(current=head;current!=NULL;current=current->next)
    {
		//cout<<current->key<<' '<<current->number<<'\n';
        out_stream<<current->key<<"\t"<<current->number<<endl;
        Z[i]=current->key;
		W[i]=current->number;
        i++;
		
    }
	return Z;
    //�ر���
    in_stream.close();
    out_stream.close();
    //�ͷ�����ռ�
    for(current=head;current!=NULL;current=current->next)
        delete current;
    
}