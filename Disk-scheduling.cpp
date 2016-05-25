#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
//先来先服务算法实现
void FCFS(vector<int> vec)                                           
{
	double track_seeking_length = 0;                                 //寻道长度
		track_seeking_length+=	abs(*vec.begin() - 100);
	int n = vec.size();
	cout << "FCFS寻道路径:     "<< "100->";
	for (auto iter = vec.begin(); iter != vec.end()-1; ++iter)
	{
		track_seeking_length += abs(*(iter + 1) - *iter);            //abs绝对值函数
		cout << *iter << "->";
	}
	cout << *(vec.end() - 1) << endl;
	cout <<"FCFS平均寻道时间:     "<< track_seeking_length/n << endl;
	
}
//最短寻道时间优先算法实现
void SSTF(vector<int> vec)
{
	double track_seeking_length = 0;        //寻道时间
	int key =100;
	int n = vec.size();
	cout << "SSTF寻道路径:     " << "100->";
	map<int, int> ma;
	for (auto c : vec)
	{
		ma.insert({ abs(c - key),c });
	}
	cout << ma.begin()->second << "->";
	track_seeking_length = ma.begin()->first;
	key = ma.begin()->second;
	ma.erase(ma.begin()->first);
	while (!ma.empty())
	{
		map<int, int> tmp;
		for (auto iter = ma.begin(); iter != ma.end();++iter)
		tmp.insert({ abs(iter->second - key),iter->second });
		cout << tmp.begin()->second << "->";
		key = tmp.begin()->second;
		track_seeking_length += tmp.begin()->first;
		for (auto b = ma.begin(); b!= ma.end(); ++b)
		{
			if (b->second == key)
			{
				ma.erase(b->first);
				break;
			}
			
		}
	}
	cout << endl;
	cout << "SSTF平均寻道时间：  "<<track_seeking_length/n << endl;
}
//扫描算法实现
void SCAN(vector<int> vec)
{
	int begin_track_num = 100;
	double track_seeking_length = 0;
	int n = vec.size();
	int tmp = 0;
	cout << "SCAN寻道路径： " << begin_track_num << "->";
	vector<int> big_tmp,min_tmp;
	for (auto c : vec)
		if (c > begin_track_num)
			big_tmp.push_back(c);
		else
			min_tmp.push_back(c);
	sort(big_tmp.begin(), big_tmp.end());
	sort(min_tmp.begin(), min_tmp.end(),
		[](int a, int b) {return a > b; });
	track_seeking_length = *big_tmp.begin() - begin_track_num;     //计算开始和第一个磁道之间的磁道数
	track_seeking_length += *(big_tmp.end() - 1) - *min_tmp.begin(); //计算磁道折回来时移动的磁道数
	for (auto c: big_tmp)
	{
		cout << c << "->";
	}
	for (auto c : min_tmp)
	{
		cout << c << "->";
	}
	for (auto iter = big_tmp.begin(); iter != big_tmp.end() - 1; ++iter) 
	{
		track_seeking_length += *(iter + 1) - *iter;
	}
	for (auto iter = min_tmp.begin(); iter != min_tmp.end() - 1; ++iter)
	{
		track_seeking_length += *iter - *(iter + 1);
	}
	cout << endl<<"SCAN平均寻道时间： "<< track_seeking_length / n << endl;

}
void CSCAN(vector<int> vec)
{
	int begin_track_num = 100;
	double track_seeking_length = 0;
	int n = vec.size();
	int tmp = 0;
	cout << "CSCAN寻道路径： " << begin_track_num << "->";
	vector<int> big_tmp, min_tmp;
	for (auto c : vec)
		if (c > begin_track_num)
			big_tmp.push_back(c);
		else
			min_tmp.push_back(c);
	sort(big_tmp.begin(), big_tmp.end());
	sort(min_tmp.begin(), min_tmp.end(),
		[](int a, int b) {return a< b; });
	track_seeking_length = *big_tmp.begin() - begin_track_num;     //计算开始和第一个磁道之间的磁道数
	track_seeking_length += *(big_tmp.end() - 1) - *min_tmp.begin(); //计算磁道折回来时移动的磁道数
	for (auto c : big_tmp)
	{
		cout << c << "->";
	}
	for (auto c : min_tmp)
	{
		cout << c << "->";
	}
	for (auto iter = big_tmp.begin(); iter != big_tmp.end() - 1; ++iter)
	{
		track_seeking_length += *(iter + 1) - *iter;
	}
	for (auto iter = min_tmp.begin(); iter != min_tmp.end() - 1; ++iter)
	{
		track_seeking_length += *(iter + 1) - *iter;
	}
	cout << endl << "CSCAN平均寻道时间： " << track_seeking_length / n << endl;

}
int  main()
{
	vector<int> vec;
	int a;
	while (cin >> a)
		vec.push_back(a);
	FCFS(vec);
	SSTF(vec);
	SCAN(vec);
	CSCAN(vec);
	return 0;
}
