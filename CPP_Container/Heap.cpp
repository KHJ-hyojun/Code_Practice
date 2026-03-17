#include <iostream>

using namespace std;

class MaxHeap
{
private:
    int *arr;     // 동적 배열 포인터
    int capacity; // 배열의 최대 용량
    int size;     // 현재 힙에 들어있는 실제 데이터 개수

    // 💡 [Vector 복습 미션 1] 공간 2배 확장 엔진
    void resize()
    {
        // 1. 기존 capacity를 2배로 늘립니다.
        capacity *= 2;
        // 2. 새로운 capacity(+1)만큼 새로운 동적 배열을 할당합니다.
        int *new_arr = new int[capacity + 1];
        // 3. 기존 배열의 데이터를 새로운 배열로 전부 복사합니다. (1번 인덱스부터 size까지)
        for (int i = 1; i <= size; i++)
        {
            new_arr[i] = arr[i];
        }
        // 4. 기존 배열의 메모리를 안전하게 해제합니다. (메모리 누수 방지)
        delete[] arr;
        // 5. arr 포인터가 새로 만든 배열을 가리키도록 연결합니다.
        arr = new_arr;
    }

    // 💡 [Heap 미션 1] 인덱스 수학 헬퍼 함수
    int parent(int i) { return i / 2; }
    int leftChild(int i) { return i * 2; }
    int rightChild(int i) { return i * 2 + 1; }

    // 💡 [Heap 미션 2] 정렬 엔진 (데이터 끌어올리기)
    void upHeap(int idx)
    {
        // 방금 맨 끝에 들어온 데이터(arr[idx])가 부모보다 크다면?
        // 부모와 자리를 계속 바꾸면서 꼭대기를 향해 치고 올라가는 로직을 작성하십시오.
        while (idx > 1 && arr[idx] > arr[parent(idx)])
        {
            swap(arr[idx], arr[parent(idx)]);
            idx = parent(idx);
        }
    }

    void downHeap(int idx)
    {

        while (leftChild(idx) <= size)
        {
            int larger_idx = leftChild(idx);

            if (rightChild(idx) <= size && arr[rightChild(idx)] > arr[larger_idx])
            {
                larger_idx = rightChild(idx);
            }

            if (arr[idx] < arr[larger_idx])
            {
                swap(arr[idx], arr[larger_idx]);
                idx = larger_idx;
            }
            else
            {
                break;
            }
        }
    }

public:
    // 💡 [Vector 복습 미션 2] 초기화
    MaxHeap(int cap = 10)
    {
        capacity = cap;
        size = 0;
        // 0번 인덱스는 계산을 편하게 하기 위해 버립니다.
        // capacity + 1 만큼 동적 할당해 보십시오.
        arr = new int[capacity + 1];
    }

    // 💡 [Vector 복습 미션 3] 소멸자
    ~MaxHeap()
    {
        // 동적 할당한 arr 메모리를 해제하십시오.
        delete[] arr;
    }

    // 💡 [종합 미션] 데이터 삽입
    void push(int value)
    {
        // 1. 만약 size가 capacity와 같다면? resize()를 호출해 방을 늘립니다.
        if (size == capacity)
            resize();
        // 2. size를 1 증가시키고, 배열의 맨 끝(arr[size])에 value를 집어넣습니다.
        size++;
        arr[size] = value;
        // 3. upHeap(size)를 호출해서 방금 넣은 놈을 위로 올려보냅니다.
        upHeap(size);
    }

    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    int top()
    {
        return arr[1];
    }

    int pop()
    {
        if (size == 0)
            return 0;

        int max_val = arr[1];

        arr[1] = arr[size];
        size--;
        downHeap(1);

        return max_val;
    }
};

int main()
{
    // 1. 방 2개짜리 초미니 힙 생성 (resize 테스트용)
    MaxHeap heap(2);

    cout << "🔥 [1단계] 데이터 삽입 (Push & Up-Heap & Resize 테스트)\n";
    cout << "삽입 순서: 15 -> 40 -> 20 -> 50 -> 10 -> 30\n";

    heap.push(15);
    heap.push(40);
    heap.push(20); // 💡 여기서 방이 꽉 차서 resize()가 터집니다!
    heap.push(50);
    heap.push(10);
    heap.push(30);

    cout << "삽입 완료! 메모리 에러 없이 정상 가동되었습니다.\n\n";

    // 2. 현재 꼭대기(1등) 확인 테스트
    cout << "🔥 [2단계] 현재 1등 확인 (Top 테스트)\n";
    cout << "예상 출력: 50\n";
    cout << "실제 출력: " << heap.top() << "\n\n";

    // 3. 우선순위대로 뽑아내기 (Down-Heap 및 정렬 테스트)
    cout << "🔥 [3단계] 데이터 추출 (Pop & Down-Heap 테스트)\n";
    cout << "로봇 시스템이 가장 급한(값이 큰) 작업부터 순서대로 처리합니다.\n";
    cout << "예상 출력: 50 40 30 20 15 10 (내림차순)\n";
    cout << "실제 출력: ";

    // 힙이 텅 빌 때까지 계속 1등을 뽑아냅니다.
    while (!heap.empty())
    {
        cout << heap.pop() << " ";
    }
    cout << "\n\n";

    cout << "✅ 힙(Heap) 시스템 테스트 완벽 종료!\n";

    return 0;
}
