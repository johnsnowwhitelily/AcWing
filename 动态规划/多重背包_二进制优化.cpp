/*
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2

输出样例：
10
*/

//二进制优化
#include <iostream>
#include <algorithm>
 
 using namespace std;

 const int N = 25000;
 int n,m;//n是物体的种数，m是背包的体积
 int v[N],w[N],s[N];//v[i]是第i种物体的体积，w[i]第i种物体的价值，s[i]第i种物体的数量
 int f[N];//f数组定义为全局变量，默认为0

 int main()
 {
 	cin>>n>>m; 

    int cnt=0;
 	for(int i=1;i<=n;i++) 
    {
        int a,b,s;
        cin>>a>>b>>s;//当前种类物体的体积，价值，个数
        int k=1;//从1开始分包
        while(k<=s)//只要k<=s就可以继续分包（每次把k个物品打包成一个包）
        {
            cnt++;
            v[cnt]=a*k;//v[cnt]是每一个包的体积
            w[cnt]=b*k;//w[cnt]是每一个包的价值
            s-=k;//将已被打包的数量从s中减去
            k*=2;//k按2的幂增长
        }
        if(s>0)
        {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }

    n=cnt;//把n更新成cnt（一共有cnt个包，转化为01背包）
 	for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);

    cout<<f[m]<<endl;

 	return 0;
 }

