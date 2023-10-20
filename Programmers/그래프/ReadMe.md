# 가장 먼 노드 (그래프)
* C++을 이용하여 풀이했습니다.

[가장 먼 노드(Level 3)](https://school.programmers.co.kr/learn/courses/30/lessons/49189)  <br/>

![image](https://github.com/seungdo1234/CodingTestPractice/assets/86179438/8c670741-c028-4dd3-a04b-d252b03e739b)

처음 이 문제를 봤을 때 그래프를 먼저 만들고 문제를 풀어야겠다 생각했는데 <br/>
n(노드)의 갯수가 2 <= 20000이라 인접 배열 말고 리스트를 생각해 인접 리스트를 만들었습니다. <br/>
그리고 BFS를 이용하여 가장 먼 노드를 구할려고 했지만 거리를 구하는 로직에서 막혔습니다. <br/>
처음 제가 생각했던 로직은 while문 마지막에 Degree를 계속 증가시켜 Count를 세는 방법으로 했습니다. <br/>
```c++
 // 1번에서 시작하기 때문에 1번 방문
 visited[1] = true;
 queue.push(1);
 int degree = 0;
 while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                count[graph[node][i]] = degree;
                // 해당 노드 방문 표시
                visited[graph[node][i]] = true;
                // Push
                queue.push(graph[node][i]);
            }
        }
        degree++;
    }
```

이렇게 구현했더니 1번노드와 해당 노드 사이에 가장 긴 거리를 반환했습니다. <br/>
고민을 하다 답이 안나와 인터넷 풀이를 봤더니 해당 코드에서 한 줄만 추가하면 됐습니다. <br/>
```c++
 // 1번에서 시작하기 때문에 1번 방문
    visited[1] = true;
    queue.push(1);
    // bfs
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                // 1번 노드와의 거리 구함
                int distance = count[node] + 1;
                count[graph[node][i]] = distance;
                // 해당 노드 방문 표시
                visited[graph[node][i]] = true;
                // Push
                queue.push(graph[node][i]);
            }
        }
    }
```
이렇게 코드를 수정한 후 통과했습니다 ! <br/>
![image](https://github.com/seungdo1234/CodingTestPractice/assets/86179438/78a004f3-f8b1-497b-8597-d6dc373e7563)

<br/>
[참고 블로그](https://0xd00d00.github.io/2021/07/10/programmers_distance.html)  <br/>

