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

print(stoint("壹拾亿"))