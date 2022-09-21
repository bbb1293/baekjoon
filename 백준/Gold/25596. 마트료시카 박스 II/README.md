# [Gold IV] 마트료시카 박스 II - 25596 

[문제 링크](https://www.acmicpc.net/problem/25596) 

### 성능 요약

메모리: 3368 KB, 시간: 0 ms

### 분류

그리디 알고리즘(greedy), 트리(trees)

### 문제 설명

<p><u><strong>마트료시카 박스 I, 마트료시카 박스 III 문제와 '상자 포함 관계가 유지되었다' 정의가 다르다.</strong></u></p>

<p>ChAOS 회사는 마트료시카 박스를 만들기로 유명한 회사이다. 마트료시카 박스 안에는 마트료시카 박스를 넣을 수 있다. 따라서 마트료시카 박스는 박스가 여러 중첩으로 들어있는 박스를 의미한다.</p>

<p>푸앙이는 ChAOS 회사에 마트료시카 박스 주문 제작 신청을 하려고 한다. 주문 제작 신청을 하기 위해서는 중복되는 박스 번호 없이 마트료시카 박스 설계도를 만들어 신청해야 한다. 설계도에서 박스 번호는 모두 자연수이며, 메인 박스는 단 $1$개만 존재한다. 메인 박스란 어떠한 박스에 담기지 않은 박스를 의미한다. 푸앙이는 $N$개의 박스로 구성된 설계도를 만들게 된다.</p>

<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<td style="text-align: center;"><strong>마트료시카 박스 번호</strong></td>
			<td style="text-align: center;"><strong>서브 박스 번호</strong></td>
		</tr>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2, 3</td>
		</tr>
		<tr>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">4</td>
		</tr>
		<tr>
			<td style="text-align: center;">3</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">-</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 1> </p>

<p style="text-align: center;"><img alt="" src="" style="height: 158px; width: 500px;"></p>

<p style="text-align: center;"><그림 1></p>

<p><표 1>은 푸앙이가 작성한 마트료시카 박스 설계도 예시이고, <그림 1>은 <표 1>의 설계도를 바탕으로 제작된 박스 모습이다. <그림 1>의 모든 박스는 열려있다.</p>

<p>서브 박스는 박스를 열었을 때 그 박스 안에 있는 박스 중 열지 않고 볼 수 있는 박스들을 의미한다.</p>

<p>그러나 푸앙이는 ChAOS 회사에서 제작 공정상 설계도 수정이 필요하다고 전달받았다. 제작 공정상 박스마다 서브 박스를 최대 $M$개 밖에 못 넣는다는 내용이었다. 좌절한 푸앙이는 당신에게 도움을 요청하였다.</p>

<p>설계도를 수정하는 과정에서 기존 박스의 위치를 옮기거나, 새로운 박스를 추가할 수 있다. 새로운 박스는 푸앙이의 자금 문제로 최대 $K$개까지만 추가할 수 있다. 추가하려는 박스의 번호는 기존에 존재하는 박스 번호와 겹치면 안 된다. 박스의 위치를 옮기는 데는 제약은 없으나, 푸앙이의 부탁으로 수정 후의 설계도는 수정 전의 설계도와 박스 포함 관계가 반드시 유지되어야 한다.</p>

<p>$(i,\,j)$쌍은 $i$번 박스가 $j$번 박스를 담고 있음을 의미한다. 수정 전 설계도에서 만족하는 모든 $(i,\,j)$쌍을 원소로 가지는 집합을 $A$, 수정 후 설계도에서 만족하는 모든 $(i,\,j)$쌍을 원소로 가지는 집합을 $B$, 집합 $B$ 원소 중 $i > N$혹은 $j > N$을 만족하는 모든 $(i,\,j)$쌍을 원소로 가지는 집합을 $C$라 하자. 이때 $A \cup C = B$를 만족한다면 박스 포함 관계가 유지되었다고 말한다.</p>

<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<td style="text-align: center;"><strong>마트료시카 박스 번호</strong></td>
			<td style="text-align: center;"><strong>서브 박스 번호</strong></td>
		</tr>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">2, 3, 4, 5</td>
		</tr>
		<tr>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">3</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">5</td>
			<td style="text-align: center;">-</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 2></p>

<p style="text-align: center;"><img alt="" src="" style="height: 119px; width: 500px;"></p>

<p style="text-align: center;"><그림 2></p>

<p><표 2>는 $N = 5,\, M = 2,\, K = 2$ 일 때 수정 전 설계도이고, <그림 2>는 <표 2>의 설계도를 바탕으로 제작된 박스 모습이다. <그림 2>의 박스는 모두 열려있다.</p>

<p>당신은 <표 2>의 설계도에서 6, 7번 박스를 새로 추가하여 모든 박스의 서브 박스가 2개 이하가 되도록 설계도를 수정할 수 있다.</p>

<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<td style="text-align: center;"><strong>마트료시카 박스 번호</strong></td>
			<td style="text-align: center;"><strong>서브 박스 번호</strong></td>
		</tr>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">6, 7</td>
		</tr>
		<tr>
			<td style="text-align: center;">2</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">3</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">4</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">5</td>
			<td style="text-align: center;">-</td>
		</tr>
		<tr>
			<td style="text-align: center;">6</td>
			<td style="text-align: center;">3, 4</td>
		</tr>
		<tr>
			<td style="text-align: center;">7</td>
			<td style="text-align: center;">2, 5</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 3></p>

<p style="text-align: center;"><img alt="" src="" style="height: 157px; width: 500px;"></p>

<p style="text-align: center;"><그림 3></p>

<p><표 3>은 <표 2>의 수정 후 설계도이고, <그림 3>은 <표 3>의 설계도를 바탕으로 제작된 박스 모습이다. <그림 3>의 박스는 모두 열려있다.</p>

<p>수정 전 $A = \{(1,2),(1,3),(1,4),(1,5)\}$이고 수정 후 $B = \{(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(6,3),(6,4),(7,2),(7,5)\}$, $C = \{(1,6),(1,7),(6,3),(6,4),(7,2),(7,5)\}$이다. 따라서 $A \cup C = B$이므로 상자 포함 관계가 유지되었다.</p>

<p>당신은 박스 $N$개로 구성된 설계도를 받았을 때, 새로운 박스를 최대 $K$개 추가하여 서브 박스가 $M$개 이하로 된 설계도로 수정할 수 있는지 없는지 알아내고, 있으면 그중 아무거나 하나를 출력하는 프로그램을 작성해야 한다.</p>

### 입력 

 <p>첫 번째 줄에 수정 전 설계도의 박스의 개수 $N$, 수정 후 설계도의 최대 서브 박스 개수 $M$, 추가할 수 있는 박스의 개수 $K$가 공백으로 구분되어 주어진다. $(4 \leq N \leq 1\,000;$ $2 \leq M \leq N - 2;$ $0 \leq K \leq 1\,000)$</p>

<p>두 번째 줄부터 $N$개의 줄에 걸쳐 수정 전 설계도가 주어진다. $i$번째 줄에는 $C$와 $i - 1$번 박스에 담긴 서브 박스 번호 $C$개가 공백으로 구분되어 주어진다. $(2 \leq i \leq N + 1)$</p>

<p>수정 전 설계도에서 주어지는 박스 번호는 모두 $N$보다 작거나 같은 자연수이다. 수정 전 설계도는 서브 박스 개수가 $M$개 보다 많은 박스가 항상 존재한다.</p>

### 출력 

 <p>조건에 맞게 설계도를 수정할 수 없다면 $0$을 출력한다.</p>

<p>조건에 맞게 설계도를 수정할 수 있다면 $1$을 출력하고, 다음 줄에는 수정 후 설계도에서 새로 추가한 서브 박스 개수 $S$를 출력한다. 세 번째 줄부터 $N + S$개의 줄에 걸쳐 수정 후 설계도를 출력한다.</p>

<p>$i$번째 줄에는 $C$와 $i - 2$번 박스에 담긴 서브 박스 번호 $C$개를 출력한다. $(3 \leq i \leq N + S + 2)$</p>

<p>출력하는 박스 번호는 모두 $N + S$보다 작거나 같은 자연수이어야 한다.</p>

