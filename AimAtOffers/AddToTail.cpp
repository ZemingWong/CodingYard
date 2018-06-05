struct ListNode {
	int value;
	ListNode* pNext;
};

void AddToTail(ListNode** pHead, value) {
	// New a new node
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->pNext = NULL;

	// Add to tail
	if (*pHead == NULL)	{
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while(pNode->pNext != NULL)
			pNode = pNode->pNext;
		pNext = pNew;
	}
	return;
}；

void RemoveNodeOfValue(ListNode** pHead, int value) {
	//Root node is null or The LinkList is empty
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* pNode = *pHead;
	//Dealing with the first Node
	while((pNode != NULL) && (pNode->value == value)) {
		//Remove Node
		*pHead == pNode->pNext;
		delete *pNode;
		pNode = *pHead;
	}

	if(pNode != NULL) {
		ListNode* pLastNode = pNode;
		pNode = pNode->pNext;
		while(pNode != NULL) {
			if (pNode->value == value) {
				//Remove Node
				pLastNode->pNext = pNode->pNext;
				delete pNode;
				pNode = pLastNode->pNext;
			} else {
				//jump to next Node
				pLastNode = pNode;
				pNode = pLastNode->pNext;
			}
		}
	}
};
