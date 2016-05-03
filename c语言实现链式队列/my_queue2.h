#ifndef MY_QUEUE2_H
#define MY_QUEUE2_H

typedef int q_item;
typedef struct q_node *q_node_t;
typedef struct q_node{
	q_item data;
	q_node_t next;
}node;

typedef struct{
	q_node_t front;
	q_node_t rear;
	int size;
}Queue;

/* Queue operation */
/* 初始化队列 */
Queue *init_queue();

/* 销毁队列 */
void destroy_queue(Queue *q);

/* 清空队列 */
void clear_queue(Queue *q);

/* 判空队列 */
int is_queue_empty(Queue *q);

/* 获取队列长度 */
int get_queue_size(Queue *q);

/* 元素入队 */
q_node_t push_queue(Queue *q,q_item n);

/* 元素出队 */
q_node_t pop_queue(Queue *q);

/* 返回队头元素 */
q_node_t get_queue_front(Queue *q);

/* 返回队尾元素 */
q_node_t get_queue_rear(Queue *q);

/* 打印队列元素 */
void print_queue(Queue *q);

#endif