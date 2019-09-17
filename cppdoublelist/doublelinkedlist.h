#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
template <typename DATA>

struct Node
{
	DATA * Data;
	// int  Data;
	Node *pNext;
	Node *pPrev;
};


template <typename DATA>
class doublelinkedlist
{

private:
	Node<DATA> head;
	Node<DATA> tail;


public:
	doublelinkedlist()
	{
		head.pNext = &tail;
		tail.pPrev = &head;
		tail.pNext = NULL;
		head.pPrev = NULL;

	}

	int Head(DATA *Data);
	int Tail(DATA *Data);
	int Del(DATA *Data);
	int Sear(DATA *Data);
	void AllDel(void);
	void Print(void);

};

template <typename DATA>
int doublelinkedlist<DATA>::Head(DATA *Data){

	Node<DATA> *pNode = new Node<DATA>;

	pNode->Data = Data; //������ ����

	pNode->pNext = head.pNext;
	pNode->pPrev = &head;
	head.pNext = pNode;
	pNode->pNext->pPrev = pNode;

	return 0;

}
//������ �����ϴ� �κ�
template <typename DATA>
int doublelinkedlist<DATA>::Tail(DATA *Data){

	Node<DATA> *pNode = new Node<DATA>;

	pNode->Data = Data;

	pNode->pPrev = tail.pPrev;
	pNode->pNext = &tail;
	tail.pPrev = pNode;
	pNode->pPrev->pNext = pNode;

	return 0;
}

//�˻� �ϴ� �κ�
template <typename DATA>
int doublelinkedlist<DATA>::Sear(DATA *Data){

	Node<DATA> *pNode = head.pNext;

	while (pNode != &tail){

		if (*(DATA*)pNode->Data == *(DATA*)Data){

			cout << "[" << *(DATA*)Data << "]" << " �� �˻� " << endl;

			return 0;
		}

		pNode = pNode->pNext;
	}

	return 1;
}


//���� �ϴ� �κ�
template <typename DATA>
int doublelinkedlist<DATA>::Del(DATA *Data){

	Node<DATA> *pNode = head.pNext;

	while (pNode != &tail){

		if (*(DATA *)pNode->Data == *(DATA *)Data){
			pNode->pNext->pPrev = pNode->pPrev;
			pNode->pPrev->pNext = pNode->pNext;
			delete pNode;

			return 0;
		}

		pNode = pNode->pNext;
	}

	return 1;
}



//��� ���� �ϴ� �κ�
template <typename DATA>
void doublelinkedlist<DATA>::AllDel(void){

	Node<DATA> *pNode = head.pNext;
	Node<DATA> *DeleteNode;

	while (pNode != &tail)
	{
		DeleteNode = pNode;
		pNode = pNode->pNext;
		delete DeleteNode;
	}

	cout << "��� ���� �Ǿ����ϴ�" << endl;

	head.pNext = &tail;
	tail.pPrev = &head;

}


// ����ϴ� �κ�
template <typename DATA>
void doublelinkedlist<DATA>::Print(void){

	struct Node<DATA> *pNode = head.pNext;

	while (pNode != &tail){

		cout << "[" << *(DATA*)pNode->Data << "]";

		if (pNode->pNext == &tail){
			cout << endl;
		}

		else{
			printf("->");
		}

		pNode = pNode->pNext;
	}

}

#endif
