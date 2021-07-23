#include<iostream>
class doublyLinkedListNode{
	public:
        int data;
        doublyLinkedListNode* next;
        doublyLinkedListNode* prev;
        doublyLinkedListNode(int data){
                this->data = data;
                this->next = NULL;
                this-> prev = NULL;
        }
};
class doublyLinkedList{
	public:
		doublyLinkedListNode* insert_front(int data, doublyLinkedListNode* head){
			doublyLinkedListNode* node = new doublyLinkedListNode(data);
			node->next = head;
			head = node;
			return head;
		}

		doublyLinkedListNode* insert_tail(int data, doublyLinkedListNode* head){
			doublyLinkedListNode* point = head;
			doublyLinkedListNode* node = new doublyLinkedListNode(data);
			while(point->next){
				point = point->next;
			}
			node->prev = point;
			point->next = node;
			return head;
		}
		doublyLinkedListNode* insertSorted(int data, doublyLinkedListNode* head){
			doublyLinkedListNode* point = head;
			doublyLinkedListNode* node = new doublyLinkedListNode(data);
			doublyLinkedListNode* p = NULL;
			while(point){
				p = point;
				if(point->data >= data){
					node->prev = point->prev;
					point->prev = node;
					node->next = point;
					if(node->prev)
						node->prev->next = node;
					else
						head = node;
					break;
				}
				point = point->next;
			}
			if(p->data<data){
				p->next = node;
				node->prev = p;
			}
			return head;
		}
		void print(doublyLinkedListNode* head){
			doublyLinkedListNode* point = head;
			while(point){
				printf("%d ", point->data);
				point = point->next;
			}
		}
};
int main(){
	int n,data;
	scanf("%d%d", &n, &data);
	doublyLinkedListNode* head = new doublyLinkedListNode(data);
	doublyLinkedList dll;
	while(--n){
		scanf("%d",&data);
		head = dll.insert_tail(data, head);
	}
	scanf("%d",&data);
	head = dll.insertSorted(data, head);
	dll.print(head);
}
