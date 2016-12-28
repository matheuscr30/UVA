#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mi;

#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pi(a) printf("%d\n",a)
#define nl printf("\n");
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define f(i,a,b) for(i=a;i<b;i++)
#define rf(i,a,b) for(i=a;i>=b;i--)
#define clr(x,a) memset(x,a,sizeof(x))
#define MAX 300010
#define MOD 1000000007

/*
On observation it can be seen that it is a problem of Range Max Query as the sequence given is non-decreasing..

Here cnt[] is used to store the cnt of each number and srt[] and ed[] store the starting index and ending index of element respectively.

Segment tree is formed from array of count of elements(cnt[]).
*/


class SegmentTree{
    private:
        vi st,A;
        int n;

    int left(int p){
        return (p << 1);
    }
    int right(int p){
        return ((p << 1)+1);
    }

    void build(int p,int L,int R){
        if(L==R){
            st[p]=A[L];
        }
        else{
            int p1,p2;
            build(left(p),L,((L+R) >> 1));
            build(right(p),((L+R) >> 1)+1,R);
            p1=st[left(p)];p2=st[right(p)];
            st[p]=((p1>=p2) ? p1 : p2);
        }
    }

    int rmq(int p,int L,int R,int i,int j){
        if(i>R || j<L) return -1;
        if(L>=i && R<=j) return st[p];
        int p1,p2;
        p1=rmq(left(p),L,((L+R) >> 1),i,j);
        p2=rmq(right(p),((L+R) >> 1)+1,R,i,j);
        if(p2==-1) return p1;
        if(p1==-1) return p2;
        return ((p1>=p2) ? p1 : p2);
    }

    public:
        SegmentTree(const vi &_A){
            A=_A;n=(int)A.size();
            st.assign(4*n,0);
            build(1,0,n-1);
        }
        int rmq(int i,int j){
            return rmq(1,0,n-1,i,j);
        }
};

int n,m,a[MAX],cnt[MAX],srt[MAX],ed[MAX];

int main(){
    int q,r,k,i,c=0,x=0,y=0,j,t,l,z,x1=0,y1=0;
    ll ans=0;string p;

    while(1){
        si(n);
        if(n==0)
            break;
        si(q);
        clr(cnt,0);
        f(i,0,n){
            si(a[i]);
            a[i]+=150000;

//a[i] is increased by arbitary number as the input can be negative....

            cnt[a[i]]++;
            if(cnt[a[i]]==1)
                srt[a[i]]=i;
        }
        vi A;
        f(i,0,n){
            A.pb(cnt[a[i]]);
            ed[a[i]]=srt[a[i]]+cnt[a[i]]-1;
        }

/*
Within a given range (x,y)::
            If  st[a[x]]=x  &&  ed[a[y]]=y  then the answer of given range would be the max of cnt in that range that can be solved using Range Max Query on cnt[] so cnt[] is used to make segment tree....
*/

        SegmentTree st(A);
        while(q--){
            sii(x,y);
            x--;y--;

//  If starting and ending index has same element then answer is (y-x+1)..

            if(a[x]==a[y])
                pi(y-x+1);
            else{

/*
if starting element is some a[x] and ending element is some a[y] then
Count of elements of a[x] in given range = ed[a[x]]-x+1
Count of elements of a[y] in given range = y-srt[a[y]]+1
And the remaining mid interval can be calculated from Range Max Query of it from segment tree...
answer is max of above three counts....
*/

                int c1=0,c2=0,c3=0;
                c1=ed[a[x]]-x+1;
                c2=y-srt[a[y]]+1;
                x1=ed[a[x]]+1;y1=srt[a[y]]-1;
                if(y1>=x1)
                    c3=st.rmq(x1,y1);
                ans=max(c1,max(c2,c3));
                pi(ans);
            }
        }
    }

    return 0;
}
