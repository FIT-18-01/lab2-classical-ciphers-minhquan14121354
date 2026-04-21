# Test Cases – FIT4012 Lab 2

## Caesar Cipher
- [x] Encrypt `I LOVE YOU` với key `3` → `L ORYH BRX`
- [x] Encrypt `hello world` với key `5` → `mjqqt btwqi`
- [x] Decrypt `L ORYH BRX` với key `3` → `I LOVE YOU`

## Rail Fence Cipher
- [x] Encrypt `I LOVE YOU` với `2` rails → `ILV O OEYU`
- [x] Encrypt `I LOVE YOU` với `4` rails → `I  EYLVOOU`
- [x] Decrypt `ILV O OEYU` với `2` rails → `I LOVE YOU`

## Validation / File input
- [x] Kiểm tra đầu vào không hợp lệ (nhập ký tự đặc biệt => thông báo lỗi)
- [x] Đọc thông điệp từ `data/input.txt` và xử lý thành công
