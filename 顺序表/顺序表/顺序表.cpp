#include<stdio.h>
#include<stdlib.h>
//线性表的顺序存储
#define InitSize 100
#define MaxSize 10
typedef struct {
	int data[MaxSize]; //静态分配
	int length; //顺序表的长度
}SqList;

typedef struct {
	int* data; // 指示动态分配数组的指针
	int maxsize, length; //定义数组的最大容量和当前个数
}SeqList;

//初始化顺序表
//静态分配
SqList L;
SeqList L2;
void InitList(SqList& L) {
	L.length = 0; //顺序表初始长度为0
}
//动态分配
void Dynamic_InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int)); //分配存储空间
	L.length = 0;
	L.maxsize = InitSize;
}

//插入操作
bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)
		return false; //判断i的范围是否合法
	if (L.length > L.maxsize)
		return false; //存储空间已满
	int j;
	for (j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1]; //将第i个元素及以后的元素后移
	}
	L.data[i - 1] = e; //在i位置插入e
	L.length++; //表长加一
	return true;
}

//删除操作
bool ListDelect(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)
		return false; //判断i的范围是否合法
	int j;
	e = L.data[i - 1]; //将要删除的数据保存到e
	for (j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--; //表长减一
	return true;
}

//按值查找（顺序查找）
int LocateElem(SeqList& L, int e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i; //返回其下标
		}
	}
	return 0;
}

int main() {
	Dynamic_InitList(L2);

}