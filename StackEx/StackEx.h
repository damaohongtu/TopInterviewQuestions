#pragma once
#include<stack>
/********** 压栈，弹出序列 **************/
bool isPopOrder(const int*pPush,const int*pPop,int nLength) {
	bool bPossible = false;
	if (pPush!=nullptr&&pPop!=nullptr&&nLength>0) {
		const int *pPushNext = pPush;
		const int *pPopNext = pPop;

		std::stack<int>stackData;
		while (pPopNext-pPop<nLength)
		{
			while (stackData.empty()||stackData.top()!=*pPopNext) {
				if (pPushNext-pPush==nLength) {
					break;//数据压完了break，stackData.top()==*pPopNext是无法保证的
				}
				stackData.push(*pPushNext);
				pPushNext++;
			}
			//一旦前一个循环终止，栈顶元素一定要与*pPopNext相等
			//不相等的情况出现的时候数据已经全部压入，上面的循环break
			if (stackData.top()!=*pPopNext) {
				break;//大循环break
			}
			stackData.pop();
			pPopNext++;
		}
		//以下任何一个判断条件都是ok的
		if (stackData.empty()&&pPopNext-pPop==nLength) {
			bPossible = true;
		}
	}
	return bPossible;
}