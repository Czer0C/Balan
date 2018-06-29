#include "queue.h"

// Hàm dựng mặc định.
queue::queue() { 
	pHead = pTail = NULL;
} 


// Hàm dựng 1 tham số (string).
// Từ 1 chuỗi ban đầu, "cắt" nhỏ chuỗi ra thành các token và bỏ vào hàng đợi.
queue::queue(std::string expression) {
	pHead = pTail = NULL;
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == ' ')
			continue;
		std::string temp(1, expression[i]);
		if (expression[i] == '-') {
			if (expression[i - 1] == '(' || expression[i - 1] == ')' || expression[i - 1] == '*'  
				|| expression[i - 1] == '/' && (i > 0)) {
				size_t j = i + 1;
				for (; j < expression.size() && (expression[j] >= '0' && expression[j] <= '9'); j++)
					temp += expression[j];
				i = j - 1; 
			}
		}
		else if (expression[i] >= '0' && expression[i] <= '9') {
			size_t j = i + 1;
			for (; j < expression.size() && (expression[j] >= '0' && expression[j] <= '9'); j++)
				temp += expression[j];
			i = j - 1; // 
		}
		enqueue(token(temp));
	}
}

// Hàm hủy.
queue::~queue() { 
	while (pHead) {
		node * pTemp = pHead;
		pHead = pHead->pNext;
		delete pTemp;
	}
}

// Hàm kiểm tra hàng đợi rỗng.
bool queue::isEmpty() {
	return pHead == NULL;
}

// Hàm thêm 1 token vào hàng đợi (đuôi).
void queue::enqueue(token data) { 
	node * pNode = new node(data); // Dựng 1 nút mới từ dữ liệu đầu vào.
	if (isEmpty())
		pHead = pTail = pNode;
	else {
		pTail->pNext = pNode;
		pTail = pNode;
	}
}

// Hàm LẤY token đầu tiên khỏi hàng đợi.
// => Trả về token đầu tiên trong hàng đợi.
//	  Đồng thời xóa luôn nút đầu tiên trong hàng đợi.
token queue::pop() { 
	if (isEmpty()) {
		std::cout << "Hang doi rong\n";
		return token(); // Hàng đợi rỗng thì trả về 1 token mặc định.
	}
	else {
		token first = pHead->key; // Lấy dữ liệu nút đầu tiên.
		if (pHead->pNext == NULL) { // Nếu hàng đợi chỉ còn 1 phần tử.
			delete pHead; // Xóa nút đầu tiên.
			pHead = pTail = NULL; // Khởi tạo lại hàng đợi.
		}
		else { // Còn nhiều phần tử thì xóa bình thường.
			node * pTemp = pHead;
			pHead = pHead->pNext;
			delete pTemp;
		}
		return first; // Trả về token đầu tiên.
	}
}

// Hàm XEM token đầu ngăn xếp (không xóa).
token queue::top() { 
	if (isEmpty()) {
		std::cout << "Ngan xep rong\n";
		return token();
	}
	else
		return pHead->key;
}