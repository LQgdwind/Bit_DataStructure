#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "queue"
#include "cstdio"
#include "cstring"

using namespace std;

typedef pair<int, int> PII;
queue <int> takeoff;
queue <int> landon;
vector <PII> paodao;

bool isnull[100001];

int n;
int timeoftakeoff;
int timeoflandon;
int numberoftakeoff = 0;
int numberoflandon = 0;

int waitingtimeoftakeoff = 0;
int waitingtimeoflandon = 0;


int runwayoccupy[100001];
bool flag = false;

int main()
{
	memset(runwayoccupy, 0, sizeof(runwayoccupy));
	memset(isnull, 0, sizeof(isnull));
	cin >> n >>timeoflandon>> timeoftakeoff;
	loop(i, 1, n+1)
	{
		paodao.push_back({ 0,0 });
	}
	int currenttime = -1;
	int takeoffperminute=1;
	int landonperminute=1;
	int airplanetakeoff = 0;
	int airplanelandon = 5000;
	while (landonperminute >= 0 && takeoffperminute>=0)
	{
		printf("Current Time: %4d\n", ++currenttime);
		if (currenttime > 0) loop(i, 1, n)
		{
			if (paodao[i].second == 0 && isnull[i])
			{
				printf("runway %02d is free\n", i);
				isnull[i] = false;
			}
		}
		cin >> landonperminute >> takeoffperminute;
		if (takeoffperminute >= 0) numberoftakeoff += takeoffperminute;
		if (landonperminute >= 0) numberoflandon += landonperminute;
		waitingtimeoflandon += landon.size();
		waitingtimeoftakeoff += takeoff.size();
		loop(i, 1, landonperminute)
		{
			landon.push(++airplanelandon);
		}
		loop(i, 1, takeoffperminute)
		{
			takeoff.push(++airplanetakeoff);
		}
		loop(i, 1, n)
		{
			if (paodao[i].second == 0)
			{
				if (landon.size() > 0)
				{
					paodao[i].first = landon.front();
					paodao[i].second = timeoflandon;
					landon.pop();
					printf("airplane %04d is ready to land on runway %02d\n", paodao[i].first, i);
					runwayoccupy[i]++;
					paodao[i].second--;
					if (paodao[i].second == 0) isnull[i] = true;
				}
				else if (takeoff.size() > 0)
				{
					paodao[i].first = takeoff.front();
					paodao[i].second = timeoftakeoff;
					takeoff.pop();
					printf("airplane %04d is ready to takeoff on runway %02d\n", paodao[i].first, i);
					runwayoccupy[i]++;
					paodao[i].second--;
					if (paodao[i].second == 0) isnull[i] = true;
				}
			}
			else
			{
				paodao[i].second--;
				if (paodao[i].second == 0) isnull[i] = true;
				runwayoccupy[i]++;
			}
		}
	}
	while (true)
	{
		printf("Current Time: %4d\n", ++currenttime);
		if (currenttime > 0) loop(i, 1, n)
		{
			if (paodao[i].second == 0 && isnull[i])
			{
				printf("runway %02d is free\n", i);
				isnull[i] = false;
			}
		}
		waitingtimeoflandon += landon.size();
		waitingtimeoftakeoff += takeoff.size();
		loop(i, 1, n)
		{
			if (paodao[i].second != 0)
			{
				break;
			}
			if (i == n)
			{
				if (paodao[n].second == 0 && takeoff.empty() && landon.empty())
				{
					flag = true;
				}
			}
		}
		if (flag) break;
		loop(i, 1, n)
		{
			if (paodao[i].second == 0)
			{
				if (landon.size() > 0)
				{
					paodao[i].first = landon.front();
					paodao[i].second = timeoflandon;
					landon.pop();
					printf("airplane %04d is ready to land on runway %02d\n", paodao[i].first, i);
					runwayoccupy[i]++;
					paodao[i].second--;
					if (paodao[i].second == 0) isnull[i] = true;
				}
				else if (takeoff.size() > 0)
				{
					paodao[i].first = takeoff.front();
					paodao[i].second = timeoftakeoff;
					takeoff.pop();
					printf("airplane %04d is ready to takeoff on runway %02d\n", paodao[i].first, i);
					runwayoccupy[i]++;
					paodao[i].second--;
					if (paodao[i].second == 0) isnull[i] = true;
				}
			}
			else
			{
				paodao[i].second--;
				if (paodao[i].second == 0) isnull[i] = true;
				runwayoccupy[i]++;
			}
		}
	}
	int totoloccupy = 0;
	cout << "simulation finished" << endl;
	printf("simulation time: %4d\n", currenttime);
	if(numberoflandon>0) printf("average waiting time of landing: %4.1f\n",(double)waitingtimeoflandon/ (double)numberoflandon);
	else printf("average waiting time of landing: %4.1f\n", 0.0);
	if(numberoftakeoff>0)printf("average waiting time of takeoff: %4.1f\n",(double)waitingtimeoftakeoff / (double)numberoftakeoff);
	else printf("average waiting time of landing: %4.1f\n", 0.0);
	loop(i, 1, n)
	{
		printf("runway %02d busy time: %4d\n",i,runwayoccupy[i]);
		totoloccupy += runwayoccupy[i];
	}
	currenttime *= n;
	totoloccupy *= 100;
	printf("runway average busy time percentage: %4.1f%%\n",(double)totoloccupy/(double)currenttime);
	return 0;
}