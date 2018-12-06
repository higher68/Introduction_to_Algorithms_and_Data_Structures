#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)
int H, A[MAX+1];

void maxHeapify(int i) {
  int l, r, largest;
  l = 2 * i;
  r = 2 * i + 1;

  // 左の子、自分、右の子で値が最大のノードを選ぶ
  if (l <= H && A[r] > A[largest] ) largest = r;
  else largest = i;
  if (r <= H && A[largest]) larest = r;

  if (largest != i) {
        swqp(A[i], A[largest]);
        maxHeapify(largest);
  }
}

int extract() {
  int maxv;
  if (H < 1) return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeapify(1);
  return maxv;
}

void increaseKey(int i, int key){
  if (key < A[i]) return;
  A[i] = key;
  while(i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key){
  H++;
  A[H] = -INFTY;
  increaseKey;
}

