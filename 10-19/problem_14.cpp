/*
	面试题14：调整数组顺序使奇数位于偶数前面
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分。
*/

class Solution
{
public:
    void reOrderArray(vector<int> &array) {
        int length=array.size();
        if(length<=1){
        	return;
        }

        int pStart=0;
        int pEnd=length-1;

        while(pStart<pEnd){
        	while((pStart<pEnd) && (array[pStart]&0x1==1)){
        		pStart++;
        	}
        	while((pStart<pEnd)&&(array[pEnd]&0x1)==0){
        		pEnd--;
        	}
        	if(pStart<pEnd){
        		int temp=array[pStart];
        		array[pStart]=array[pEnd];
        		array[pEnd]=temp;
        	}
        }
    }
	
};