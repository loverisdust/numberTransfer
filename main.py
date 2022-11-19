dir = {"零": 0, "壹": 1, "贰": 2, "叁": 3, "肆": 4, "伍": 5, "陆": 6, "柒": 7, "捌": 8, "玖": 9}
its = ["零","壹","贰","叁","肆","伍","陆","柒","捌","玖"]

def stoint(s):
    lens = len(s)
    sum = 0
    db = 1
    aaa = 1
    i = lens - 1
    while i >= 0:
        if s[i] == "拾":
            aaa = 10 * db
        elif s[i] == "佰":
            aaa = 100 * db
        elif s[i] == "仟":
            aaa = 1000 * db
        elif s[i] == "万":
            db = 10000
            i = i - 1
            aaa = db
            continue
        elif s[i] == "亿":
            db = 100000000
            i = i - 1
            aaa = db
            continue
        elif s[i] == "零":
            i = i - 1
            continue
        else:
            j = 0
            while j < 10:
                if s[i] == its[j]:
                    sum = sum + j * aaa
                j = j + 1
        i = i - 1
    return sum

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

def judgeType(Str):
    NUM= ["零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", \
           "玖", "拾", "佰", "仟", "万", "亿", "元", "整"]
    num= ["1","2","3","4","5","6","7","8","9","0"]

    for i in Str:
        if (i not in NUM )and (i not in num):
            return -1
        elif i in NUM:
            return 1
        else:
            return 0

if __name__ == '__main__':
    number = input("请输入:")
    type = judgeType(number)
    if type == 0:
        #小写转大写
        print(lowertoupper(number,recursive_depth=0)+"元整")
    elif type == 1:
        #大写转小写
        print(stoint(number))
    else:
        print("错误的输入！")
