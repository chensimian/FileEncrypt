#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 800
#define MaxValue 200000
using namespace std;
#include"Count.h"

//��������㶨��
typedef struct huffNode
{
    char ch;
    int weight;
    int lChild;
	int mChild;
    int rChild;
    int parent;
    char hCode[Max];
}huffman;


//������������
void init(huffman *huffmanTree,int *w,char *z,int n)
{
    int i;
    //for(i=0;i<2*n-1;i++)
    //    huffmanTree[i]=(huffman *)malloc(sizeof(huffman));

	//(3n-1)/2) nΪ����ʱ���������
	if(n%2 == 1)
	{
		for(i=0;i<(3*n-1)/2;i++)
		{
			huffmanTree[i].ch=z[i];
			huffmanTree[i].weight=w[i];
			huffmanTree[i].parent=-1;
			huffmanTree[i].lChild=-1;
			huffmanTree[i].mChild=-1;
			huffmanTree[i].rChild=-1;
		}
	}

	//3n/2 nΪż��ʱ���������
	else
	{
		for(i=0;i<(3*n)/2;i++)
		{
			huffmanTree[i].ch=z[i];
			huffmanTree[i].weight=w[i];
			huffmanTree[i].parent=-1;
			huffmanTree[i].lChild=-1;
			huffmanTree[i].mChild=-1;
			huffmanTree[i].rChild=-1;
		}
	}

}

//��������������
void setHuffmanTree(huffman *huffmanTree,int n)
{
    int m,m1,m2,m3,x1,x2,x3,i,j;
	if(n%2 == 1)
	{
		m=(3*n-1)/2;
	}
	else
		m=3*n/2;
    for(i=n;i<m;++i)
    {
		//����m1��m2��m3,��ֵΪ1000����Ϊ�Ƚϴ�С����������
        m1=m2=m3=MaxValue;
		//��ʼ��x1��x2��x3
        x1=x2=x3=0;

		//�Ƚ���СȨֵ��Ȼ�����
        for(j=0;j<i;++j)
        {
			//��������
            if(huffmanTree[j].parent==-1&&huffmanTree[j].weight<m1)
            {
                m2=m1;
				x2=x1;
				m1=huffmanTree[j].weight;
				x1=j;
            }
            else if (huffmanTree[j].parent==-1&&huffmanTree[j].weight<m2)
            {    
				m2=huffmanTree[j].weight;
				x2=j;
            }
			else if (huffmanTree[j].parent==-1&&huffmanTree[j].weight<m3)
            {    
				m3=huffmanTree[j].weight;
				x3=j;
            }
        }

		//ż�����ڵ�ʱ����˫�׽��
		if(n%2 == 1)
		{
			huffmanTree[x1].parent=i;
			huffmanTree[x2].parent=i;
			huffmanTree[x3].parent=i;
			huffmanTree[i].lChild=x1;
			huffmanTree[i].mChild=x2;
			huffmanTree[i].rChild=x3;
			huffmanTree[i].weight=m1+m2+m3;
		}

		//�����ڵ�ʱ����˫�׽��
		else
		{
			huffmanTree[x1].parent=i;
			huffmanTree[x2].parent=i;
			huffmanTree[x3].parent=i;
			huffmanTree[i].lChild=x1;
			huffmanTree[i].mChild=x2;
			huffmanTree[i].rChild=x3;
			if(n!=m-1)
			{
				//����˫�׽��Ȩֵ����������ѭ���н��й���������
				huffmanTree[i].weight=m1+m2+m3;
			}
			else
				huffmanTree[i].weight=m1+m2;
		}
    }
}


void huffmanTreeCode(huffman *huffmanTree,int n)
{
	//��������洢�������ַ�
    char hc[Max];
	//Ҷ�ӽڵ��012���볤��
    int hcLen;
    int i,j,k,parent,p;

	//������Ҷ�ӽ���Ӧ��012���룬Ȼ��洢��Ҷ�ӽ����
    for(i=0;i<n;i++)
    {
        hcLen=0;
		//�������ַ���˫�׽���±�
        parent=huffmanTree[i].parent;
        p=i;

        while(parent!=-1)//δ��������
        {
            if(huffmanTree[parent].lChild==p)//������
                hc[hcLen]='0',hcLen++;
            else if(huffmanTree[parent].mChild==p)//���к���
                hc[hcLen]='1',hcLen++;
			else if(huffmanTree[parent].rChild==p)//���Һ���
                hc[hcLen]='2',hcLen++;
                p=parent;
                parent=huffmanTree[parent].parent;//�������������
		}
	//������д����Ӧ�ַ�����
    for(j=0,k=hcLen-1;j<hcLen;j++,k--)
        huffmanTree[i].hCode[j]=hc[k];
        huffmanTree[i].hCode[j]='\0';//�����ַ���������
    }

    return;
}

void encode(huffman *huffmanTree,int n)
{
	char c;
	string fileName;
	cout<<"������������ļ�����"<<endl;
	cin>>fileName;
	ifstream in_stream(fileName.c_str());//Դ�ļ�
	in_stream>>noskipws;
	in_stream.is_open();
	ofstream out_stream;//����ļ�
	out_stream.open("Code.txt");
	/*for(int i =0;i<n;i++)
	{
		cout<<huffmanTree[i].ch<<"\t"<<huffmanTree[i].hCode<<endl;
	}*/
	//������ļ�����
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //��Դ�ļ�����
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
	while(in_stream>>c)
	{
		for(int j = 0;j < n;j++)
		{
			if(c == huffmanTree[j].ch)
			{
				out_stream<<huffmanTree[j].hCode;
		
			}
		}
		
	}
	//�ر���
	out_stream.close();	
    //�ͷ�����ռ�
	in_stream.close();
    cout<<"���ܳɹ�"<<endl;
}

void decode(huffman *huffmanTree,int n)
{
	char c;
	string fileName;
	cout<<"������������ļ�����"<<endl;
	cin>>fileName;
	ifstream in_stream(fileName.c_str());//Դ�ļ�
	in_stream.is_open();
	ofstream out_stream;//����ļ�
	out_stream.open("deCode.txt");

	//������ļ�����
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }

	//��Դ�ļ�����
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
	
	string str;
	while(in_stream>>c)
	{
		str+=c;		
		for(int j = 0;j < n;j++)
		{
			string code=huffmanTree[j].hCode;
			if(str==code)
			{
				out_stream<<huffmanTree[j].ch;
				str="";
			}
		}

	}
	//�ر���
	out_stream.close();	
    //�ͷ�����ռ�
	in_stream.close();
	cout<<"���ܳɹ�"<<endl;
}




	
