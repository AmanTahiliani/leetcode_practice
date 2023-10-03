// Problem
// Given an array of functions [f1, f2, f3, ..., fn], return a new function fn that is the function composition of the array of functions.

// The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).

// The function composition of an empty list of functions is the identity function f(x) = x.

// You may assume each function in the array accepts one integer as input and returns one integer as output.


// Intuition
// I had just learned about reduct and how it uses the concept of applying an accumulator and value approach. I found this to be a similar problem, only the accumulator was to be in reverse order of the array.

// Approach
// The reduce function takes an array, a function and an initial value as an input and applies the function for each value of the array along with the output of the last element's process as the input of the current one.

// Think of this as a summation function where we try to find the sum of all the element of an array. We take an accumulator CurrentSum and on each element of the array, we apply CurrentSum += element with the value of CurrentSum being carried over into the next element.

// This is solved for by the reduce function, which does the same thing, but allows us the functionality of being able to define how we want to use the value carried over from the last operation alongside the current element

// Complexity
// Time complexity:
// As we are only looping over the elements once, the time complexity is O(N)O(N)O(N)

// Space complexity:
// O(N)O(N)O(N) because we are copying over the array (in reverse) into another array.


//Solution

/**
 * @param {Function[]} functions
 * @return {Function}
 */


let compose = function(functions) {
    revFunctions = functions.reverse();
	return function(x) {
        return revFunctions.reduce((accumulator, val) => val(accumulator), x) 
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */