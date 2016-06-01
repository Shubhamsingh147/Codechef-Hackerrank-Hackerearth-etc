#include<stdio.h>
int ans,c,n,a[102],v[102],max[502][502],index;
int maximum(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int cal()
{
    int i,j;
    for(j=1;j<=c;j++)
    {
        if(j==a[0])
        max[0][j]=v[0];
        else
        max[0][j]=0;
       for(i=1;i<n;i++)
        {
            int val=0;
            if(j>=a[i])
            val=maximum(max[i-1][j],max[i-1][j-a[i]]+v[i]);
            else
            val=max[i-1][j];
            max[i][j]=val;
        }
        if(max[n-1][j]>ans)
        {
            ans=max[n-1][j];
            index=j;
        }
    }
}
int main()
{
    int i;
    while(1)
    {
        ans=0;
        scanf("%d%d",&c,&n);
        if(c==0 && n==0)
        break;
        for(i=0;i<n;i++)
        scanf("%d%d",&a[i],&v[i]);
        cal();
        printf("%d %d\n",index,ans);
    }
    return 0;
}