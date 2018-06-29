#pragma once
#include "stack.h"
#include "queue.h"

// Hàm "Ba Lan" hóa hàng đợi.
// VD: Chuỗi ban đầu : "2 * (11 + 9) / 5 - 6)
//		Ban đầu hàng đợi là:
//	    2, *, (, 11, +, 9, ), /, 5, -, 6
//		Sau khi được "Ba Lan" hóa:
//		2, 11, 9, +, *, 5, /, 6, -
queue balanize(std::string expression);

// Hàm tính giá trị của 1 biểu thức đầu vào dạng chuỗi.
// Tham số: biểu thức dưới dạng chuỗi -> string
// Đầu ra: 1 giá trị nguyên ứng với biểu thức đầu vào -> int.
// VD: expression = "1+22+3/3*((4+4)*1/3)"
//	  => evaluateExpression(expression) = 25
//	   expression = "2 * (11 + 9) / 5 - 6"
//	  => evaluateExpression(expression) = 2
long evaluateExpression(std::string expression);


// Hàm chuẩn hóa chuỗi theo dạng biểu thức tính toán.
void standardize(std::string &expression);

// Kiểm tra nếu biểu thức chỉ chứa những kí tự hợp lệ.
// => (, ), + , -, * ,/ , 0, 1.., 9 là các kí tự hợp lệ.
// Các kí tự còn lại nếu bị phát hiện sẽ return false.
bool containValidCharacter(std::string expression);

// Kiểm tra xem biểu thức có hợp lệ không.
bool isValid(std::string expression);