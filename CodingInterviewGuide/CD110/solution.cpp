#include<iostream>
using namespace std;

/*
    由于每次删除后都重新报数，所以每次删除的过程中所有人的坐标都会左移m个位置
    而最终删除结果只剩下一个元素，也就是0

    这也就意味着如果我们想得到胜利者的坐标，就需要逆推上面的过程，即不断右移m个位置来恢复原有坐标
*/
void Joseph(int n, int m)
{
    int res = 0;
    for(int i = 2; i <= n; i++)
    {
        res = (res + m) % i;
    }
    cout << res + 1 << endl;
}

int main()
{
    int m, n;
    while(cin >> n >> m)
    {
        Joseph(n, m);
    }
    return 0;
}