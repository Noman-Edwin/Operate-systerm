#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int base_time;
int begin_time=0;
struct jcb                                                            //������ҵ��
{
	jcb(const string &a,int n)
		:name(a),need_time(n),arrive_time(base_time++){}              //���캯��
	string name;                                                      //��ҵ��
	int need_time;
	int arrive_time;                                                  //ÿ�ε��õ���ʱ��+1
};
void FCFS(deque<jcb> vec)                                             //�����ȷ�������㷨
{
	double turn_time = 0;
	double with_authority_turn_time = 0;
	auto n = vec.size();
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout<< "������" << iter->name << endl
			<< "��ʼʱ��" << begin_time << endl
			<< "���ʱ��" << begin_time + iter->need_time << endl
			<< "��תʱ��" << begin_time + iter->need_time -
			iter->arrive_time << endl
			<< "��Ȩ��תʱ��" <<(double) (begin_time + iter->need_time -
				iter->arrive_time) / iter->need_time << endl;
		turn_time += begin_time + iter->need_time -
			iter->arrive_time;                                                    //�ۼӽ�����תʱ��
		with_authority_turn_time += (double)(begin_time + iter->need_time -
			iter->arrive_time) / iter->need_time;                                 //�ۼӽ��̴�Ȩ��תʱ��
		begin_time += iter->need_time;
	 }
	cout << "ƽ����תʱ��" << turn_time / n << endl
		<< "ƽ����Ȩ��תʱ��" << with_authority_turn_time / n << endl;
}                           
void SJF(deque<jcb> vec)
{
	sort(vec.begin(), vec.end(),
		[](jcb a, jcb b)
	{return a.need_time < b.need_time; });    //�������ҵ��������
	FCFS(vec);                                //���ú���FCFS
}
int main()
{
	cout << "please cin process name,needtime" << endl;
	string a;
	int  n;
	deque<jcb> vec;
	while (cin >> a >> n)                                     //ѭ�����������Ϣ                
	{
		jcb process(a,  n);
		vec.push_back(process);
	}
	//FCFS(vec);
	SJF(vec);
	return 0;
}