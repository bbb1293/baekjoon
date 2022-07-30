# [Gold II] 카드 뒤집기 게임 - 22026 

[문제 링크](https://www.acmicpc.net/problem/22026) 

### 성능 요약

메모리: 4168 KB, 시간: 8 ms

### 분류

애드 혹(ad_hoc)

### 문제 설명

<p>카드 뒤집기 게임은 혼자서 하는 카드 게임으로, 두 가지 타입의 카드 A, B를 사용한다. 카드 A에는 게임에 적용될 규칙에 관한 정보가 적혀 있다. 구체적으로, <strong>그림 1</strong>과 같이 두 정수 $N$ 과 $M(\le N)$, 그리고 $N \times N$ 격자 형태로 문자 'O'와 'X'가 배치된 패턴 $P$가 적혀 있다. </p>

<p style="text-align: center;"><img alt="" src="" style="width: 98px; height: 133px;"></p>

<p style="text-align: center;"><strong>그림 1</strong></p>

<p>카드 B는 앞면에 문자 'O', 뒷면에 문자 'X'가 적힌 카드다. 카드 B 한 장은 카드 A에 적힌 패턴의 문자 하나를 나타내기 위해 사용될 것인데, 이를 위해 충분히 많은 양의 카드 B가 준비되어 있다.</p>

<p>게임을 시작해보자. 먼저, 카드 A를 하나 선택하고, 그 카드에 적힌 $N$ 값에 따라 $N \times N$ 격자 형태로 카드 B를 배치한다. 처음 배치되는 카드는 모두 'X'가 보이도록 배치해야 한다. 배치된 각 카드는 <strong>그림 2</strong>처럼 행과 열의 번호로 구분한다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 254px; height: 209px;"></p>

<p style="text-align: center;"><strong>그림 2</strong></p>

<p>카드의 초기 배치가 끝나면, 플레이어는 아래에 설명하는 <strong>'뒤집기'</strong>를 필요에 따라 반복한다. 한 번의 '뒤집기'는 두 단계로 구성된다. </p>

<ul>
	<li> 단계 1: 카드가 놓인 $N \times N$  격자에서 임의의 한 행 또는 한 열을 선택한다. 또한, 카드 A에 적힌 정수 $M$에 따라 임의의 정수 $k(0 \le k < M)$를 선택한다.</li>
	<li>단계 2: 단계 1에서 선택한 것이 행 $i$ 라면, $j \equiv k \pmod{M} $인 모든 $j$ 에 대해, 격자 상에서 $(i,j)$ 위치에 있는 모든 카드를 뒤집는다. 유사하게, 단계 1에서 선택한 것이 열 $j$ 라면, $i \equiv k \pmod{M}$인 모든 $i$ 에 대해, 격자 상에서 $(i,j)$ 위치에 있는 모든 카드를 뒤집는다.</li>
</ul>

<p>플레이어는 '뒤집기'를 반복해서 격자에 놓인 카드의 패턴과 카드 A에 그려진 패턴 $P$를 일치시켜야 한다. 이것이 실제로 가능한 일인지 판별해보자.</p>

### 입력 

 Empty

### 출력 

 Empty

