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

class HuffmanTree
{
  public:


