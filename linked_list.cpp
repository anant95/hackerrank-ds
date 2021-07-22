#include<iostream>
#include<map>
class Node{
	public:
		int data;
		Node* next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};
class linkedList{
	public:
	void print(Node* point){
		while(point){
	 		printf("%d ",point->data);
			point = point->next;
		}
		printf("\n");
	}
	Node* insert_tail(int data, Node* head){
		Node* point = head;
		Node* node = new Node(data);
		while(point->next){
			point = point->next;
		}
		point->next = node;
		return head;
	}
	Node* delete_node(int pos, Node* head){
		Node* point = head;
		Node* temp;
		if(pos == 0){
			if(head->next == NULL){
				delete head;
				return NULL;
			}
			else{
				head = point->next;
				delete point;
				return head;
			}
		}
		while(--pos){
			temp = head;
			point = point->next;

		}
		temp = point->next;
		point->next = point->next->next;
		delete temp;
		return head;

	}
	Node* reverse_list(Node* point){
		Node* current = point;
		Node* prev = NULL;
		Node* next = NULL;
		while(current){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		return prev;
	}
	int compare_list(Node* list1, Node* list2){
		while(list1 && list2){
			if(list1->data != list2->data){
				break;
			}
			list1 = list1->next;
			list2 = list2->next;
		}
		if(!list1 && !list2){
			return 1;
		}
		return 0;
	}
	Node* merge_sorted_list(Node* list1, Node* list2){
		Node* head=NULL;
		Node* point=NULL;
		Node* point1=NULL;
		while(list1 && list2){
			if(list1->data > list2->data){
				point = list2;
				list2 = list2->next;
			}
			else{
				point = list1;
				list1 = list1->next;
			}
			point->next = NULL;
			if(!head){
				head = point;
				point1 = head;
			}
			else{
				point1->next = point;
				point1 = point;
			}
		}
		if(list1){
			point1->next = list1;
		}
		else if(list2){
			point1->next = list2;
		}
		return head;
	}
	Node* delete_duplicate_sorted(Node* head){
		Node* point = head;
		Node* point1 = NULL;
		while(point->next){
			if(point->data == point->next->data){
				point1 = point->next;
				point->next = point->next->next;
				delete point1;
			}
			else{	
				point= point->next;
			}
		}
		return head;
	}
	int cycle_detect(Node* head){
		Node* point = head;
		std::map<int, bool> int_present;
		while(point){
			if(!int_present[point->data]){
				int_present[point->data] = true;
			}
			else
				return 1;
		point = point->next;
		}
		return 0;
	}
	Node* findMergePoint(Node* head1, Node* head2){
		Node* point1 = head1;
		Node* point2 = head2;
		if(!point1 || !point2)
			return NULL;
		while(point1 != point2){
			if(!point1)
				point1 = head2;
			else
				point1 = point1 -> next;
			if(!point2)
				point2 = head1;
			else
				point2 = point2 -> next;
		}
		return point1;
	}
};
int main(){
	linkedList ll;
	int t,n;
	scanf("%d",&t);
	while(t){
		t--;
		scanf("%d", &n);
		int data;
		scanf("%d",&data);
		Node* head1 = new Node(data);
		for(int i = 0; i<n-1; i++){
			scanf("%d", &data);
			head1 = ll.insert_tail(data,head1);
		}
		scanf("%d", &n);
		scanf("%d",&data);
		Node* head2 = new Node(data);
		for(int i = 0; i<n-1; i++){
			scanf("%d", &data);
			head2 = ll.insert_tail(data,head2);
		}
		Node* m = ll.findMergePoint(head1, head2);
		if(m)
			printf("%d ", m -> data);
		}
}
