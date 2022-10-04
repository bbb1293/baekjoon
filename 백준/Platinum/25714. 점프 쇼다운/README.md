# [Platinum V] 점프 쇼다운 - 25714 

[문제 링크](https://www.acmicpc.net/problem/25714) 

### 성능 요약

메모리: 2724 KB, 시간: 48 ms

### 분류

조합론(combinatorics), 수학(math)

### 문제 설명

<p><em>문제의 모티브는 비디오 게임 <strong>폴 가이즈(Fall Guys)</strong>의 미니게임 점프 쇼다운이지만, 후술할 게임 시스템과는 관계가 없으므로 지문을 읽어야 합니다.</em></p>

<p style="text-align: center;"><img alt="" src="" style="height: 385px; width: 400px;"><br>
[그림 1]</p>

<p>점프 쇼다운이란 [그림 1]과 같이 중앙이 뚫린 원형 게임장에서 즐기는 게임이다. 1번부터 <em>N</em>번까지의 <em>N</em>개의 <strong>판</strong>이 맞물려 하나의 게임장을 이룬다. 게임이 시작된 직후엔 <em>N</em>개의 판이 모두 존재하지만, 시간이 지남에 따라 판들이 순차적으로 사라진다. 마지막에는 정확히 <strong>3개</strong>의 판이 남고, 이 셋은 게임이 종료될 때까지 절대 사라지지 않는다.</p>

<p>모든 판은 서로 구분할 수 있다. 즉, 1번 판이 사라진 것과 2번 판이 사라진 것은 다른 경우이다. 각 판은 시계 방향 및 반시계 방향으로 가장 가까운 두 판과 인접하며, 인접한 판이 사라져도 그 다음으로 가까운 판과 인접하다고 하지 않는다. [그림 1]을 예로 들면 1번 판과 인접한 두 판은 2번 판과 8번 판이다.</p>

<p>플레이어는 사라지지 않은 판을 밟고 가만히 서 있거나, 밟고 있는 판과 인접한 판으로 걸어서 이동할 수 있다. 만약 인접한 판이 사라졌다면 그곳으로는 이동할 수 없고, 사라지는 판 위에 가만히 서 있는다면 게임에서 탈락한다.</p>

<p style="text-align: center;"><img alt="" src=""><br>
[그림 2]</p>

<p>[그림 2]와 같은 상황을 예로 들면,</p>

<ul>
	<li>1 → 2의 순서로 판이 사라지면 1이나 2에 서 있던 플레이어는 3으로 이동할 수 있다.</li>
	<li>2 → 1의 순서로 판이 사라지면 1에 가만히 서 있던 플레이어는 반드시 탈락할 수 밖에 없다.</li>
</ul>

<p>불가항력으로 게임에서 탈락하게 된 플레이어는 화가 나 게임을 그만둘 수 있다. 게임 제작자는 사람들이 게임을 계속 플레이하길 바라기 때문에, 이렇게 탈락하는 경우가 발생하지 않게 하려고 한다. 판이 떨어지는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c21"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cF7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c21"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi><mo stretchy="false">(</mo><mi>N</mi><mo>,</mo><mi>N</mi><mo>−</mo><mn>3</mn><mo stretchy="false">)</mo><mo>=</mo><mi>N</mi><mo>!</mo><mo>÷</mo><mn>3</mn><mo>!</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P(N, N-3) = N!\div 3!$</span></mjx-container>가지 경우의 수 중, 플레이어가 어떻게 이동해도 불가항력으로 탈락하지 않는 것은 몇 가지인지 알아보자.</p>

### 입력 

 <p>게임이 시작된 직후의 발판의 개수 <em>N</em>이 주어진다.</p>

### 출력 

 <p>문제의 정답을 10<sup>9</sup> + 7로 나눈 나머지를 출력한다.</p>

