#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 100
#define MaxValue 1000
using namespace std;

 
//链表节点定义
typedef struct LNode
{   char key;
    int number;
    LNode *next;
}*Link;

//三叉树节点定义
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


//构建空三叉树
void init(huffman *huffmanTree,int *w,char *z,int n)
{
    int i;
    //for(i=0;i<2*n-1;i++)
    //    huffmanTree[i]=(huffman *)malloc(sizeof(huffman));

	//(3n-1)/2) n为奇数时计算节点个数
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

	//3n/2 n为偶数时计算节点个数
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

//构建最优三叉树
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
		//定义m1，m2，m3,的值为1000，作为比较大小交换的载体
        m1=m2=m3=MaxValue;
		//初始化x1，x2，x3
        x1=x2=x3=0;

		//比较最小权值，然后相加
        for(j=0;j<i;++j)
        {
			//交换过程
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

		//偶数个节点时生成双亲节点
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

		//奇数节点时生成双亲节点
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
				//计算双亲节点权值，方便用于循环中进行构建三叉树
				huffmanTree[i].weight=m1+m2+m3;
			}
			else
				huffmanTree[i].weight=m1+m2;
		}
    }
}


void huffmanTreeCode(huffman *huffmanTree,int n)
{
	//定义数组存储树节点的字符
    char hc[Max];
	//叶子节点的012编码长度
    int hcLen;
    int i,j,k,parent,p;

	//先生成叶子节点对应的012编码，然后存储到叶子节点中
    for(i=0;i<n;i++)
    {
        hcLen=0;
		//待编码字符的双亲结点下标
        parent=huffmanTree[i].parent;
        p=i;

        while(parent!=-1)//未到达根结点
        {
            if(huffmanTree[parent].lChild==p)//是左孩子
                hc[hcLen]='0',hcLen++;
            else if(huffmanTree[parent].mChild==p)//是中孩子
                hc[hcLen]='1',hcLen++;
			else if(huffmanTree[parent].rChild==p)//是右孩子
                hc[hcLen]='2',hcLen++;
                p=parent;
                parent=huffmanTree[parent].parent;//继续向根结点查找
		}
	//将编码写入相应字符数组
    for(j=0,k=hcLen-1;j<hcLen;j++,k--)
        huffmanTree[i].hCode[j]=hc[k];
        huffmanTree[i].hCode[j]='\0';//加上字符串结束符
    }

    return;
}


//创建一个新结点
Link CreateNode(void)
{
	//初始化链表节点
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
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream;//源文件
	in_stream>>noskipws;
    ofstream out_stream;//输出文件
    in_stream.open("Source.txt");
    //打开源文件错误
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //打开输出文件错误
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //遍历文件，依次读取每个字符
    while(in_stream>>c)
    {
        flag=true;//标志c不存在于链表中
        //遍历链表，判断c是否已经存在于链表中
        for(current=head;current!=NULL;current=current->next)
        {
            //c已经存在，c对应的频数加1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag置为false
                break;//跳出for循环
            }

        }
        if(flag)
        {
            //c不存在，创建新结点
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
    //cout<<"The result:"<<endl;//控制台输出
    //输出至输出文件
    out_stream<<"字母"<<"\t频数"<<endl;
    //遍历链表，分别输出至控制台和文件中
    for(current=head;current!=NULL;current=current->next)
    {
        //cout<<current->key<<' '<<current->number<<'\n';
        out_stream<<current->key<<"\t"<<current->number<<endl;
		W[i]=current->number;
        i++;
    }
	return W;
    //关闭流
    in_stream.close();
    out_stream.close();
    //释放链表空间
    for(current=head;current!=NULL;current=current->next)
        delete current;
    
}

int Count()
{
	char c;
    bool flag;
	int i = 0;
	
    int W[Max];
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream;//源文件
	in_stream>>noskipws;//读空格
    ofstream out_stream;//输出文件
    in_stream.open("Source.txt");
    //打开源文件错误
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //打开输出文件错误
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //遍历文件，依次读取每个字符
    while(in_stream>>c)
    {
        flag=true;//标志c不存在于链表中
        //遍历链表，判断c是否已经存在于链表中
        for(current=head;current!=NULL;current=current->next)
        {
            //c已经存在，c对应的频数加1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag置为false
                break;//跳出for循环
            }

        }
        if(flag)
        {
            //c不存在，创建新结点
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
    //cout<<"The result:"<<endl;//控制台输出
    //输出至输出文件
    out_stream<<"字母"<<"\t频数"<<endl;
    //遍历链表，分别输出至控制台和文件中
    for(current=head;current!=NULL;current=current->next)
    {
        out_stream<<current->key<<"\t"<<current->number<<endl;
		W[i]=current->number;
        i++;
    }
	return i;
    //关闭流
    in_stream.close();
    out_stream.close();
    //释放链表空间
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
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream;//源文件
	in_stream>>noskipws;
    ofstream out_stream;//输出文件
    in_stream.open("Source.txt");
    //打开源文件错误
    if(in_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    out_stream.open("Output.txt");
    //打开输出文件错误
    if(out_stream.fail())
    {
        cout<<"inserting to the file is failing";
        exit(1);
    }
    //遍历文件，依次读取每个字符
    while(in_stream>>c)
    {
        flag=true;//标志c不存在于链表中
        //遍历链表，判断c是否已经存在于链表中
        for(current=head;current!=NULL;current=current->next)
        {
            //c已经存在，c对应的频数加1
            if(current->key==c)
            {
				
				
                current->number++;
                flag=false;//flag置为false
                break;//跳出for循环
            }

        }
        if(flag)
        {
            //c不存在，创建新结点
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
    //cout<<"The result:"<<endl;//控制台输出
    //输出至输出文件
    out_stream<<"字母"<<"\t频数"<<endl;
    //遍历链表，分别输出至控制台和文件中
    for(current=head;current!=NULL;current=current->next)
    {
		//cout<<current->key<<' '<<current->number<<'\n';
        out_stream<<current->key<<"\t"<<current->number<<endl;
        Z[i]=current->key;
		W[i]=current->number;
        i++;
		
    }
	return Z;
    //关闭流
    in_stream.close();
    out_stream.close();
    //释放链表空间
    for(current=head;current!=NULL;current=current->next)
        delete current;
    
}


	
