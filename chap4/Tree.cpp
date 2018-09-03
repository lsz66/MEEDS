const int MAXSIZE = 100;
typedef char ElemType;

//双亲树，储存节点的双亲
typedef struct {
	//每个结点的存储结构
	ElemType data;	//数据
	int parent;		//父节点
}PTNode;
typedef struct {
	PTNode nodes[MAXSIZE];	//节点数组
	int n;	//节点数
}PTree;	//双亲树

//孩子树，储存节点的孩子
typedef struct CNode {
	int child;		//孩子的下标
	CNode *next;	//下一个孩子	
}CNode, *Child;
typedef struct {
	ElemType data;	//数据
	Child firstChild;	//第一个孩子
}TNode;
typedef struct {
	TNode nodes[MAXSIZE];
	int n;
}

//孩子兄弟表示
typedef struct CSNode{
	ElemType data;
	CSNode *firstChild, rightSib;
}CSNode;