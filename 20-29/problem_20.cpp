/*
	面试题20：顺时针打印矩阵
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，  
	例如，如果输入如下矩阵：  
	1 2 3 4   
	5 6 7 8   
	9 10 11 12   
	13 14 15 16 ，  
	则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10。
*/

#include<iostream>

class Solution
{
public:
	void printMatrixClockWisely(int** numbers,int columns,int rows){
		if(numbers==NULL||columns<=0||rows<=0){
			return;
		}

		for(int start=0;(start*2<columns)&&(start*2<rows);start++){
			printMatrixInCircle(numbers,columns,rows,start);
		}
	}
	
private:
	void printMatrixInCircle(int** numbers,int columns,int rows,int start){
		int endX=columns-start-1;
		int endY=rows-start-1;

		//从左到右 第一行
		for(int x=start;x<=endX;x++){
			printNumber(numbers[start][x]);
		}

		//从上到下 最后一列
		for(int y=start+1;y<=endY;y++){
			printNumber(numbers[y][endX]);
		}

		//从右到左 最后一行
		for(int x=endX-1;x>=start;x--){
			printNumber(numbers[endY][x]);
		}

		//从下到上 第一列
		for(int y=endY-1;y>start;y--){
			printNumber(numbers[y][start]);
		}

	}

	void printNumber(int number){
		std::cout<<number<<" ";
	}
};