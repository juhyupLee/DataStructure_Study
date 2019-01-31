#include "ArrayQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
	for (int i = 0; i < QUE_LEN; ++i)
	{
		pq->queArr[i] = 0;
	}
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}

void Enqueue(Queue * pq, Data data)
{
	int temp = pq->rear;

	if (++pq->rear > QUE_LEN - 1)// rear �����͸� ������Ű�¼���
		pq->rear = 0;
	//rear�� ���ߴµ�, �װ��� front�� �������ٸ�... ����� ������ ���⶧���� �����ε��ư����Ѵ�

	if (pq->rear == pq->front)
	{
		pq->rear = temp;
		return;
	}
	else
	pq->queArr[pq->rear] = data;

}

Data Dequeue(Queue * pq)
{
	if (pq->front == pq->rear) // Dequeue�� �Ϸ��¼��� ���ϱ� ���ƹ�����. �׷��ܾ��� �̹� ���Ծ��ֱܾ�// �ֺ�
		return 0;

	if (++pq->front>QUE_LEN-1 )
		pq->front = 0;


	return pq->queArr[pq->front] ;

}

Data QPeek(Queue * pq)
{

	return pq->queArr[pq->front];
}
