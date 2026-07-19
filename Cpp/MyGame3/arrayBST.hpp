#include "variable.hpp"
//------------------ functions
int getLeftIdx(int idxIn){
	return (idxIn*2)+1;
}
int getRightIdx(int idxIn){
	return (idxIn*2)+2;
}
void showArray(int **pptrArr){
	for(int i=0;i<CAPACITY;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void addNum(int **pptrArr, int currIdx, int newNum){
	if(array[currIdx]==-1){
		*((*pptrArr)+currIdx)=newNum;
		return ;
	}
	if(array[currIdx]<newNum){
		int rightIdx=getRightIdx(currIdx);
		if(rightIdx<CAPACITY){
			addNum(pptrArr, rightIdx, newNum);	
		}
		else{
			return ;
		}
	}
	else if(array[currIdx]>newNum){
		int leftIdx=getLeftIdx(currIdx);
		if(leftIdx<CAPACITY){
			addNum(pptrArr, leftIdx, newNum);
		}
		else{
			return ;
		}
	}
}
void deleteNum(int **pptrArr, int currIdx, int targetNum){
	while(currIdx<CAPACITY){
		if(array[currIdx]<targetNum){
			deleteNum(pptrArr, getRightIdx(currIdx), targetNum);
		}
		else if(array[currIdx]>targetNum){
			deleteNum(pptrArr, getLeftIdx(currIdx), targetNum);
		}
		else{
			int leftIdx=getLeftIdx(currIdx);
			int rightIdx=getRightIdx(currIdx);
			if((array[leftIdx]==-1)&&(array[rightIdx]==-1)){
				*((*pptr)+currIdx)=-1;
				return ;
			}
			else if(array[leftIdx]==-1){
				*((*pptr)+currIdx)=array[rightIdx];
				return ;
			}
			else if(array[rightIdx]==-1){
				*((*pptr)+currIdx)=array[leftIdx];
				return ;
			}
			else{
				int mostLeftIdx=getLeftIdx(currIdx);
				while(array[getRightIdx(mostLeftIdx)]!=-1){
					if(getRightIdx(mostLeftIdx)<CAPACITY){
						mostLeftIdx=getRightIdx(mostLeftIdx);
					}
					else{
						return ;
					}
				}
				*((*pptr)+currIdx)=*((*pptr)+mostLeftIdx);
				deleteNum(pptrArr, getLeftIdx(currIdx), array[mostLeftIdx]);
			}
		}
	}
}