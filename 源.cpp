#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int base_time;
int begin_time=0;
struct jcb                                                            //定义作业块
{
	jcb(const string &a,int n)
		:name(a),need_time(n),arrive_time(base_time++){}              //构造函数
	string name;                                                      //作业名
	int need_time;
	int arrive_time;                                                  //每次调用到达时间+1
};
void FCFS(deque<jcb> vec)                                             //先来先服务调度算法
{
	double turn_time = 0;
	double with_authority_turn_time = 0;
	auto n = vec.size();
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout<< "进程名" << iter->name << endl
			<< "开始时间" << begin_time << endl
			<< "完成时间" << begin_time + iter->need_time << endl
			<< "周转时间" << begin_time + iter->need_time -
			iter->arrive_time << endl
			<< "带权周转时间" <<(double) (begin_time + iter->need_time -
				iter->arrive_time) / iter->need_time << endl;
		turn_time += begin_time + iter->need_time -
			iter->arrive_time;                                                    //累加进程周转时间
		with_authority_turn_time += (double)(begin_time + iter->need_time -
			iter->arrive_time) / iter->need_time;                                 //累加进程带权周转时间
		begin_time += iter->need_time;
	 }
	cout << "平均周转时间" << turn_time / n << endl
		<< "平均带权周转时间" << with_authority_turn_time / n << endl;
}                           
void SJF(deque<jcb> vec)
{
	sort(vec.begin(), vec.end(),
		[](jcb a, jcb b)
	{return a.need_time < b.need_time; });    //按最短作业优先排序
	FCFS(vec);                                //调用函数FCFS
}
int main()
{
	cout << "please cin process name,needtime" << endl;
	string a;
	int  n;
	deque<jcb> vec;
	while (cin >> a >> n)                                     //循环输入进程信息                
	{
		jcb process(a,  n);
		vec.push_back(process);
	}
	//FCFS(vec);
	SJF(vec);
	return 0;
}