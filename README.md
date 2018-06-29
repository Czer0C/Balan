# Balan

### Yêu cầu: 
> Viết chương trình cho phép nhập vào một biểu thức toán học từ dòng lệnh, tính giá trị của biểu thức này và xuất kết quả ra màn hình. Biểu thức có chứa các phép tính +, -, *, / (phép chia nguyên), dấu mở ngoặc, đóng ngoặc, các số trong biểu thức là số nguyên dương. Các token ngăn cách nhau bằng 1 khoảng trắng. VD: (-(5 + 8 ) * 12 + (11 - 3) * 4) * -9 + 12

### Ghi chú:
- **Biểu thức trung tố**: Toán tử nằm giữa 2 toán hạng. VD: x + y
- **Biểu thức hậu tố**: Toán tử nằm sau 2 toán hạng. VD: x y +
- Trong bài viết này mỗi thành phần riêng lẻ trong biểu thức được gọi là *Token*. Như trong ví dụ
trên thì (, 5, +, 8, ), *, 12, +, 11… là các Token.

### Cách tính giá trị biểu thức:
- **Bước 1**: Chuyển biểu thức từ dạng trung sang dạng hậu tố.
- **Bước 2**: Tính giá trị của biểu thức dạng hậu tố, ta sẽ được kết quả.

### Tool sử dụng: Visual Studio 2017 Enterprise
