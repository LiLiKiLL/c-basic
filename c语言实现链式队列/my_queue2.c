#include "my_queue2.h"
#include <stdio.h>
#include <malloc.h>

/* 初始化队列 */
Queue *init_queue()
{
	Queue *pqueue;
	pqueue = (Queue *)malloc(sizeof(Queue));
	if(pqueue != NULL){
		pqueue->front = NULL;
		pqueue->rear = NULL;
		pqueue->size = 0;
	}
	return pqueue;
}

/* 销毁队列 */
void destroy_queue(Queue *q)
{
	if(is_queue_empty(q) != 1){
		clear_queue(q);
	}
	free(q);
}

/* 清空队列 */
void clear_queue(Queue *q)
{
	while(is_queue_empty(q) != 1){
		pop_queue(q);
	}
}

/* 判空队列 */
int is_queue_empty(Queue *q)
{
	if(q->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/* 获取队列长度 */
int get_queue_size(Queue *q)
{
	return q->size;
}

/* 元素入队 */
q_node_t push_queue(Queue *q,q_item n)
{
	q_node_t qnode;
	qnode = (q_node_t)malloc(sizeof(q_node_t));
	if(qnode != NULL){
		qnode->data = n;
		qnode->next = NULL;
		if(is_queue_empty(q) == 1){
			q->front = qnode;
		}
		else{
			q->rear->next = qnode;
		}
		q->rear = qnode;
		q->size++;
	}
	return qnode;
}

/* 元素出队 */
q_node_t pop_queue(Queue *q)
{
	q_node_t qnode = q->front;
	if(is_queue_empty(q) != 1){
		q->front = qnode->next;
		free(qnode);
		q->size--;
		if(q->size == 0){
			q->rear = NULL;
		}
	}
	return q->front;
}

/* 返回队头元素 */
q_node_t get_queue_front(Queue *q)
{
	return q->front;
}

/* 返回队尾元素 */
q_node_t get_queue_rear(Queue *q)
{
	return q->rear;
}

/* 打印队列元素 */
void print_queue(Queue *q)
{
	q_node_t qnode = q->front;
	int i = q->size;
	while(i--){
		printf("%d\t",qnode->data);
		qnode = qnode->next;
	}
	printf("\n");
}

