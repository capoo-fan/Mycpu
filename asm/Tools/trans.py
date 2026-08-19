def hex_to_signed_decimal(hex_str, bits=32):
    value = int(hex_str, 16)

    # 如果最高位为 1，则按有符号补码解释
    if value >= (1 << (bits - 1)):
        value -= (1 << bits)

    return value


while True:
    s = input("请输入十六进制数，例如 0x80400000（q退出）：").strip()

    if s.lower() == "q":
        break

    try:
        result = hex_to_signed_decimal(s)
        print("十进制有符号值 =", result)
        print("右移12位 =", result >> 12)
        print()
    except ValueError:
        print("输入格式错误")