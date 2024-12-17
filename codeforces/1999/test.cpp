/*
function returns a double
fun_factor >= 0

double max_fun(Employee* ceo)

employee direct subordinates cannot appear!

dp[i][j] = max fun of subtree under employee i
           if j = 0, then employee i is not there
           otherwise employee i is there

dp[i][0] = sum(max(dp[k][0], dp[k][1])) for all subordinates k of i
dp[i][1] = fun_factor[i] + sum(dp[k][0]) for all subordinates k of i

max(dp[ceo_index][0], dp[ceo_index][1])

*/

struct Employee {
	double fun_factor;
	vector<Employee*> subs;	
};

// {not there, there}
pair<double, double> helper(Employee* node) {
	// if (node->subs.size() == 0) { // leaf node
	// 	return {0.0, node->fun_factor};
	// }
	double funIfThere = 0;
	double funIfNotThere = 0;
	for (const Employee* sub : node->subs) {
		pair<double, double> sub_values = helper(sub);
		funIfNotThere += max(sub_values.first, sub_values.second);
		funIfThere += sub_values.first;
	}
	funIfThere += node->fun_factor;
	return {funIfNotThere, funIfThere};
}

double max_fun(Employee* ceo) {
	pair<double, double> res = helper(ceo);
	return max(res.first, res.second);
}