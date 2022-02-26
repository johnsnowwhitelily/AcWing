//有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次
//第 i 件物品的体积是 vi，价值是 wi。
//求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

//输入格式
//第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
//接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

//输出格式
//输出一个整数，表示最大价值。

//数据范围
//0<N,V≤1000
//0<vi,wi≤1000

//输入样例
//4 5
//1 2
//2 4
//3 4
//4 5

//输出样例：
//8

 //优化算法
#include <iostream>
#include <algorithm>
 
 using namespace std;

 const int N = 1010;
 int n,m;//n是物体的数量，m是背包的体积
 int v[N],w[N];//v[i]是第i个物体的体积，w[i]第i个物体的价值
 //  f(i, 这一层只用到了f（i-1, 这一层 滚动数组
 int f[N];//int f[N][N];

 int main()
 {
 	cin>>n>>m; 
 	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];//读入所有物品的体积和价值

 	//f[0~n][0~m]枚举所有的状态
 	//如f[0][m]表示一共0件物品，总体积不超过m的最大价值
 	//由于0件物品的价值为0，所以f[0][0~m]=0

 	for(int i=1;i<=n;i++)//从1件物品开始枚举
 		for (int j=m;j>=v[i];j--)//枚举所有的体积	
            //f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);	
                f[j]=max(f[j],f[j-v[i]]+w[i]);//f[]是从大向小更新，f[j-v[i]]还停在上一层

 	cout<<f[m]<<endl;

 	return 0;
 }