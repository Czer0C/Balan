#include "balan.h"
// Thông báo đầu chương trình.
std::string noti_1 = "\n=============================================================================== \n\t\t      Chuong trinh tinh toan tho so\n\n\t\t   Duoc thuc hien boi Nguyen Hai Trieu\n\t\t      MSSV : 1560602 | Lop : 15CK5\n\t\t   Giang vien phu trach : Ho Thi Xanh\n\n\t     Nhap vao 1 bieu thuc de chuong trinh tinh toan\n\t\tKhong nhap gi ca va nhan Enter de ket thuc\n\n\n===============================================================================\n";

			/*==============================================================================*\
			||																				||
			||				BÀI TẬP CUỐI KÌ - ĐỀ 1 : CẤU TRÚC DỮ LIỆU BALAN					||
			||					SINH VIÊN THỰC HIỆN : NGUYỄN HẢI TRIỀU						||
			||						MSSV : 1560602 | LỚP 15CK5								||
			||			GIẢNG VIÊN PHỤ TRÁCH (CA THỨ CHIỀU THỨ 6) : HỒ THỊ XANH				||
			||																				||
			\*==============================================================================*/


int main(int argc, char *argv[]) {
	std::cout << noti_1;
	if (argc == 2) { // Tham số dòng lệnh (Nếu có).
		std::cout << "\n\t\t\tChe do tham so dong lenh\n";
		std::cout << "\t\tBieu thuc dau vao la: " << argv[1] << endl;
		std::string temp(argv[1]);
		standardize(temp); // Chuẩn hóa chuỗi.
		if (!isValid(temp)) { // Nếu đầu vào không hợp lệ thì ngừng chạy.
			std::cout << "\t\tBieu thuc nay khong hop le, vui long thu lai\n";
			system("pause");
			return 0;
		}
		long result = evaluateExpression(temp); // Tính toán.
		if (result != NotANumber) { // Nếu kết quả đúng thì in ra màn hình console.
			std::cout << "\n\t\t\t\t     = " << result;
			std::cout << "\n\t\tCam on da su dung chuong trinh nay\n";
			std::cout << "\n===============================================================================\n";
			system("pause");
			return 0;
		}
		else { // Kết quả không phải là số, phép toán sai thì ngừng.
			std::cout << "\n\t\t\tBieu thuc ban vua nhap khong dung, hay thu lai\n\n";
			std::cout << "\n===============================================================================\n";
			system("pause");
			return 0;
		}
	}
	// Chế độ release bình thường.
	std::string a;
	std::cout << "\n\t\t\t   Che do binh thuong\n\n";
	std::cout << "\t\tVD1 : 1+22+3/3*((4+4)*1/3)\n\n\t\tVD2 : 2 * (11 + 9) / 5 - 6\n\n\t\tVD3 : (-(5 + 8 ) * 12 + (11 -  3) * 4) * -9 + 12\n\n";
	do { // Người dùng tự quyết định khi nào kết thúc chương trình.
		do { // Biểu thức nhập vào phải hợp lệ.
			std::cout << "\n\t>> ";
			getline(cin, a); // Nhập biểu thức.
			standardize(a); // Chuẩn hóa chuỗi.
			if (a == "") { // Nếu không nhập gì tức lệnh hủy -> kết thúc chương trình.
				std::cout << "\n\t\tCam on da su dung chuong trinh nay\n";
				std::cout << "\n-------------------------------------------------------------------------------\n";
				system("pause");
				return 0;
			}
			else if (!isValid(a)) // Ngược lại thì kiểm tra biểu thức.
				std::cout << "\n\tBieu thuc khong hop le, vui long thu lai\n";
		} while (!isValid(a)); // Nếu biểu thức hợp lệ thì chuyển sang tính toán.
		long result = evaluateExpression(a); // Tính toán.
		if (result != NotANumber) { // Nếu kết quả đúng.
			std::cout << "\t    = " << result;
			std::cout << "\n-------------------------------------------------------------------------------\n";
		}
		else { // Kết quả không phải là số, phép toán sai.
			std::cout << "\n\t\t\tBieu thuc ban vua nhap khong dung, hay thu lai\n\n";
			std::cout << "\n-------------------------------------------------------------------------------\n";
		}
	} while (a.size() > 0); // Chương trình chỉ kết thúc nếu không nhập gì.
	return 0;
}