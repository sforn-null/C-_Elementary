#include<iostream>
//���ճ���ϰ�У����ں�����������ͻ���Ϳ��Խ�stdȫչ��
using namespace std;
//c++�������ж������Ƿŵ�std�����ռ���
//����д���ǽ�std�����ռ�������ж���ȫչ�����涼������


//���õĿ�����һЩ����������Ϳ���չ����
//������Ŀ��ͨ���Ƚ��Ƽ������÷�
using std::cout;//����ǽ�std�����coutչ��
using std::endl;//����ǽ�std�����endlչ��
//����֮��д�Ĵ���Ϳ���ֱ����cout��endl��

int main()
{
	std::cout << "hello world\n";
	//std::����count��std����ģ����ǰ��û��չ������ô
	//������͵������
	//��c++�п�����\n����
	//����һ�㳣��
	std::cout << "hello world" << std::endl;
	//�������end1��һ������endl��L��
	int i = 1;
	double d = 1.11;

	std::cin >> i >> d;
	//cin�������룬ͬ�������Զ�ʶ������

	std::cout << i << " " << d << std::endl;
	//cout��������������Զ�ʶ������
	return 0;
}