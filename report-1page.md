# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Tóm tắt ngắn gọn mục tiêu của bài lab.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Giữ chữ hoa và dấu cách |
| hello world | 5 | mjqqt btwqi | Xử lý chữ thường |
| L ORYH BRX | 3 | I LOVE YOU | Giải mã bằng key âm |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Giữ khoảng trắng như ký tự bình thường |
| I LOVE YOU | 4 | I  EYLVOOU | Kiểm tra pattern zig-zag với 4 ray |
| ILV O OEYU | 2 | I LOVE YOU | Đã giải mã chính xác |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
  - Một số ký tự không phải chữ cái hoặc dấu cách sẽ bị coi là không hợp lệ (ví dụ: 'hello!').
- Kết quả đọc từ `data/input.txt`:
  - Nội dung file được đọc và mã hóa/mã giải trong chương trình (ví dụ: "HELLO WORLD").

## 4. Kết luận
Nêu ngắn gọn em học được gì từ bài lab, khó khăn lớn nhất là gì, và điều gì giúp em hiểu rõ hơn về Caesar hoặc Rail Fence Cipher.
