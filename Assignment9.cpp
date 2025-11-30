//1
// #include <iostream>
// #include <queue>
// using namespace std;

// int main(){
//     int n = 5;
//     int g[5][5] = {
//         {0,1,1,0,0},
//         {1,0,0,1,0},
//         {1,0,0,1,1},
//         {0,1,1,0,1},
//         {0,0,1,1,0}
//     };

//     bool vis[5] = {0};

//     queue<int> q;

//     q.push(0);
//     vis[0] = true;

//     while(!q.empty()){
//         int v = q.front();
//         q.pop();

//         cout << v << " ";

//         for(int i=0;i<n;i++){
//             if(g[v][i] && !vis[i]){
//                 vis[i]=true;
//                 q.push(i);
//             }
//         }
//     }
// }



//2
// #include <iostream>
// using namespace std;

// void dfs(int v,bool vis[],int g[5][5]){
//     cout << v << " ";
//     vis[v] = true;

//     for(int i=0;i<5;i++){
//         if(g[v][i] && !vis[i])
//             dfs(i,vis,g);
//     }
// }

// int main(){
//     int g[5][5] = {
//         {0,1,1,0,0},
//         {1,0,0,1,0},
//         {1,0,0,1,1},
//         {0,1,1,0,1},
//         {0,0,1,1,0}
//     };

//     bool vis[5]={0};

//     dfs(0,vis,g);
// }



//3(a)
// #include <iostream>
// using namespace std;

// struct Edge{
//     int u,v,w;
// };

// int find(int p[], int i){
//     while(p[i]!=i)
//         i=p[i];
//     return i;
// }

// void unite(int p[],int x,int y){
//     p[x]=y;
// }

// int main(){
//     int n=4;
//     Edge e[]={
//         {0,1,10},
//         {0,2,6},
//         {0,3,5},
//         {1,3,15},
//         {2,3,4}
//     };

//     int m=5;

//     for(int i=0;i<m-1;i++)
//         for(int j=i+1;j<m;j++)
//             if(e[i].w > e[j].w){
//                 Edge t=e[i];
//                 e[i]=e[j];
//                 e[j]=t;
//             }

//     int parent[n];
//     for(int i=0;i<n;i++)
//         parent[i]=i;

//     int cnt=0,i=0;
//     while(cnt<n-1){
//         Edge cur=e[i++];
//         int x=find(parent,cur.u);
//         int y=find(parent,cur.v);

//         if(x!=y){
//             cout<<cur.u<<" "<<cur.v<<" "<<cur.w<<endl;
//             unite(parent,x,y);
//             cnt++;
//         }
//     }
// }




//3(b)
// #include <iostream>
// #include <climits>
// using namespace std;

// int main(){
//     int n=5;

//     int g[5][5]={
//         {0,2,0,6,0},
//         {2,0,3,8,5},
//         {0,3,0,0,7},
//         {6,8,0,0,9},
//         {0,5,7,9,0}
//     };

//     bool mst[5]={0};
//     int key[5];
//     int parent[5];

//     for(int i=0;i<n;i++){
//         key[i]=INT_MAX;
//         parent[i]=-1;
//     }

//     key[0]=0;

//     for(int c=0;c<n-1;c++){
//         int mn=INT_MAX,u=0;

//         for(int v=0;v<n;v++)
//             if(!mst[v] && key[v]<mn){
//                 mn=key[v];
//                 u=v;
//             }

//         mst[u]=true;

//         for(int v=0;v<n;v++){
//             if(g[u][v] && !mst[v] && g[u][v]<key[v]){
//                 key[v]=g[u][v];
//                 parent[v]=u;
//             }
//         }
//     }

//     for(int i=1;i<n;i++)
//         cout<<parent[i]<<" "<<i<<" "<<g[i][parent[i]]<<endl;
// }


//4
// #include <iostream>
// #include <climits>
// using namespace std;

// int main(){
//     int n=5;

//     int g[5][5]={
//         {0,10,0,5,0},
//         {0,0,1,2,0},
//         {0,0,0,0,4},
//         {0,3,9,0,2},
//         {7,0,6,0,0}
//     };

//     int dist[5];
//     bool vis[5]={0};

//     for(int i=0;i<n;i++)
//         dist[i]=INT_MAX;

//     dist[0]=0;

//     for(int c=0;c<n-1;c++){
//         int mn=INT_MAX,u=0;

//         for(int i=0;i<n;i++)
//             if(!vis[i] && dist[i]<mn){
//                 mn=dist[i];
//                 u=i;
//             }

//         vis[u]=true;

//         for(int v=0;v<n;v++){
//             if(!vis[v] && g[u][v] &&
//                dist[u]!=INT_MAX &&
//                dist[u]+g[u][v] < dist[v]){

//                 dist[v]=dist[u]+g[u][v];
//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//         cout<<"0 -> "<<i<<" = "<<dist[i]<<endl;
// }