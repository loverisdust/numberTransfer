def lowertoupper(number, recursive_depth=0):
    str_number = str(number)
    if len(str_number) > 4:
        str_number = str_number[-4:]
    bits = "零 壹 贰 叁 肆 伍 陆 柒 捌 玖".split(" ")

    units = " 拾 佰 仟".split(" ")
    large_unit = ' 万 亿 万'.split(" ")  # 可扩展,以万为单位
    number_len = len(str_number)
    result = ""

    for i in range(number_len):
        result += bits[int(str_number[i])]
        if str_number[i] != "0":
            result += units[number_len - i - 1]

    # 去除连续的零
    while "零零" in result:
        result = result.replace("零零", "零")
    # 去除尾部的零
    if result[-1] == "零":
        result = result[:-1]
    # 调整10~20之间的数
    if result[:2] == "一十":
        result = result[1:]
    # 字符串连接上大单位
    result += large_unit[recursive_depth]

    # 判断是否递归
    if len(str(number)) > 4:
        recursive_depth += 1
        return lowertoupper(str(number)[:-4], recursive_depth) + result
    else:
        return result

if __name__ == '__main__':
    number = input("请输入:")
    if number.isdigit() and len(number)<=12:
        up = lowertoupper(number,recursive_depth=0)
        if int(number)==0:
            print(up+str("零元整"))
        else:
            print(up + str("元整"))
    else:
        print("输入错误")
