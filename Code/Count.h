#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 1250
#define MaxValue 2000000
using namespace std;


//链表结点定义
typedef struct LNode
{   char key;
    int number;
    LNode *next;
}*Link;

//创建一个新结点
Link CreateNode(void)
{
	//初始化链表结点
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
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream(fileName.c_str());//源文件
	in_stream>>noskipws;
    ofstream out_stream;//输出文件
    in_stream.is_open();
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
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
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

int Count(string fileName)
{
	char c;
    bool flag;
	int i = 0;
	
    int W[Max];
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream(fileName.c_str());//源文件
	in_stream>>noskipws;//读空格
    ofstream out_stream;//输出文件
    in_stream.is_open();
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
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
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


char *Word(string fileName) 
{
    char c;
    bool flag;
	int i = 0;
	static char Z[Max];
    int W[Max];
    Link head=NULL;//头指针
    Link current=head;//当前结点
    
	ifstream in_stream(fileName.c_str());//源文件
	in_stream>>noskipws;
    ofstream out_stream;//输出文件
    in_stream.is_open();
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
		//w[i]=current->number;
		//z[i]=current->key;
		//i++;
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