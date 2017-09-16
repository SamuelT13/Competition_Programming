//Longest Common Subsequence
cin >> S >> T;

int n = S.length(), m = T.length();
vector<vector<int> > memo(n+1, vector<int>(m+1, 0));

for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		if (S[i-1] == T[j-1]) memo[i][j] = memo[i-1][j-1] + 1;
		else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		
//Longest Increasing Subsequence
vector<int> nums(N, 0), LIS(N, 0);
for (int i = 0; i < N; i++) cin >> nums[i];

for (int i = 0; i < N; i++){
	for (int j = 0; j < i; j++)
		if (nums[j] < nums[i]) LIS[i] = max(LIS[i], LIS[j]);
	LIS[i]++;
}

//String Edit Distance
cin >> S >> T;

int n = S.length(), m = T.length();
vector<vector<int> > memo(n+1, vector<int>(m+1, 0));

for (int i = 0; i <= n; i++) memo[i][0] = i;
for (int j = 0; j <= m; j++) memo[0][j] = j;

for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		if (S[i-1] == T[j-1]) memo[i][j] = memo[i-1][j-1];
		else memo[i][j] = 1 + min(dp[i-1][j-1], 
								  min(dp[i][j-1], dp[i-1][j]));

//Set 2-Partition, Min Difference
vector<int> nums(N, 0);
vector<vector<bool> > memo;
int sum(0);
for (int i = 0; i < N; sum += nums[i], i++) cin >> nums[i];

memo.assign(N+1, vector<int>(sum+1, false));

for (int i = 0; i <= N; i++) memo[i][0] = true;

for (int i = 1; i <= N; i++)
	for (int j = 1; j <= sum; j++){
		memo[i][j] = memo[i-1][j];
		
		if (nums[i-1] <= j)
			memo[i][j] |= memo[i-1][j-nums[i]];
	}
	

int ans(1e9);

for (int j = sum/2; j >= 0; j--)
	if (dp[N][j]){
		ans = sum - 2*j, break;
	}

//0-1 Knapsack
vector<int> weight(N, 0), value(N, 0);
vector<vector<int> > memo(N+1, vector<int>(W+1, 0));

for (int i = 0; i < N; i++) cin >> weight[i];
for (int i = 0; i < N; i++) cin >> value[i];


for (int i = 1; i <= N; i++)
	for (int j = 0; j <= W; j++){
		memo[i][j] = memo[i][j-1];
		
		if (j >= weight[i])
			memo[i][j] = max(memo[i][j],
							 memo[i-1][j-weight[i]] + value[i]);
	}

//Assembly Line
vector<int> time_1(N, 0), time_2(N, 0), entry(2, 0), exit(2, 0);
vector<vector<int> > trav(2, vector<int>(N, 0)), change(2, vector<int>(N, 0));

time_1[0] = entry[0] + trav[0][0];
time_2[0] = entry[1] + trav[1][0];

for (int i = 1; i < N; i++){
	time_1[i] = min(time_1[i-1]+trav[0][i], time_2[i-1]+change[1][i]+trav[0][i]);
	time_2[i] = min(time_2[i-1]+trav[1][i], time_1[i-1]+change[0][i]+trav[1][i]);
}

min(time_1[N-1] + exit[0], time_2[N-1] + exit[1]);

//Min Cost Binary Tree
vector<int> freq(N, 0), keys(N, 0);
vector<vector<int> > cost(N, vector<int>(N, 0)); //cost for tree from keys [i, j]

for (int i = 0; i < N; i++) cin >> keys[i] >> freq[i];

for (int i = 0; i < N; i++) cost[i][i] = freq[i];

for (int L = 2; L <= N; L++)
	for (int i = 0; i <= N-L+1; i++){
		int j = i+L-1;
		cost[i][j] = 1e9;
		
		//try making key[r] the root
		for (int r = i; r <= j; r++){
			int c = ((r > i)? cost[i][r-1]:0) + 
					((r > j)? cost[r+1][j]:0) +
					sum(freq, i, j);
		
			cost[i][j] = min(cost[i][j], c);
		}
	}
	
cout << cost[0][N-1];

//Matrix Chain Multiplication
cost(i, j) = 0, if i = j
cost(i, j) = min(cost(i, k)) + cost(k+1, j) + P_(i-1) + P(k) + P(j)), for i <= k <= j-1

ans: cost(1, n)
