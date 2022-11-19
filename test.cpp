
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




