// how would i do this if i knew the array?
// grab maximum of array with max(a_i) f(1, n) / n
// we can binary search for max(a_i)
// 		if ? l, r != max(a_i) * (r - l + 1), we know to search in the second half
//      if ? l, r == max(a_i) * (r - l + 1), then we can continue to divide this segment
// this way we can find the max value.
	// log2(n) comparisons

// therefore m must be a multiple of max(a_i)
// segment cannot be longer than n / k in length
// 

