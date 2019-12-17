Node* Partition(Node* PBegin, Node* PEnd){
    int key = PBegin->val;
    Node* p = PBegin; Node* q = PBegin->next;
    while(q!=Pend){
        if(q->key<key){
            p = p->next;
            swap(q->val,p->val);
        }
        q = q->next;
    }
    swap(p->key, q->key);
    return p;
}

void link_quick_sort(Node* pBegin, Node* pEnd){
    if(pBegin != pEnd){
        Node* index = Partition(pBegin,pEnd);
        link_quick_sort(PBegin,Partition);
        link_quick_sort(Partition->next,pEnd);
    }
}