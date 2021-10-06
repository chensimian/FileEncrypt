#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 100
#define MaxValue 1000
using namespace std;

 
//����ڵ㶨��
typedef struct LNode
{   char key;
    int number;
    LNode *next;
}*Link;

//�������ڵ㶨��
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

	//(3n-1)/2) nΪ����ʱ����ڵ����
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

	//3n/2 nΪż��ʱ����ڵ����
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

		//ż�����ڵ�ʱ����˫�׽ڵ�
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

		//�����ڵ�ʱ����˫�׽ڵ�
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
				//����˫�׽ڵ�Ȩֵ����������ѭ���н��й���������
				huffmanTree[i].weight=m1+m2+m3;
			}
			else
				huffmanTree[i].weight=m1+m2;
		}
    }
}


void huffmanTreeCode(huffman *huffmanTree,int n)
{
	//��������洢���ڵ���ַ�
    char hc[Max];
	//Ҷ�ӽڵ��012���볤��
    int hcLen;
    int i,j,k,parent,p;

	//������Ҷ�ӽڵ��Ӧ��012���룬Ȼ��洢��Ҷ�ӽڵ���
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


//����һ���½��
Link CreateNode(void)
{
	//��ʼ������ڵ�
    Link newnode =(LNode*)malloc(sizeof(LNode));
    if(newnode!=NULL)
    {
        newnode->number=0;
        newnode->next=NULL;
    }
    return newnode;
}
 
int *Number() 
{
    char c;
    bool flag;
	int i = 0;
	
    static int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream;//Դ�ļ�
	in_stream>>noskipws;
    ofstream out_stream;//����ļ�
    in_stream.open("Source.txt");
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
		/*w[i]=current->number;
		z[i]=current->key;
		i++;*/
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

int Count()
{
	char c;
    bool flag;
	int i = 0;
	
    int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream;//Դ�ļ�
	in_stream>>noskipws;//���ո�
    ofstream out_stream;//����ļ�
    in_stream.open("Source.txt");
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
		/*w[i]=current->number;
		z[i]=current->key;
		i++;*/
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


char *Word() 
{
    char c;
    bool flag;
	int i = 0;
	static char Z[Max];
    int W[Max];
    Link head=NULL;//ͷָ��
    Link current=head;//��ǰ���
    
	ifstream in_stream;//Դ�ļ�
	in_stream>>noskipws;
    ofstream out_stream;//����ļ�
    in_stream.open("Source.txt");
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
		/*w[i]=current->number;
		z[i]=current->key;
		i++;*/
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


	
