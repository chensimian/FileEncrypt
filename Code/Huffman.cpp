#include"HuffmanTreeLib.h"
#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <string>
#define Max 800
#define MaxValue 2000000
using namespace std;

void init(huffman *huffmanTree,int *w,char *z,int n);
void setHuffmanTree(huffman *huffmanTree,int n);
void huffmanTreeCode(huffman *huffmanTree,int n);
void encode(huffman *huffmanTree,int n);
void decode(huffman *huffmanTree,int n);
Link CreateNode(void);
int *Number(string fileName);
int Count(string fileName);
char *Word(string fileName);
void menu();

int main()
{
	int n;
    char *Z;
    int *W;
	int inNum;
	//char c;
	string fileName;

	bool a=true;
    while(a)
	{
		menu();
		cin>>inNum;
		switch(inNum)
		{
			case 1://选择密码本
				system("cls");
				cout<<"请输入文件名："<<endl;
				cin>>fileName;
				huffman huffmanTree[Max];
				n = Count(fileName);
				W = Number(fileName);
				Z = Word(fileName);
				init(huffmanTree,W,Z,n);
				setHuffmanTree(huffmanTree,n);
				huffmanTreeCode(huffmanTree,n);
				break;
			case 2://加密
				system("cls");
				encode(huffmanTree,n);
				break;
			case 3://解密
				system("cls");
				decode(huffmanTree,n);
				break;
			default:a=false;
		}
	}
	
    return 0;
}

void menu()
{
	//system("cls");
	cout<<"-------------------------------------------------------------------"<<endl;
	cout<<"                                Menu";
    cout<<endl<<endl;
	cout<<"                            1, 选择密码本";
	cout<<endl<<endl;
	cout<<"                            2, 加密文件";
	cout<<endl<<endl;
	cout<<"                            3, 解密文件";
	cout<<endl<<endl;
	cout<<"                            4, 退出";
	cout<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"请注意：必须先选择密码本才可以进行加密和解密操作！"<<endl;
	cout << "Please input your choice(输入选择): ";
}


