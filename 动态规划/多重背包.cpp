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
0<N,V≤100
0<vi,wi,si≤100

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2

输出样例：
10
*/

//朴素算法
#include <iostream>
#include <algorithm>
 
 using namespace std;

 const int N = 110;
 int n,m;//n是物体的种数，m是背包的体积
 int v[N],w[N],s[N];//v[i]是第i种物体的体积，w[i]第i种物体的价值，s[i]第i种物体的数量
 int f[N][N];//f数组定义为全局变量，默认为0

 int main()
 {
 	cin>>n>>m; 
 	for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];//读入所有物品的体积、价值、数量

 	for(int i=1;i<=n;i++)//从只有第一种物品开始枚举
 		for (int j=v[i];j<=m;j++)//枚举所有的体积
 			for(int k=0;k*v[i]<=j&&k<=s[i];k++)//枚举第i种物体可能的个数
 				f[i][j]=max(f[i-1][j],f[i-1][j-v[i]*k]+w[i]*k);//右边的集合当j<v[i]时为空集

 	cout<<f[n][m]<<endl;

 	return 0;
 }

