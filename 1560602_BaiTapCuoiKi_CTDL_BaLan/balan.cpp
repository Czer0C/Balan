#include "balan.h"

// Hàm "Ba Lan" hóa hàng đợi.
// VD: Chuỗi ban đầu : "2 * (11 + 9) / 5 - 6)
//		Ban đầu hàng đợi là:
//	    2, *, (, 11, +, 9, ), /, 5, -, 6
//		Sau khi được "Ba Lan" hóa:
//		2, 11, 9, +, *, 5, /, 6, -
queue balanize(std::string expression) {
	queue tokens(expression); // Tạo 1 hàng đợi các token từ chuỗi đầu vào.
	queue balan; // Tạo hàng đợi chứa các token theo cấu trúc Ba Lan.
	stack operatoR; // Tạo 1 ngăn xếp để chứa các toán tử.
	while (!tokens.isEmpty()) { // Khi hàng đợi vẫn còn token.
		token tok = tokens.pop(); // LẤY token đầu tiên khỏi hàng đợi.
		if (tok.type == 0) // Là toán hạng thì bỏ vào kết quả.
			balan.enqueue(tok);
		else if (tok.value == '(') // Gặp ngoặc trái thì cho vào ngăn xếp.
			operatoR.push(tok);
		else if (tok.value == ')') { // Gặp ngoặc phải.
			while (!operatoR.isEmpty() && operatoR.top().value != '(') // Khi token đầu ngăn xếp không phải ngoặc trái.
				balan.enqueue(operatoR.pop()); // LẤY token đầu tiên khỏi ngăn xếp, THÊM vào kết quả.
			operatoR.pop(); // Bỏ token ngoặc trái.
		}
		else if (tok.type > 1) { // Các trường hợp còn lại là toán tử.
			if (operatoR.isEmpty() || (operatoR.top().type < tok.type)) // Nếu ngăn xếp rỗng.
				operatoR.push(tok); // Hoặc token đầu ngăn xếp "yếu" hơn token đang xét => thêm vào.
			else if (operatoR.top().type == tok.type) { // token đầu ngăn xếp bằng mức.
				balan.enqueue(operatoR.pop()); // LẤY token đầu tiên khỏi ngăn xếp, THÊM vào kết quả.
				operatoR.push(tok); // Cho token đang xét vào ngăn xếp.
			}
			else if (operatoR.top().type > tok.type) { // token đầu ngăn xếp "mạnh" hơn.
				while (!operatoR.isEmpty() && operatoR.top().value != '(') // Ngăn xếp không rỗng, token khác '('
					balan.enqueue(operatoR.pop()); // LẤY token đầu tiên khỏi ngăn xếp, THÊM vào kết quả.
				operatoR.push(tok); // Cho token đang xét vào ngăn xếp.
			}
		}
	}
	while (!operatoR.isEmpty())// Trong khi ngăn xếp vẫn còn phần tử.
		balan.enqueue(operatoR.pop()); // LẤY token đầu tiên khỏi ngăn xếp, THÊM vào kết quả.
	return balan;
}


// Hàm tính giá trị của 1 biểu thức đầu vào dạng chuỗi.
// Tham số: biểu thức dưới dạng chuỗi -> string
// Đầu ra: 1 giá trị nguyên ứng với biểu thức đầu vào -> int.
// VD: expression = "1+22+3/3*((4+4)*1/3)"
//	  => evaluateExpression(expression) = 25
//	   expression = "2 * (11 + 9) / 5 - 6"
//	  => evaluateExpression(expression) = 2
long evaluateExpression(std::string expression) {
	queue balan = balanize(expression); // Lấy 1 cấu trúc Ba Lan từ chuỗi đầu vào.
	stack pending; // Khởi tạo 1 ngăn xếp cho việc tính toán.
	while (!balan.isEmpty()) { // Trong khi "dãy" Ba Lan vẫn còn phần tử.
		token tok = balan.pop(); // LẤY phần tử đầu tiên khỏi dãy.
		if (tok.type == 0) // Là toán hạng thì cho vào đầu ngăn xếp.
			pending.push(tok);
		else { // Là toán tử.
			int a = pending.pop().value; // "Rút" 2 toán hạng đầu tiên khỏi ngăn xếp.
			int b = pending.pop().value; // Vì ngăn xếp là "đầu vào đầu ra" nên thứ tự toán hạng bị đảo.
			switch (tok.value) { // Xét toán tử
			case '+':						  // Thực hiện phép cộng.
				pending.push(token(0, b + a));// Tạo 1 token(2 tham số) và bỏ vào đầu ngăn xếp.
				break;
			case '-':						  // Thực hiện phép trừ.
				pending.push(token(0, b - a));// Tạo 1 token(2 tham số) và bỏ vào đầu ngăn xếp.
				break;
			case '*':						  // Thực hiện phép nhân.
				pending.push(token(0, b * a));// Tạo 1 token(2 tham số) và bỏ vào đầu ngăn xếp.
				break;
			case '/':						  // Thực hiện phép chia.
				pending.push(token(0, b / a));// Tạo 1 token(2 tham số) và bỏ vào đầu ngăn xếp.
				break;
			}
		}
	}
	if (pending.pHead->pNext == NULL) // Nếu ngăn xếp chỉ còn 1 phần tử.
		return (pending.pHead->key.value); // Trả về token đầu tiên => kết quả biểu thức.
	else // Ngược lại là biểu thức bị sai định dạng.
		cout << "\nNguoi dung nhap sai bieu thuc\n";
	return NotANumber; // Trả về 1 giá trị không phải là số.
}


// Hàm chuẩn hóa chuỗi theo dạng biểu thức tính toán.
// VD 1 : input = "1(3)" => output = "1*3".
// VD 2 : input = "-(3 + 4) * -9 => output = "-1*(3+4)*-9".
// VD 3 : input = "- - 2 * 9 (3 +- 9) => output = "2*9*(3-9)".
void standardize(std::string &expression) {
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == ' ') // Bỏ đi khoảng trống.
			expression.erase(expression.begin() + i);
		else if (i < expression.size() - 1) { // Tránh truy xuất phần tử ngoài mảng.
			// TH 1: 1 -- 2 = 1 + 2 => Bỏ 1 dấu -, đổi dấu trừ kia thành +.
			if (expression[i] == '-' && expression[i + 1] == '-') {
				expression.erase(expression.begin() + i + 1);
				expression[i] = '+';
			}
			// TH 2: -(1 + 3) = -1 * (1 + 3) => Thêm 1 * vào trước dấu (.
			else if (expression[i] == '-' && expression[i + 1] == '(')
				expression.insert(i + 1, "1*");
			// TH 3: 1 ++ 2 = 1 + 2 => Bỏ 1 dấu +.
			else if (expression[i] == '+' && expression[i + 1] == '+')
				expression.erase(expression.begin() + i + 1);
			// TH 4:  + (1 * 2) = (1 * 2), 1 +- 3 = 1 - 3 => Bỏ đi dấu +.
			else if (expression[i] == '+' && i == 0 && (expression[i + 1] == '(' || expression[i + 1] == '-'))
				expression.erase(expression.begin() + i);
			// TH 5: 3(9 + 1) = 3 * (9 + 1) => Thêm dấu * vào trước (.
			else if (((expression[i] >= '0' && expression[i] <= '9')) && expression[i + 1] == '(')
				expression.insert(i + 1, "*");
		}
	}
}


// Kiểm tra nếu biểu thức chỉ chứa những kí tự hợp lệ.
// => (, ), + , -, * ,/ , 0, 1.., 9 là các kí tự hợp lệ.
// Các kí tự còn lại nếu bị phát hiện sẽ return false.
bool containValidCharacter(std::string expression) {
	int balance = 0; // Cân bằng 2 dấu ngoặc.
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'
			|| expression[i] == ' ' || (expression[i] >= '0' && expression[i] <= '9'))
			continue; // Nếu gặp các kí tự hợp lệ thì bỏ qua.
		else if (expression[i] == '(')
			balance++;
		else if (expression[i] == ')')
			balance--;
		else // Có kí tự lạ tự động return false.
			return false;
	} // balance != 0 -> dư hoặc thiếu ngoặc -> return false.
	return balance == 0 ? true : false;
}


// Kiểm tra xem biểu thức có hợp lệ không.
bool isValid(std::string expression) {
	if (expression.size() < 1 || !containValidCharacter(expression))
		return false; // Khoảng trống và có chứa kí tự lạ return false.
	standardize(expression); // Chuẩn hóa đầu vào.
	queue q(expression); // Tạo hàng đợi các token.
	int operand = 0; // Đếm toán hạng.
	int operatoR = 0; // Đếm toán tử.
	for (node * i = q.pHead; i; i = i->pNext) {
		if (i->key.type == 0)
			operand++;
		else if (i->key.type > 1) // Các toán tử có kiểu là 2, 3.
			operatoR++;
	} // Đầu vào hợp lệ <=> đã cân bằng và số toán tử < toán hạng 1 đơn vị.
	return (operand - operatoR == 1);
}