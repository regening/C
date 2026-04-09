// 一条街从1到2020号 现要制作门牌号 比如2020要制作2 0 2 0四个数字排
// 问我要做这条街的门牌号 需要几个2
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main () { // 转成字符串 
	int num = 0;
	for (int i=1; i<2021; i++) {
		string s = to_string(i);
		for (char c : s) { // 遍历s复制每一个字符到c 
			if (c == '2') {
				num++;
			} 
		} 
	}
	printf("%d", num);
	return 0;
}  

/* 数学方法 
int mathmo (int n) {
	int count = 0;
	while (n > 0) {
		if (n % 10 == 2) { // 取最后一位看是不是2 
			count++;
		}
		n /= 10; // 去掉最后一位 
	}
	return count;
}

int main () {
	int num = 0;
	for (int i=1; i < 2021; i++) {
		num += mathmo(i);
	}
	printf("%d", num);
	return 0;
}
*/
