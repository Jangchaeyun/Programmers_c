#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX 1010
#define TRAP_MAX 10
#define INF 987654321
#define MOD 1000000007

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair key;
    bool value;
} Edge;

Edge MAP[MAX][MAX];
bool Is_Trap[MAX];
int Trap_Index[MAX];
int Dist[MAX][1 << TRAP_MAX];

int Min(int A, int B) { return A < B ? A : B; }

void Setting(int N, int roads[][3], size_t roads_rows) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            MAP[i][j].key.first = 0;
            MAP[i][j].key.second = 0;
            MAP[i][j].value = false;
        }
        for (int j = 0; j < (1 << TRAP_MAX); j++) {
            Dist[i][j] = INF;
        }
    }

    for (size_t i = 0; i < roads_rows; i++) {
        int S = roads[i][0];
        int E = roads[i][1];
        int D = roads[i][2];

        MAP[S][E].key.first = E;
        MAP[S][E].key.second = D;
        MAP[S][E].value = true;

        MAP[E][S].key.first = S;
        MAP[E][S].key.second = D;
        MAP[E][S].value = false;
    }
}

void Make_Trap_Info(int traps[], size_t traps_len) {
    for (size_t i = 0; i < traps_len; i++) {
        int N = traps[i];
        Is_Trap[N] = true;
        Trap_Index[N] = i;
    }
}

int Find_Min_Cost(int E) {
    int Result = INF;
    for (int i = 0; i < (1 << TRAP_MAX); i++) {
        Result = Min(Result, Dist[E][i]);
    }
    return Result;
}

bool Trap_State(int Next, int State) {
    return (State & (1 << Trap_Index[Next])) != 0;
}

int Active_Trap(int State, int Idx) { return State | (1 << Trap_Index[Idx]); }

int UnActive_Trap(int State, int Idx) { return State ^ (1 << Trap_Index[Idx]); }

int Dijkstra(int N, int S, int E) {
    typedef struct {
        int cost;
        int node;
        int state;
    } QueueNode;

    QueueNode queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (QueueNode){0, S, 0};
    Dist[S][0] = 0;

    while (front < rear) {
        QueueNode current = queue[front++];
        int Cur = current.node;
        int Cost = current.cost;
        int State = current.state;

        for (int Next = 1; Next <= N; Next++) {
            if (MAP[Cur][Next].key.first == 0) continue;

            int Next_Cost = MAP[Cur][Next].key.second + Cost;
            int Next_State = State;
            bool Edge_State = MAP[Cur][Next].value;

            bool Cur_Trap_State = Is_Trap[Cur] ? Trap_State(Cur, State) : false;
            bool Next_Trap_State = Is_Trap[Next] ? Trap_State(Next, State) : false;

            if ((Cur_Trap_State ^ Next_Trap_State) == Edge_State) {
                if (Is_Trap[Next]) {
                    if (Next_Trap_State) {
                        Next_State = UnActive_Trap(Next_State, Next);
                    } else {
                        Next_State = Active_Trap(Next_State, Next);
                    }
                }

                if (Dist[Next][Next_State] > Next_Cost) {
                    Dist[Next][Next_State] = Next_Cost;
                    queue[rear++] = (QueueNode){Next_Cost, Next, Next_State};
                }
            }
        }
    }
    return Find_Min_Cost(E);
}

int solution(int n, int start, int end, int roads[][3], size_t roads_rows, int traps[], size_t traps_len) {
    Setting(n, roads, roads_rows);
    Make_Trap_Info(traps, traps_len);
    return Dijkstra(n, start, end);
}
