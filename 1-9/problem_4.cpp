/*
	面试题4：替换空格
	请实现一个函数，把字符串中的每个空格替换成“%20”。
	例如输入“We are happy.”，则输出“We%20are%20happy.”。
*/

class Soultion
{
public:
	void replaceBlank(char sentence[],int length){
		if(sentence==NULL&&length<=0){
			return;
		}

		int originnalLength=0;
		int numberOfBlanks=0;
		char c;
		for(int i=0;(c=sentence[i])!='\0';i++){
			originnalLength++;
			if(c==' '){
				numberOfBlanks++;
			}
		}

		int newLength=originnalLength+2*numberOfBlanks;
		if(newLength>length){
			return;
		}

		int indexOfOriginal=originnalLength;
		int indexOfNew=newLength;
		while(indexOfOriginal>=0&&indexOfNew>indexOfOriginal){
			if(sentence[indexOfOriginal]==' '){
				sentence[indexOfNew--]='0';
				sentence[indexOfNew--]='2';
				sentence[indexOfNew--]='%';
			}else{
				sentence[indexOfNew--]=sentence[indexOfOriginal];
			}
			indexOfOriginal--;
		}
	}
	
};