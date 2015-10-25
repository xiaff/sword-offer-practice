/*
	面试题43：n个骰子的点数
	把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
	输入n，打印出s的所有可能的值出现的概率。
*/

#include<iostream>
#include<math.h>

using namespace std;

class Solution
{
public:
	const int g_maxValue=6;

	void printProbablity(int n){
		if(n<1){
			return;
		}

		int arrayLength=g_maxValue*n+1;
		int* probs[2];
		probs[0]=new int[arrayLength];
		probs[1]=new int[arrayLength];

		for(int i=0;i<arrayLength;i++){
			probs[0][i]=0;
			probs[1][i]=0;
		}

		int flag=0;
		for(int i=1;i<=g_maxValue;i++){
			probs[flag][i]=1;
		}

		for(int k=2;k<=n;k++){
			for(int i=0;i<k;i++){
				probs[1-flag][i]=0;
			}
			for(int i=k;i<=g_maxValue*k;i++){
				probs[1-flag][i]=0;
				for(int j=1;j<=i&&j<=g_maxValue;j++){
					probs[1-flag][i]+=probs[flag][i-j];
				}
			}
			flag=1-flag;
		}

		double total=pow((double)g_maxValue,n);
		for(int i=n;i<arrayLength;i++){
			double ratio=(double)probs[flag][i]/total;
			cout<<i<<": "<<ratio<<endl;
		}
		
		delete[] probs[0];
		delete[] probs[1];
	}	
};