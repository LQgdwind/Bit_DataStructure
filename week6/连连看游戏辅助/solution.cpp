#include "bits/stdc++.h"
const int N = 1e3 + 10;int Graph[N][N],visit[N][N];
int m, n, StartX, StartY, targetx, targety; bool mark;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
class Node
{
public:
    int x, y, direction, transfer;
    Node() :x(0), y(0), direction(0), transfer(0) {};
};
void BFS()
{
    mark = false;std::queue<Node> q;Node x0, guodu, x1;
    for (int i = 0; i < 4; i++)x1.x = StartX + dx[i], x1.y = StartY + dy[i], x1.direction = i, x1.transfer = 1,visit[x1.x][x1.y] = x1.transfer,q.push(x1);
    while (q.size())
    {
        x0 = q.front(), q.pop();
        if (x0.x == targetx && x0.y == targety)
        {
            mark = true,std::cout << "TRUE" << std::endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            guodu.x = x0.x + dx[i],guodu.y = x0.y + dy[i],guodu.direction = i;
            if (guodu.direction != x0.direction)guodu.transfer = x0.transfer + 1;
            else guodu.transfer = x0.transfer;
            if (guodu.transfer > 3 || guodu.x < 0 || guodu.y < 0 || guodu.x > m - 1 || guodu.y > n - 1)continue;
            if (Graph[guodu.x][guodu.y] != 0 && Graph[guodu.x][guodu.y] != Graph[targetx][targety]) continue;
            if (visit[guodu.x][guodu.y] == 0 || visit[guodu.x][guodu.y] >= guodu.transfer) visit[guodu.x][guodu.y] = guodu.transfer,q.push(guodu);
        }
    }
    if (!mark) std::cout << "FALSE" << std::endl;
}
int main()
{
    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
       for (int j = 0; j < n; j++)
            std::cin >> Graph[i][j];
    std::cin >> StartX >> StartY >> targetx >> targety, BFS();
    return 0;
}
