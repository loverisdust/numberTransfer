#include <iostream>
#include <cmath>
using namespace std;

int high = 0;
int flag = 0;
int mark = 0;

/*
此函数用于判断输入的从键盘输入的数据是否有效
当输入数据大于千亿或是含有字母时，无效输入
*/
bool isAvailable(std::string inputNum) {
	std::string::iterator pInputNum = inputNum.begin();

	//遍历输入的数据

	for ( ; pInputNum < inputNum.end() ; pInputNum ++) {

		if (high == 0 && *pInputNum == '0') {
			flag = 1;
			high++;
			continue;
		}

		if (flag) {
			if (*pInputNum != NULL)
				std::cout << "首字符为0，不合法" ;
			mark = 1;
			return false;
		}

		if (*pInputNum > '9' || *pInputNum < '0') {
			std::cout << "请输入数字，不能输入字符" ;
			return false;
		}
		high ++;
	}

//整数部分的位数，不能超过12，否则当作非法输入
	if (high > 12) {
		std::cout << "输入数据过大，目前只支持仟亿" ;
		return false;
	}
	return true;
}



/*
string型数据转化为double型
*/
void stringTranslate2Double(string inputStr, double &inputDouble) {
	inputDouble = atof(const_cast<const char *>(inputStr.c_str()));
}


int main() {
	std::string sNum;
	double dNum;
	const std::string NUM[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
	const std::string UNIT[] = { "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟"};
	{
		high = 0 ;
		int mNum = 0;
		bool FrontNumberIsZero = false;
		std::cout << "请输入待转换的数值：" << std::endl;
		std::cin >> sNum;
		//退出循环


		if (isAvailable(sNum)) {
			std::cout << "转化后为：\n";

			if (flag == 1) {
				cout << "零元整";
			}

			else {

				stringTranslate2Double(sNum, dNum);
				//std::cout<<dNum<<std::endl;
				//处理整数部分
				while (high != 0 && high != 1) {
					mNum = dNum / (pow(10, high - 1));   //取最高位记为mNum
					dNum = dNum - (pow(10, high - 1)) * mNum;  //去掉最高位
					if (mNum == 0) {
						FrontNumberIsZero = true;
						switch (high) {				//4位切分
							case 9:
								std::cout << UNIT[high - 2];
								//FrontNumberIsZero = false;
								break;
							case 5:
								std::cout << UNIT[high - 2];
								//FrontNumberIsZero = false;
								break;
							case 1:
								std::cout << UNIT[high - 2];
								//FrontNumberIsZero = false;
								break;
							default:
								break;
						}
					} else {
						if (FrontNumberIsZero) {
							std::cout << NUM[0];
						}
						FrontNumberIsZero = false;
						std::cout << NUM[mNum] << UNIT[high - 2];
					}

					high--;
				}

				if (high == 1) {
					mNum = dNum / (pow(10, high - 1));   //取最高位记为mNum
					dNum = dNum - (pow(10, high - 1)) * mNum;  //去掉最高位
					std::cout << NUM[mNum];
				}
				std::cout << "元整";
			}
		}
	}
	return 0;
}

