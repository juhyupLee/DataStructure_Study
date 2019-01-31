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

	if (++pq->rear > QUE_LEN - 1)// rear 포인터를 증가시키는순간
		pq->rear = 0;
	//rear을 업했는데, 그것이 front랑 같아진다면... 허들을 넘을수 없기때문에 원래로돌아가야한다

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
	if (pq->front == pq->rear) // Dequeue를 하려는순간 보니깐 같아버린다. 그렇단얘기는 이미 뺄게없단애기// 텅빔
		return 0;

	if (++pq->front>QUE_LEN-1 )
		pq->front = 0;


	return pq->queArr[pq->front] ;

}

Data QPeek(Queue * pq)
{

	return pq->queArr[pq->front];
}
