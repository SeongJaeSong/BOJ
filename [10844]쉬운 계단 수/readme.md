https://sihyungyou.github.io/baekjoon-10844/

```
(x + y)%mod == (x % mod + y % mod) % mod
덧셈, 곱셈에서 성립
```


```
2차원 배열은 arr[10][10] = {1,} 등으로 초기화가 안된다.
```

``` cpp
for (int i = 1; i < n; i++) {
	sum = 0;
	for (int j = 0; j < 10; j++) {
		if (j == 0) {
			dp[i%2][j] = (dp[(i+1)%2][j + 1])%MOD;
		}
		else if (j == 9) {
			dp[i%2][j] = (dp[(i+1)%2][j - 1])%MOD;
		}
		else {
			dp[i%2][j] = (dp[(i+1)%2][j - 1] + dp[(i+1)%2][j + 1])%MOD;
		}
		sum += dp[i % 2][j];
	}
}

dp[(i+1)%2][j - 1] + dp[(i+1)%2][j + 1] 이 부분이 long long의 범위를 넘어갈 수 있다는 생각을 못했었음
```
