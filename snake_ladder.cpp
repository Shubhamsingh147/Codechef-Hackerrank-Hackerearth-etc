#include <iostream>
#include <queue>
using namespace std;
struct node{
    int v;
    int dist;
};
int main()
{
    int t,m,n,x,y;
    cin>>t;
    while(t--)
    {
        int moves[101] = {0};
        int visited[101] = {0};
        bool wonGame = false;
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>x>>y;
            moves[x] = y;
        }
        cin>>m;
        for (int i = 0; i < m; ++i)
        {
            cin>>x>>y;
            moves[x] = y;
        }
        queue <node> q;
        node qe;
        qe.v = 1;
        qe.dist = 0;
        q.push(qe);
        while( !q.empty() )
        {
            qe = q.front();
            int vertex = qe.v;
            int distance = qe.dist;
//            cout<<"Popped out ("<<vertex<<", "<<distance<<")\n";
            if(vertex == 100)
            {
//                cout<<"Yay! Won game!\n";
                wonGame = true;
                break;
            }
            q.pop();
            int j;
            for (j = vertex + 1 ; j <= (vertex + 6) && j <= 100; j++)
            {
                if(!visited[j])
                {
                    visited[j] = 1;
                    node a;
                    a.dist = distance + 1;

                    if(moves[j] != 0)
                        a.v = moves[j];
                    else
                        a.v = j;
//                    cout<<"Pushing in ("<<a.v<<", "<<a.dist<<")\n";
                    q.push(a);
                }
            }
        }
//        cout<<endl;

        if(wonGame)
            cout<<qe.dist<<endl;
        else 
            cout<<"-1"<<endl;
    }
}
/*
10
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70
*/
/*
4
-1
4
-1
4
-1
4
-1
4
-1
*/