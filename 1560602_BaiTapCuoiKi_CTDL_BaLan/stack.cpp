#include "stack.h"

// Hàm dựng mặc định.
stack::stack() {
	pHead = NULL;
} 

// Hàm hủy.
stack::~stack() {
	while (pHead) {
		node * pTemp = pHead;
		pHead = pHead->pNext;
		delete pTemp;
	}
}

// Hàm kiểm tra ngăn xếp rỗng.
bool stack::isEmpty() { 
	return pHead == NULL;
} 

// Hàm thêm 1 token vào đầu ngăn xếp.
void stack::push(token data) { 
	node * pNode = new node(data); // Dựng 1 nút mới từ dữ liệu đầu vào.
	if (pNode == NULL) {
		std::cout << "Khong du bo nho\n";
		return;
	}
	if (pHead == NULL)
		pHead = pNode;
	else {
		pNode->pNext = pHead;
		pHead = pNode;
	}
}

// Hàm LẤY token đầu tiên khỏi ngăn xếp.
// => Trả về token đầu tiên trong ngăn xếp.
//	  Đồng thời xóa luôn nút đầu tiên trong ngăn xếp.
token stack::pop() { 
	if (isEmpty()) {
		std::cout << "Ngan xep rong!\n";
		return token(); // Ngăn xếp rỗng thì trả về 1 token mặc định.
	}
	else {
		token first = pHead->key; // Lấy token đầu tiên.
		if (pHead->pNext == NULL) { // Nếu ngăn xếp chỉ còn 1 phần tử.		 		
			delete pHead;
			pHead = NULL; // Khởi tạo lại ngăn xếp.			
		}
		else { // Còn nhiều phần tử thì xóa bình thường.
			node * pNode = pHead;
			pHead = pHead->pNext;
			delete pNode;
		}
		return first; // Trả về token đầu tiên.
	}
}

// Hàm lấy dữ liệu nút đầu tiên (không xóa).
token stack::top() { 
	if (isEmpty()) {
		std::cout << "Ngan xep rong!\n";
		return token();
	}
	return pHead->key;
}