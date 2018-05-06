#pragma once
#include<stack>
/********** ѹջ���������� **************/
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
					break;//����ѹ����break��stackData.top()==*pPopNext���޷���֤��
				}
				stackData.push(*pPushNext);
				pPushNext++;
			}
			//һ��ǰһ��ѭ����ֹ��ջ��Ԫ��һ��Ҫ��*pPopNext���
			//����ȵ�������ֵ�ʱ�������Ѿ�ȫ��ѹ�룬�����ѭ��break
			if (stackData.top()!=*pPopNext) {
				break;//��ѭ��break
			}
			stackData.pop();
			pPopNext++;
		}
		//�����κ�һ���ж���������ok��
		if (stackData.empty()&&pPopNext-pPop==nLength) {
			bPossible = true;
		}
	}
	return bPossible;
}