/*
	面试题42：翻转单词顺序 VS 左旋转字符串
	1. 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
	例如输入字符串"I am a student."，则输出"student. a am I"。
	2. 字符串的左旋转操作是把字符串前面的若干字符转移到字符串的后面。
	请定义一个函数实现字符串左旋转操作的功能，
	比如：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab"。
*/

#include<string>

class Solution
{
public:
	string reverseSentence(string sentence) {
		if (sentence.length()<1) {
			return NULL;
		}

		int senLength = 0;
		for (int i = 0;sentence[i] != '\0';i++) {
			senLength++;
		}

		reverseStr(sentence, 0, senLength - 1);

		for (int i = 0, j = 0;i < senLength;) {
			if (sentence[i] == ' ') {
				i++;
				j++;
			}
			else if (sentence[j] == ' ' || sentence[j] == '\0') {
				reverseStr(sentence, i, j - 1);
				i = j;
			}
			else {
				j++;
			}
		}

		return sentence;
	}

	string leftRotateString(string word,int n){
		if(word.length()<1){
			return NULL;
		}

		reverseStr(word,0,n-1);
		reverseStr(word,n,word.length()-1);
		reverseStr(word, 0, word.length() - 1);
		return word;
	}

private:
	void reverseStr(string& str, int start, int end) {
		if (start >= end || str.length()<1) {
			return;
		}

		for (int i = start, j = end;i<j;i++, j--) {
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}

};