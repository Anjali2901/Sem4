#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *l;
	struct node *r;
	struct node *p;
};

void print(struct node * head) 
{
	if(head == NULL)
		return;
	printf("%d ",head->data);
	print(head->l);
	print(head->r);
}

int int_to_bin(int *a,int n)
{
	int i, j = 0;
	for(i =0 ; n > 0 ; i ++) {
		a[j++] = n%2;
		n = n/2;
	}
	return j-1;
}

struct node * get_node(int x) 
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->l = NULL;
	temp->r = NULL;
	return temp;
}

void max_heapify(struct node *head)
{
	if(head->l == NULL && head->r == NULL) 
		return;
	struct node * left, * right, * largest;
	int t;
	left = head->l;
	right = head ->r;
	if(left != NULL) {
		if(left->data > head->data)
			largest = left;
		else
			largest = head;
	}
	if(right != NULL) {
		if (right->data > largest->data) 
			largest = right;
	}
	if(largest != head) {
		t = largest->data;
		largest->data = head->data;
		head->data = t;
		max_heapify(largest);
	}
}

struct node * delete(struct node *head,int x,int heap_size)
{
	int a[100];
	struct node *temp,*t;
	temp = head;
	int z = int_to_bin(a,heap_size);
	z--;
	while(z > 0) {
		if(a[z] == 1)
			temp = temp->r;
		else 
			temp =temp->l;
		z--;
	}
	if(a[0] == 0) {
		head->data = temp->l->data;
		t = temp->l;
		temp->l = NULL;
	}
	else {
		head->data = temp->r->data;
		t = temp->r;
		temp->r = NULL;
	}
	free(t);
	max_heapify(head);
}

struct node * insert(struct node *head,int x,int heap_size)
{
	int i,z,a[100],t;
	struct node *temp = head;
	struct node *get = get_node(x);
	if(head == NULL) {
		head = get;
		return head;
	}
	z = int_to_bin(a,heap_size+1);
	z--;
	for(i = z ; i > 0 ; i--) {
		if(a[i] == 0)
			temp = temp->l;
		else
			temp = temp->r;
	}
	if(a[0] == 0)
		temp->l = get;
	else
		temp->r = get;
	get->p = temp;
	temp = get;
	while(temp->p != NULL) {
		if(temp->p->data < temp->data){
			t = temp->data;
			temp->data = temp->p->data;
			temp->p->data = t;
			temp = temp->p;
		}
		else 
			break;
	}
	return head;
}
int main()
{
	struct node *parent = NULL;
	int heap_size = 0;
	int n,i,x;
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d",&x);
		parent = insert(parent,x,heap_size);
		heap_size++;
	}
	print(parent);
	printf("\n");
	delete(parent,0,heap_size);
	print(parent);
	return 0;
}