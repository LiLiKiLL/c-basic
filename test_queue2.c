#include "my_queue2.h"
#include <stdio.h>

int main()
{
	Queue *test_queue;// 队列数据结构用于存储数据
	test_queue = init_queue();
	// 将0-9入队
	int i;
	for(i = 0; i < 10; i++){
		push_queue(test_queue,i);
	}
	printf("所有队列元素：");
	print_queue(test_queue);
	printf("队列长度：%d\n",get_queue_size(test_queue));
	q_node_t a;
	a = get_queue_front(test_queue);
	printf("队头元素：%d\n",a->data);
	printf("出队元素9...\n");
	pop_queue(test_queue);
	a = get_queue_front(test_queue);
	printf("队头元素：%d\n",a->data);
	printf("清空队列...\n");
	clear_queue(test_queue);
	if(is_queue_empty(test_queue) != 0){
		printf("队列已清空\n");
	}
	destroy_queue(test_queue);
	printf("队列已销毁\n");
	return 0;
}