#include<iostream>
using namespace std;

int Map[10][10];
int visit[10][10];
int msize;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int start = 0;
int ans;
struct Node{
    int x;
    int y;
    int cnt;
    Node* next;
    Node* prev;
} node[100001];
Node* head, *tail;
int nodeCnt, qSize;

void add1(Node* ptr, int x, int y, int cnt){
    node[nodeCnt].x = x; node[nodeCnt].y = y; node[nodeCnt].cnt = cnt;
    Node* tmp = &node[nodeCnt++];
    tmp->next = ptr->next; tmp->prev = ptr;
    ptr->next->prev = tmp; ptr->next = tmp;
    qSize++;
}
void remove1(Node* ptr){
    ptr->next->prev = head;
    head->next = ptr->next;
    qSize--;
}
void bfs_init(int map_size, int map[10][10]) {
    if(start == 0){
        head = new Node();
        tail = new Node();
        start =1;
    }
    msize = map_size;
    for(int i=0;i<msize;i++){
        for(int j=0;j<msize;j++){
            Map[i][j] = map[i][j];
        }
    }
}

int bfs(int x1, int y1, int x2, int y2) {
    bfs_init(msize, Map);
    int eflag = 0;
    x1--; y1--; x2--; y2--;
    ans = -1;    nodeCnt = 0;    qSize = 0;
    head->next = tail;
    tail->prev = head;
   for(int i=0;i<msize;i++){
        for(int j=0;j<msize;j++){
            visit[i][j] = 0;
        }
    }
    visit[y1][x1] = 1;
    add1(tail->prev,x1,y1,0);
    while(qSize>0){
        if(eflag == 1) break;
        int x = head->next->x;
        int y = head->next->y;
        int cnt = head->next->cnt;
        remove1(head->next);
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == x2 && ny == y2){
                ans =  cnt+1;
                eflag = 1;
                break;
            }
            if(nx<0 || nx>msize || ny<0 || ny>msize || visit[ny][nx] == 1 || Map[ny][nx] == 1) continue;
            visit[ny][nx] =1;
            add1(tail->prev,nx,ny,cnt+1);
        }
    }
    if(eflag == 0) ans = -1;
    return ans;
}

int main(){
    int N;
	int map[10][10];
	cin>>N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin>> map[i][j];
		}
	}
    bfs_init(N, map);
    
    int M;
    scanf("%d",&M);
    for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
        cout<<"result: "<<result<<' ';
		int dist;
		scanf("%d", &dist);
		cout<<"dist: "<<dist<<endl;
	}
}