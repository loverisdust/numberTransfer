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
