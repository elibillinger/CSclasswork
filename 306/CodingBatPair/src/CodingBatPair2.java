//Authors: Alek Engstrom and Eli Billinger

//Array-3 > fix34 Exercise
public int[] fix34(int[] nums) {
	int[] ans = new int[nums.length];
	int hold = 0;
	for(int i = 0; i < nums.length; i++){
		if (nums[i] == 3){
			hold = nums[i+1];
			nums[i+1] = 10;
		}
		if (nums[i] == 4){
			nums[i] = hold;
		}
	}

	for(int i = 0; i < nums.length; i++){
		if (nums[i] == 4){
			nums[i] = 1;
		}
	}
	for(int i = 0; i < nums.length; i++){
		if (nums[i] == 10){
			nums[i] = 4;
		}
	}

	return nums;
}
/*
 * Expected This Run
 * fix34([1, 3, 1, 4]) -> [1, 3, 4, 1]	OK	
 * fix34([1, 3, 1, 4, 4, 3, 1])-> [1, 3, 4, 1, 1, 3, 4]	OK	
 * fix34([3, 2, 2, 4]) -> [3, 4, 2, 2]	OK	
 */

//Logic-2 > evenlySpaced Exercise
public boolean evenlySpaced(int a, int b, int c) {
	if((Math.abs(a-b) == Math.abs(b-c) ||Math.abs(a-b) == Math.abs(a-c) || Math.abs(a-c) == Math.abs(b-c)) && c != b && a != b)
		return true;
	if(Math.abs(a-b) == 0 && Math.abs(b-c) == 0 && Math.abs(a-c) == 0)
		return true;
	return false;
}
/*
 * Expected This Run
 * evenlySpaced(2, 4, 6) → true	OK	
 * evenlySpaced(4, 6, 2) → true	OK	
 * evenlySpaced(4, 6, 3) → false OK
 */

//Array-3 > countClumps Exercise
public int countClumps(int[] nums) {
	int count = 0;
	boolean matching = false;
	for(int i = 0; i<nums.length-1;i++){
		if(nums[i] == nums[i+1] && matching == false){
			count++;
			matching = true;
		} else if(nums[i] != nums[i+1]) {
			matching = false;
		}
	}
	return count;
}
/*
 *Expected This Run
 *countClumps([1,2,2,3,4,4]) 2 OK
 *countClumps([1,2,3]) 0 OK
 *countClumps([1,1,1,1,1]) 1 OK
 */

// String-2 > plusOut Exercise

public String plusOut(String str, String word) {
	int wordSize = word.length();
	int stringSize = str.length();
	String newString = "";
	for(int i = 0; i < stringSize; i++){
		if(i <= stringSize - wordSize){
			if(str.substring(i,i+wordSize).equals(word)){
				newString = newString + word;
				i = i+ wordSize-1;
			} else {
				newString = newString + "+";
			}
		} else {
			newString = newString + "+";
		}
	}
	return newString;
}
/*
 *Expected This Run
 *plusOut("12xy34","xy") "++xy++" OK
 *plusOut("12xy34xyabcxy","xy") "++xy++xy+++xy" OK
 *plusOut("aaxxxxbb", "xx") "++xxxx++" OK
 */
