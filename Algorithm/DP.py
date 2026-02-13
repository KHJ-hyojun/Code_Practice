# 다이나믹 프로그래밍 DP(Dynamic Programming)

"""
1. 다이나믹 프로그래밍 (동적 계획법) 이란?
- 특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 
효율적으로 값을 구하는 알고리즘

하나의 큰 문제를 여러 개의 작은 문제로 나누어 그 결과를 저장하여 
다시 큰 문제를 해결할 때 사용


2. 왜 DP를 쓰는 것일까?
일반적인 재귀와 유사
BUT 차이점 : 
일반적인 재귀를 단순히 사용할 때 작은 문제 하나에서 작은 문제가 있다면
이를 계속 반복하여야 하기 때문에 규모가 큰 계산에서 굉장히 비효율적이게 될 수 있다.


3. 분할 정복과의 차이점
공통점 :
주어진 문제를 작은 문제로 작게 쪼개서 서브 문제들을 해결하고 
이를 토대로 큰 문제를 해결한다는 점

차이점 :
분할정복 - 분할된 하위 문제가 동일하게 중복이 일어나지 않는 경우
DP - 분할된 하위 문제가 동일하게 중복이 일어나는 경우


4. DP의 사용 조건
I) Overlapping Subproblems(겹치는 부분 문제)
II) Optimal Substructure(최적 부분 구조)

I) Overlapping Subproblems
 DP는 기본적으로 문제를 나누고 그 문제의 결과 값을 재활용해서 전체 답을 구한다.
그래서 동일한 작은 문제들이 반복해서 나타나는 경우에 사용가능

즉, DP는 부분 문제의 결과를 저장해서 다시 계산하지 않을 수 있어야 하는데,
 해당 부분 문제(subproblems)가 반복적으로 나타나지 않는다면 재사용이 불가능하니
부분 문제가 중복되지 않는 경우에는 사용불가

II) Optimal Substructure(최적 부분 구조)
 부분 문제(subproblems)의 최적 결과 값을 사용해 전체 문제의 최적 결과를 낼 수 있는 경우
그래서 특정 문제의 정답은 문제의 크기와는 상관없이 항상 동일


5. DP 사용 과정
I) DP로 풀 수 있는 문제인지 확인
문제가 작은 문제들로 쪼개질 수 있는지, 즉 하나의 함수로 표현될 수 있는 지 판단

II) 문제의 변수 파악
문제 내에서 변수의 개수를 알아내야 한다.

III) 변수 간 관계식 만들기
점화식을 통해 짧은 코드 내에서 반복/재귀를 통해 문제가 자동으로 해결되도록 구축할 수 있게 된다.

IV) 메모하기 - Memoization
변수 간 관계식까지 정상적으로 생성되었다면 변수의 값에 따른 결과를 저장해야 한다.

V)기저 상태 파악하기
가장 작은 문제의 상태를 파악한 후 미리 배열 등에 저장해둔다.
EX) 피보나치 수열에서의 f(0) = 0, f(1) = 1

VI)구현하기
- Bottom-Up (Tabulation 방식) : 반복문 방식
아래에서부터 위로 계산을 수행하면서 이를 통해 누적된 것으로 전체 큰 문제를 해결해 나가는 방법
dp[0]부터 시작해서 반복문을 통해 점화식으로 결과를 도출하여 dp[n]까지 그 값을 이동시켜 재활용하는 방식

- Top-Down (Memoization 방식) : 재귀 사용
dp[n]을 찾아내기 위해서 위에서부터 바로 호출 진행


"""

### DP 구현 - python
# Top-Down with memoization 코드
def fibonacci_td(n):
    if n < 2:
        return n
    if _memo[n] is None:
        _memo[n] = fibonacci_td(n-1) + fibonacci_td(n-2)

    return _memo[n]

_memo = [None] * 50
print(fibonacci_td(36))

# Bottom-Up with memoization 코드

def fibonacci_bu(n):
    memo = [0,1]

    for i in range(2, n+1):
        memo.append(memo[i-1] + memo[i-2])

    return memo[-1]

print(fibonacci_bu(36))

"""
top-down방식은 위에서부터 시작하기 때문에 재귀로,
bottom-up방식은 아래에서부터 시작하기 때문에 for 반복문으로 구성

"""